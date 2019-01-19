#include<iostream>

using namespace std;

int Power(int b, int p){
    int ans=1;
    for (int i=1;i<=p;i++) ans*=b;
    return ans;
}

int fun(int num)
{
    int r,inv=0,cnt;
    for(cnt=1;num>0;num/=10,cnt+=1)
    {
        r=num%10;
        inv=inv + cnt*(Power(10,(r-1)));
    }
    return (inv);
}

int main()
{
    int n;cin>>n;
    int a=fun(n);
    cout<<a;
}
