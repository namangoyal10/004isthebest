#include<iostream>
using namespace std;

int factorial(int n){
    if (n<=1) return 1;
    return n*factorial(n-1);
}

int ncr(int n, int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

void pascal(int n){
    if (n==0) return;
    pascal(n-1);
    for (int i=0;i<n;i++){
        cout<<ncr(n-1,i)<<" ";
    }
    cout<<endl;
}

int main(){
    ///cout<<ncr(5,2);
    pascal(6);
}
