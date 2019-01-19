#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int i=1;
    int Spaces=((n+1)/2)-1, Stars=1;
    while (i<=n){
        int j=1;
        while (j<=Spaces){
            cout<<" ";
            j=j+1;
        }
        j=1;
        while (j<=Stars){
            cout<<"*";
            j=j+1;
        }
        cout<<endl;
        if (i<(n+1)/2){
            Spaces=Spaces-1;
            Stars=Stars+2;
        } else {
            Spaces=Spaces+1;
            Stars=Stars-2;
        }
        i=i+1;
    }
}
