#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100
/* 202314108
   Yeaser Ahmad
*/
class Bill {
public:
    string name;
    int amount;
    int timestamp;

    Bill() {
        this->name = "";
        this->amount = 0;
        this->timestamp = 0;
    }

    Bill(string name, int amount = 0, int timestamp = 0) {
        this->name = name;
        this->amount = amount;
        this->timestamp = timestamp;
    }
};

class PriorityQueue {
private:
    Bill heap[MAX_SIZE];
    int size_;

    void swap_(Bill& a, Bill& b) {
        Bill temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int i) {
        while (i > 1) {
            int parent = i / 2;
            if (heap[parent].amount < heap[i].amount) {
                swap_(heap[parent], heap[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int L = 2 * i;
        int R = 2 * i + 1;

        if (L <= size_ && heap[L].amount > heap[largest].amount) {
            largest = L;
        }
        if (R <= size_ && heap[R].amount > heap[largest].amount) {
            largest = R;
        }
        if (largest != i) {
            swap_(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    PriorityQueue() {
        size_ = 0;
    }

    void addBill(string name, int amount, int timestamp) { //FUNCTION 1 - Insert(Enqueue)
        if (size_ > MAX_SIZE) {
            return;
        }
        size_++;
        heap[size_] = Bill(name, amount, timestamp);
        heapifyUp(size_);
    }

    void extractMax() { // FUNCTION 2 - Remove Max(Dequeue)
        if (size_ == 0) {
            cout << "No bills to process." << endl;
            return;
        }
        cout << "Processed: " << heap[1].name << ", Amount: " << heap[1].amount << endl;
        swap_(heap[1], heap[size_]);
        size_--;
        heapifyDown(1);
    }

    void viewMax() { // FUNCTION 3 - Peek
        if (size_ == 0) {
            cout << "No Customer is available" << endl;
            return;
        }
        cout << "Next in line: " << heap[1].name << ", Amount: " << heap[1].amount << endl;
    }

    void update(string customer, int newAmount) { // FUNCTION 4 - Update
    if(size_ == 0){
        cout<<"The Restaurant is Empty"<<endl;
    }
        int node = 0;
        for (int i = 1; i <= size_; i++) {
            if (heap[i].name == customer) {
                heap[i].amount = newAmount;
                node = i;
                break;
            }
        }
        int par=node/2;
        int l=node*2;
        int r=node*2+1;
        if(heap[par].amount < heap[node].amount){
        heapifyUp(node);
        }
        else if((heap[l].amount > heap[node].amount) || (heap[r].amount > heap[node].amount)){
            heapifyDown(node);
        }

    }

void findMin(){ // FUNCTION 5 - Find Min
            if (size_ == 0) {
            cout << "No Customer is available" << endl;
            return;
        }
        int minAmount=heap[size_ /2 +1].amount;
        for(int i=size_/2+1 ; i<=size_;i++){
            if(minAmount>heap[i].amount){
                minAmount=heap[i].amount;
            }
        }
        cout<<"The minimum bill is: "<<minAmount<<endl;
}

void processMax() {
    if (size_ == 0) {
        cout<<"The Restaurant is Empty"<<endl;
        return;
    }
    int root=1;
    for (int i=2; i<=size_;i++) {
        if (heap[i].amount==heap[root].amount && heap[i].timestamp < heap[root].timestamp) {
            root=i; 
        }
    }
    cout << "Processed: " << heap[root].name << ", Amount: " << heap[root].amount <<" TimeStamp: "<< heap[root].timestamp<<endl;
    swap_(heap[root], heap[size_]);
    size_--;
    heapifyDown(root);
}


void processMin() {
    if (size_ == 0) {
        cout << "The Restaurant is Empty" << endl;
        return;
    }

    int minAmount = heap[size_ / 2 + 1].amount; //Minimum most finding
    for (int i = size_ /2+1; i<= size_;i++) {
        if (heap[i].amount < minAmount) {
            minAmount = heap[i].amount; 
        }
    }

    int minIndex = size_ /2 +1; //Comparing timeStamp for Equal minimum most
    for (int i = size_ / 2 + 1; i <= size_; i++) {
        if (heap[i].amount == minAmount && 
            heap[i].timestamp < heap[minIndex].timestamp) {
            minIndex = i; 
        }
    }
    cout<<"Processed Minimum Bill: "<<heap[minIndex].name<<", Amount: "<<heap[minIndex].amount<<", Timestamp: "<<heap[minIndex].timestamp<<endl;
    swap_(heap[minIndex], heap[size_]);
    size_--;

}




void processBill(int a){// Main Restaurant Bill Processing Function 
    int counter=0;
    while(size_ > 0){
        if(size_==0){
            cout<<"No bills to process"<<endl;
            break;
        }
        else{
           if(counter==a){
            processMin();
            counter=0;
           }
           else{
            processMax();
            counter++;
           }
        }

    }
}


void DeleteAt(int index){ // FUNCTION 6 - Delete at index i
if(size_ == 0 ){
    cout<<"The Restaurant is Empty"<<endl;
}
    if(index<=0 || index>=size_){
        cout<<"Invalid Position to delete"<<endl;
        return;
    }
    else{
        swap(heap[index] , heap[size_]);
        size_--;
        int par= index/2;
        int left=2*index;
        int right=2*index+1;
        if(index>1 && heap[par].amount < heap[index].amount){
            heapifyUp(index);
        }
        else if((left<=size_  && heap[left].amount > heap[index].amount)||(right<=size_  && heap[right].amount > heap[index].amount)){
            heapifyDown(index);
        }
    }
}


    void printHeap() {
        if (size_ == 0) {
            cout << "No bills to display." << endl;
            return;
        }
        for (int i = 1; i <= size_; i++) {
            cout << "Bill Name: " << heap[i].name
                 << ", Amount: " << heap[i].amount
                 << ", Timestamp: " << heap[i].timestamp << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int timestamp = 1;
    int myID = 202314108;
    int serviceCounter = myID % 9;

    while (1) {
        cout << "RESTAURANT MANAGEMENT: "<<endl;
        cout << "1. Add Bill"<<endl;
        cout << "2. Process or Delete Max Bill"<<endl;
        cout << "3. View Max Bill"<<endl;
        cout << "4. Update Bill"<<endl;
        cout << "5. Display All Bills"<<endl;
        cout << "6. View Minimum Bill"<<endl;
        cout << "7. Manage the orders or Process the Bills"<<endl;
        cout << "8. Remove a Bill from the restaurant"<<endl;
        cout << "9. CLOSE THE RESTAURANT"<<endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string name;
            int amount;
            cout << "Enter customer name: ";
            cin >> name;
            cout << "Enter bill amount: ";
            cin >> amount;
            pq.addBill(name, amount, timestamp++);
        }
         else if (choice == 2) {
            pq.extractMax();
        }
         else if (choice == 3) {
            pq.viewMax();
        } 
        else if (choice == 4) {
            string name;
            int newAmount;
            cout << "Enter customer name: ";
            cin >> name;
            cout << "Enter new amount: ";
            cin >> newAmount;
            pq.update(name, newAmount);
        }
         else if (choice == 5) {
            pq.printHeap();
        }
         else if (choice == 6) {
            pq.findMin();
        }
            else if (choice == 7) {
            pq.processBill(serviceCounter);
        }

         else if (choice == 8) {
            int pos;
            cout << "Enter the position of the bill you want to remove: ";
            cin>>pos;
           pq.DeleteAt(pos);
        }
        else if(choice == 9){
                 cout << "CLOSING THE RESTAURANT. THANKS FOR VISITING!" << endl;
            break;
        }
     
         else {
            cout << "Invalid Choice!" << endl;
        }
    }
}
