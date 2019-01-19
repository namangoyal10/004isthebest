#include<iostream>
using namespace std;

void Print (int n){
    if(n==0) return;
    Print(n-1);
    for(int i=1;i<=n;i++) cout<<"*";
    cout<<endl;
}


int main(){
    Print(5);
}

