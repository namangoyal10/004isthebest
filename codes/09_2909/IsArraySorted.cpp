#include<iostream>
using namespace std;

bool isSorted (int arr[],int n){
    if (n<=1) return true;
    /*bool ans=isSorted(arr,n-1);
    if (ans==false) return false;
    if (arr[n-1]>=arr[n-2]) return true; else return false;*/
    return isSorted(arr,n-1) && (arr[n-1]>=arr[n-2]);
}

bool isSorted1 (int arr[],int n){
    if (n<=1) return true;
    /*bool ans=isSorted(arr,n-1);
    if (ans==false) return false;
    if (arr[n-1]>=arr[n-2]) return true; else return false;*/
    return isSorted(arr+1,n-1) && (arr[0]<arr[1]);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    cout<<isSorted1(arr,n);

}
