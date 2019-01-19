#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int cnt=0, BinConv=0, pv=1;
    for (;n>0;n/=2){
        if (n%2==1) cnt++;
        BinConv+=(n%2)*pv;
        pv*=10;
    }
    cout<<cnt<<endl;
    cout<<BinConv;
}
