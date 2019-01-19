#include<iostream>
using namespace std;

bool ass711(int arr[], int n,int sp){
    if (sp>=n) return false;
    if(arr[sp]==arr[n-1]) return true;
    return ass711(arr,n-1,sp+1);

}

int main(){
    int arr[4]={2,7,5,2};
    int n;
    cout<<ass711(arr,4,0);
}
