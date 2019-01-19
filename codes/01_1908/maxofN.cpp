#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int cnt=1,Max=INT_MIN,a;
    while (cnt<=n){
        cin>>a;
        if (a>Max) Max=a;
        cnt=cnt+1;
    }
    cout<<Max;
}

/*
int main(){
    int n;cin>>n;
    int cnt=1,Max,a;
    while (cnt<=n){
        cin>>a;
        if (cnt==1) Max=a;
        else if (a>Max) Max=a;
        cnt=cnt+1;
    }
    cout<<Max;
}
*/
