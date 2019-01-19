#include<iostream>
using namespace std;

int main(){
    int a, sum=0, cnt;
    cnt=1;
    while (cnt<=5){
        cin>>a;
        sum=sum+a;
        cnt=cnt+1;
    }
    cout<<sum;
}
