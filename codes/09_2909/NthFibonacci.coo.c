#include<iostream>
using namespace std;

int NthFibonacci(int n){
    if (n==0 || n==1) return n;
    return NthFibonacci(n-1)+NthFibonacci(n-2);
}

int main(){
    cout<<NthFibonacci(8);
}
