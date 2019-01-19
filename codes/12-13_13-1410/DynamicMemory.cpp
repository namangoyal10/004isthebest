#include<iostream>
using namespace std;

int main(){
    int *iSB=new int;
    cin>>*iSB;
    int *arr=new int [*iSB];
    for (int i=0;i<*iSB;i++) cin>>arr[i];
    for (int i=*iSB-1;i>=0;i--) cout<<arr[i]<<" ";

    delete iSB; iSB=NULL;
    delete [] arr; arr=NULL;


}
