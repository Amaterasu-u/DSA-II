#include<bits/stdc++.h>
using namespace std;

int counts=0;

class Bill
{
    public:
    string name;
    int amount;
    int timestamp;
    Bill()
    {
        name="";
        amount=0;
        timestamp=0;
    }
    Bill(string n,int a,int t)
    {
        name=n;
        amount=a;
        timestamp=t;
    }
};

class PQ
{
    public:
    int heap_size;
    Bill bill[100];
    PQ()
    {
        heap_size = 0;
    }
    int leftChild(int i)
{

    return (2 * i);
}

int rightChild(int i)
{

    return ((2 * i) + 1);
}

    void heapInsert(Bill val)
    {
        heap_size++;
        bill[heap_size]=val;
        heapifyUp(heap_size);
    }
    void heapifyUp(int index)
    {
        if(index==1) return;
        if(bill[index].amount > bill[index/2].amount)
        {
            swap(bill[index],bill[index/2]);
            heapifyUp(index/2);
        }
    }
      int peekMax()
{
    if(heap_size== 0){
        cout<<"Empty"<<endl;
    }
    int result = bill[1].amount;
    return result;
}
    int extractMax()
{
    if(heap_size== 0){
        cout<<"Empty"<<endl;
    }
    int result = bill[1].amount;

    //bill[1].amount = bill[heap_size].amount;
    swap(bill[1],bill[heap_size]);
    heap_size = heap_size - 1;
     heapifydown(1);
    return result;
}
    void heapifydown(int i)
    {
        int maxIndex = i;

    // Left Child
    int l = leftChild(i);

    if (l <= heap_size && bill[l].amount > bill[maxIndex].amount) {
        maxIndex = l;
    }

    // Right Child
    int r = rightChild(i);

    if (r <= heap_size && bill[r].amount> bill[maxIndex].amount) {
        maxIndex = r;
    }
     if (i != maxIndex) {//incase of parent and both child are same
        swap(bill[i], bill[maxIndex]);
       heapifydown(maxIndex);
    }
    }
 void Updatebill(string n, int t) {

    if(heap_size== 0){
        cout<<"Empty"<<endl;
    }
        int j= 0;
        for (int i = 1; i <= heap_size; i++) {
            if (bill[i].name == n) {
                bill[i].amount = t;
                j= i;
                break;
            }
        }
        int par=j/2;
         int l = leftChild(j);
         int r = rightChild(j);
        if(j>1 && bill[par].amount < bill[j].amount){
            heapifyUp(j);
        }
        else if((l<=heap_size && bill[l].amount > bill[j].amount)||(r<=heap_size&& bill[r].amount >bill[j].amount)){
            heapifydown(j);
        }
    }
int findmin(){
           if(heap_size== 0){
        cout<<"Empty"<<endl;
    }
        int minimum=bill[heap_size/2 +1].amount;
        for(int i=heap_size/2+1 ; i<=heap_size;i++){
            if(minimum>bill[i].amount){
                minimum=bill[i].amount;
            }
        }
return minimum;
}
void minimum(){
           if(heap_size== 0){
        cout<<"Empty"<<endl;
    }
        int mini=bill[heap_size/2 +1].amount;
        for(int i=heap_size/2+1 ; i<=heap_size;i++){
            if(mini>bill[i].amount){
                mini=bill[i].amount;
            }
        }
swap(bill[mini],bill[heap_size]);
    heap_size = heap_size - 1;
     heapifydown(mini);
}
void maximum()
{
    if(heap_size== 0){
        cout<<"Empty"<<endl;
    }
    
    swap(bill[1],bill[heap_size]);
    heap_size = heap_size - 1;
    heapifydown(1);
  
}
void print(){
 for(int i=1;i<=heap_size;i++)
    {
        cout <<bill[i].name<< " ";
        cout << bill[i].amount << " ";
         cout <<bill[i].timestamp << " "<<endl;
    }


}
void deletebill(int j){
   if(heap_size== 0){
        cout<<"Empty"<<endl;
    }
    if(j<=0 || j>heap_size){
        cout<<"Invalid"<<endl;
        return;
    }
    else{
        swap(bill[j],bill[heap_size]);
        heap_size = heap_size - 1;
        int par=j/2;
         int l = leftChild(j);
         int r = rightChild(j);
        if(j>1 && bill[par].amount < bill[j].amount){
            heapifyUp(j);
        }
        else if((l<=heap_size && bill[l].amount > bill[j].amount)||(r<=heap_size&& bill[r].amount >bill[j].amount)){
            heapifydown(j);
        }
    }

}
void processbill(int modval){
int obj=0;
while(heap_size>0){
    if(obj==modval){
           minimum();
            obj=0;
           }
           else{
            maximum();
           obj++;

}
}
}
};

int main()
{
    cout<<"Press Q to Exit."<<endl;
    PQ pq;
    while(1)
    {
        counts++;
        cout<<"Enter Customer"<<counts<<endl;
         string s;
         cout<<"Name:"<<endl;
         cin >> s;
        if(s=="Q") break;
        cout<<"Amount:"<<endl;
        int amount;
        cin >> amount;

        Bill bill=Bill(s,amount,counts);
        pq.heapInsert(bill);
    }
    cout<<"Welcome!List of Functions: "<<endl;

  while (1) {
        cout << "press 1 to Delete Maximum Bill"<<endl;
        cout << "press 2 to peek Maximum Bill"<<endl;
        cout << "press 3 to Update Bill"<<endl;
        cout << "press 4 to print Bill"<<endl;
        cout << "press 5 to view minimum Bill"<<endl;
        cout << "press 6 to Delete Bill at particular index"<<endl;
        cout << "press 7 to process Bill"<<endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
if (choice == 1) {
         cout<<endl << "Node with maximum priority : "<< pq.extractMax()<< "\n";
        }
         else if (choice == 2) {
          cout<<endl << "peek maximum priority : "<< pq.peekMax()<< "\n";
        }
        else if (choice == 3) {
          cout<<endl<<"enter name to update bill: "<<endl;
string n;
cin>>n;
cout<<"enter amount to update : "<<endl;
int t;
cin>>t;
pq.Updatebill(n,t);
cout<<"Updated bill: "<<endl;
  pq.print();

        }
         else if (choice == 4) {
            pq.print();
        }
         else if (choice == 5) {
          cout<<endl << "Node with minimum priority : "<< pq.findmin()<<endl;
        }
            else if (choice == 6) {
    cout<<"enter index to delete at : "<<endl;
int j;
cin>>j;
pq.deletebill(j);
cout<<"Bill after deletion: "<<endl;
  pq.print();

        }

         else if (choice == 7) {
                int id;
                cout<<"enter your ID:";
         cin>>id;
         cout<<"processed bills are: "<<endl;
         int modval=id%9;
         pq.processbill(modval);
         pq.print();
        }

         else {
            cout << "Invalid Choice!" << endl;
            break;
        }
    }


    return 0;
}