#include<iostream>
using namespace std;

void Merge(int arr[], int sPos, int ePos){
    int temp[100];
    for (int i=sPos;i<=ePos;i++) temp[i]=arr[i];
    int mPos=(sPos+ePos)/2;
    int i=sPos, j=mPos+1,k=sPos;
    while (i<=mPos && j<=ePos){
        if (temp[i]<temp[j]){
            arr[k]=temp[i];
            k++;i++;
        } else{
            arr[k]=temp[j];
            k++;j++;
        }
    }
    while (i<=mPos){
        arr[k]=temp[i];
        k++;i++;
    }
    while (j<=ePos){
        arr[k]=temp[j];
        k++;j++;
    }
}


void MergeSort(int arr[], int sPos, int ePos){
    if (sPos>=ePos) return;
    int mPos=(sPos+ePos)/2;
    MergeSort(arr,sPos,mPos);
    MergeSort(arr,mPos+1,ePos);
    Merge(arr, sPos, ePos);
}


int main(){
    int arr[]={3,6,9,4,2,8,1,0,5,7};
    int n=10;
    MergeSort (arr,0,n-1);
    for (int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
}
