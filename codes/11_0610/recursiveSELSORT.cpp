#include<iostream>
using namespace std;
#define max1=20
void selsort(int arr[],int size)
{
    if(size==0)
        return;
    int smallest=arr[0],buffer,k=0;
    for(int i=0; i<size; ++i)
        if(arr[i]<smallest)
        {
            smallest=arr[i];
            k=i;
        }
    buffer=arr[k];
    arr[k]=arr[0];
    arr[0]=buffer;
    selsort(arr+1,size-1);
}


int main()
{
    int arr[max1],size;
    cout<<"enter no. of elements(integers) you want to sort(<"<<max1<<") :- ";
    cin>>size;
    for(int i=0; i<size; ++i)
    {
        cout<<"enter "<<i+1<<"th element:- ";
        cin>>arr[i];
    }
    selsort(arr,size);
    cout<<"sorted array"<<endl;
    for(int i=0; i<size; ++i)
        cout<<arr[i]<<"  ";
}
