#include<iostream>
using namespace std;

int main(){
    int arr1[7]={3,4,5,7};
    int arr2[3]={1,2,6};
    int m=4,n=3;
    int i=m-1, j=n-1, k=m+n-1;
    while (k>=0 && j>=0){
        if (i>0&&arr1[i]>arr2[j]){
            arr1[k]=arr1[i];
            k--;i--;
        } else {
            arr1[k]=arr2[j];
            j--;k--;
        }
    }
    for(i=0;i<m+n;i++) cout<<arr1[i]<<" "; cout<<endl;
}
/*int main(){
    int arr1[7]={3,4,5,7};
    int arr2[3]={1,2,6};
    int m=4,n=3;
    int i=m-1, j=n-1, k=m+n-1;
    while (i>=0&&j>=0){
        if (arr1[i]>arr2[j]){
            arr1[k]=arr1[i];
            k--;i--;
        } else {
            arr1[k]=arr2[j];
            j--;k--;
        }
    }
    while (j>=0){
        arr1[k]=arr2[j];
        k--;j--;
    }
    for(i=0;i<m+n;i++) cout<<arr1[i]<<" "; cout<<endl;
}
*/
