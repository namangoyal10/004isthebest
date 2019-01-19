#include<iostream>
using namespace std;

bool Find7(int arr[], int n){
    if (n==0) return false;
    if (arr[0]==7) return true;
    return Find7(arr+1,n-1);
}

int Find7FirstIndex1(int arr[], int n, int on){
    if (n==0) return -1;
    if (arr[0]==7) return on-n;
    return Find7FirstIndex1(arr+1,n-1,on);
}

int Find7FirstIndex2(int arr[], int n, int sp){
    if (sp>=n) return -1;
    if (arr[sp]==7) return sp;
    return Find7FirstIndex2(arr,n,sp+1);
}

int Find7FirstIndex3(int arr[], int n){
    if (n==0) return -1;
    int ans=Find7FirstIndex3(arr,n-1);
    if (ans!=-1) return ans;
    if (arr[n-1]==7) return n-1; else return -1;
}

int Find7LastIndex(int arr[], int n){
    if (n==0) return -1;
    if (arr[n-1]==7) return n-1;
    return Find7LastIndex(arr,n-1);
}

int Find7FirstIndex4(int arr[], int n){
    if (n==0) return -1;
    if (arr[0]==7) return 0;
    int ans=Find7FirstIndex4(arr+1,n-1);
    if (ans==-1) return -1; else return ans+1;
}

void Find7Allind(int arr[], int n, int sp){
    if (sp>=n) return;
    if (arr[sp]==7) cout<< sp<<" ";
    Find7Allind(arr,n,sp+1);
}

int main(){
    int arr[10]={2,9,0,7,3,7,6,4,17,1};
    int n=10;
    ///cout<<Find7(arr,n);
    ///cout<<Find7FirstIndex1(arr,n,n);
    ///cout<<Find7FirstIndex2(arr,n,0);
    ///cout<<Find7FirstIndex3(arr,n);
    ///cout<<Find7FirstIndex4(arr,n);
    ///cout<<Find7LastIndex(arr,n);
    Find7Allind(arr,n,0);
}
