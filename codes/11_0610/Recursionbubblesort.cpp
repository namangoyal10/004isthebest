#include <iostream>
using namespace std;

void bbsort(int arr[],int size)
{
    if (size<=1) return;
    int temp;
    for(int j=0; j<size-1; j++){
        if(arr[j]>arr[j+1]){
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
        }
    }
    bbsort(arr, size-1);
}

int main(){
    int arr[100],size;
    cout<<"enter the no of elements:";
    cin>>size;
    for(int i=0; i<size;i++)
    {
        cin>>arr[i];

    }
    bbsort(arr,size);
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";


}

