#include<iostream>
using namespace std;
int memo[100];

int NthFibonacci(int n){
    if (n==0 || n==1) return n;
    /*if (memo[n]!=-1){
        return memo[n];
    }*/
    int ans= NthFibonacci(n-1)+NthFibonacci(n-2);
    memo[n]=ans;
    return ans;
}

int main(){
    for (int i=0;i<100;i++) memo[i]=-1;
    cout<<NthFibonacci(40);
}
