#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n){
    for (int i=0;i<n-1;i++){
        int min_index=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[min_index]) min_index=j;
        }
        swap(arr[i],arr[min_index]);
    }
}

void BubbleSort(int arr[], int n){
    for (int i=0;i<n-1;i++){
        bool isSorted=true;
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                isSorted=false;
            }
        }
        if (isSorted) break;
    }
}
void InsertionSort(int arr[], int n){
    for (int i=1;i<n;i++){
        int temp=arr[i],j;
        for (j=i-1;j>=0&&arr[j]>temp;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}

void CountSort(int arr[], int n){
    int mini=1000, maxi=1006;
    int telly[10]={};
    for (int i=0;i<n;i++){
        telly[arr[i]-mini]++;
    }
    int seq=0;
    for (int i=mini;i<=maxi;i++){
        for (int j=1;j<=telly[i-mini];j++){
            arr[seq++]=i;
        }
    }
}


void InsertionSort1(int arr[], int n){
    int i,j,temp;
    for (i=1,temp=arr[1];i<n;arr[j+1]=temp,i++,temp=arr[i])
        for (j=i-1;j>=0&&arr[j]>temp;arr[j+1]=arr[j],j--);
}

int BinarySearch(int arr[], int n, int k){
    int si=0, ei=n-1;
    while (si<=ei){
        int mid=(si+ei)/2;
        if (arr[mid]==k) {
            return mid;
        } else if (arr[mid]<k){
            si=mid+1;
        } else {
            ei=mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[10]={5,8,3,9,1,4,0,2,17,6};
    int n=10;
    ///SelectionSort(arr,n);
    BubbleSort(arr,n);
    ///InsertionSort(arr,n);
    for (int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
    cout<<BinarySearch(arr,n,7);
    //int arr[]={2,2,2,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,3,1,2,1,3,1};
    /*int arr[]={1002,1002,1002,1001,1002,1001,1001,1001,1001,1001,
        1001,1002,1001,1001,1001,1001,1001,1001,1003,1001,1002,
        1001,1003,1001};
    int n=24;
    CountSort(arr,n);
    for (int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;*/

}
