#include<iostream>
using namespace std;

int factorial(int n){
    if (n==0) return 1;
    int ans=factorial(n-1);
    return ans*n;
}

int main(){

    cout<<factorial(5);

}
