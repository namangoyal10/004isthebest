#include<iostream>
using namespace std;
int Power(int b, int p){
    int ans=1;
    for (int i=1;i<=p;i++) ans*=b;
    return ans;
}
int Armstrong(int n)
{
    int num=0, rem, cnt=0;

    for(int i=n;i>0;i/=10) cnt++;
    for(int j=n;j>0;j/=10){
        rem=j%10;
        num=num+Power(rem,cnt);
    }
    if(num==n) cout<<"true"; else cout<<"false";
}

int main()
{
    int n; cin>>n;
    cout<<Armstrong(n);
}
