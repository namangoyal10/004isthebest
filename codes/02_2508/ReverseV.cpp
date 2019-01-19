#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int i=1;
    while (i<=n){
        int j=1;
        while (j<=n-i){
            cout<<" ";
            j=j+1;
        }
        cout<<"*";
        j=1;
        while (j<=2*i-3){
            cout<<" ";
            j=j+1;
        }
        if (i!=1) cout<<"*";
        cout<<endl;
        i=i+1;
    }
}
