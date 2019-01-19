#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int hn=(n+1)/2;
    for (int i=1;i<=n;i++){
        int eqi;
        if (i<=hn) eqi=i; else eqi=n-i+1;
        for(int j=1;j<=hn-eqi;j++) cout<<" ";
        for(int j=1;j<=2*eqi-1;j++) cout<<"*";
        cout<<endl;
    }
}


/*
int main(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++) cout<<" ";
        for(int j=1;j<=2*i-1;j++) cout<<"*";
        cout<<endl;
    }
}
*/
