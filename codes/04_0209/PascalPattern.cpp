#include<iostream>
using namespace std;

int Factorial(int n){
    int f=1;
    for (int i=1;i<=n;i++) f*=i;
    return f;
}
int NCR (int n, int r){
    return Factorial(n)/(Factorial(n-r)*Factorial(r));
}

int main(){
    /*int a; cin>>a;
    int f=Factorial(a);
    cout<<f<<endl;;*/
    cout<<NCR(5,3);
}
