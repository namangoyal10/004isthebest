#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int a[1000];

    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int mini=a[0], maxi=a[0], sum=a[0];
    for (int i=1;i<n;i++){
        sum+=a[i];
        if(a[i]<mini) mini=a[i];
        if(a[i]>maxi) maxi=a[i];

    }
    cout<<sum<<" "<<mini<<" "<<maxi<<" "<<float(sum)/n;

}
