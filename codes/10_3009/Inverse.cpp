#include<iostream>
using namespace std;

void Inverse(int arr[], int n, int sp){
    if (sp>=n) return;
    int val=arr[sp];
    Inverse(arr,n,sp+1);
    arr[val]=sp;
}

int main(){
    int arr[4]={2,0,3,1};
    Inverse (arr,4,0);
    for (int i=0;i<4;i++) cout<<arr[i];
}
