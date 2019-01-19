#include<iostream>
using namespace std;

int Factorial(int n){
    int f=1;
    for (int i=1;i<=n;i++) f*=i;
    n=30;
    return f;
}

int main(){
    int n; cin>>n;
    int f=Factorial(n);
    cout<<f<<endl;
    cout<<n;

}
