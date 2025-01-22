#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[60];
    for(int i=0;i<60;i++){
        cin>>arr[i];
    }

    int count1=0;
    int count2=0;
    int count3=0;
    int count4=0;
    int count5=0;
    int count6=0;
    int count7=0;
    for(int i=0;i<60;i++){
        if(arr[i]>=70 && arr[i]<87) count1++;
      else  if(arr[i]>=87 && arr[i]<104) count2++;
       else if(arr[i]>=104 && arr[i]<121) count3++;
        else if(arr[i]>=121 && arr[i]<138) count4++;
       else if(arr[i]>=138 && arr[i]<155) count5++;
       else if(arr[i]>=155 && arr[i]<172) count6++;
       else if(arr[i]>=172 && arr[i]<=189) count7++;
    }

    cout<<"Freq 70-87: "<<count1<<endl;
    cout<<"Freq 87-104: "<<count2<<endl;
    cout<<"Freq 104-121: "<<count3<<endl;
    cout<<"Freq 121-138: "<<count4<<endl;
    cout<<"Freq 138-155: "<<count5<<endl;
    cout<<"Freq 155-172: "<<count6<<endl;
    cout<<"Freq 172-189: "<<count7<<endl;
}