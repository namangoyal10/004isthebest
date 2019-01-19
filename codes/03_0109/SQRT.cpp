#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int p;cin>>p;
    int myP;
    float inc=1;
    float ans=0;
    for (myP=0;myP<=p;myP=myP+1,inc=inc/10){
        for (;ans*ans<=n;ans=ans+inc);
        ans=ans-inc;
    }
    cout<<ans;
}


/*
int main(){
    int n;cin>>n;
    int i;
    for (i=0;i*i<=n;i=i+1);
    cout<<i-1;
}*/
