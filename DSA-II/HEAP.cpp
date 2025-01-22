#include <iostream>
#include <cstring>
using namespace std;

#define MAX_SIZE 100

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
    Bill heap[MAX_SIZE]; // Array for the max-heap
    int size_;            // Current number of elements in the heap

    // Utility function to swap two bills
    void swap_(Bill& a, Bill& b) {
        Bill temp = a;
        a = b;
        b = temp;
    }

    // Heapify up to maintain max-heap property
    void heapifyUp(int i) {
        while (i > 1) {
            int par = i / 2;
            if (heap[par].amount < heap[i].amount) {
                swap_(heap[par], heap[i]);
                i = par;//Perholate up korar por jokhon child uthay parent er jaygate 
                // anbo ,, tokhon abar parent er position theke ABAR percholaUP korte
                // hobe. Tai Parent er index ta ekhon child er index which was i er
                // moddhe initialise korlam
            } 
            else {// without this else condition , PRINT HOCCHE NA 
                break; // No need to continue if heap property is restored
            }
        }
    }

    // Heapify down to maintain max-heap property
    void heapifyDown(int i) {
        int largest;
        int L = 2 * i;
        int R = 2 * i + 1;

        if (L <= size_ && heap[L].amount > heap[largest].amount) {
            largest = L;
        }
        else{
             largest = i;
        }
        if (R <= size_ && heap[R].amount > heap[largest].amount) {
            largest = R;
        }

        if (largest != i) {
            swap_(heap[i], heap[largest]);
            heapifyDown(largest); // Recursively heapify down
        }
    }

public:

    PriorityQueue() {
        size_ = 0;
    }


    void addBill(string name, int amount, int timestamp) {
        if (size_ >= MAX_SIZE - 1) {
            return; // Avoid overflow
        }
        size_++;
        heap[size_] = Bill(name, amount, timestamp);
        heapifyUp(size_); // Ensure heap property is maintained after insertion
    }


    void ExtractMax() {
        while(size_>0){
        if (size_ == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout <<heap[1].amount<<endl;

   
        swap_(heap[1], heap[size_]);
        size_--;
        heapifyDown(1); 
    }
    }


    void printHeap() {
        for (int i = 1; i <= size_; i++) {
            cout << "Bill Name: " << heap[i].name
                 << ", Amount: " << heap[i].amount
                 << ", Timestamp: " << heap[i].timestamp << endl;
        }
    }
};

int main() {
    PriorityQueue pq;


    int timestamp = 0;


    pq.addBill("Alice", 200, timestamp++);
    pq.addBill("Bob", 100, timestamp++);
    pq.addBill("Charlie", 300, timestamp++);
    pq.addBill("Dave", 200, timestamp++);

    pq.printHeap(); 

    pq.ExtractMax(); 
    
}
