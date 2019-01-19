#include<iostream>
using namespace std;

int Power(int b, int p){
    int ans=1;
    for (int i=1;i<=p;i++) ans*=b;
    return ans;
}
int arm(int &n)
{   int cnt=0;
    for(int i=n;i>0;i=i/10) ++cnt;
    int sum=0;
   for(int i=n;i>0;i=i/10)
    {
        int rem=i%10;
        sum+=Power(rem,cnt);
    }
    return (n==sum);
    /*bool status=true;
    if(n!=sum)
    {
        status=false;
    }
    return status;*/

}
int main()
{
    int n;
    cout<<"enter n";
    cin>>n;
    cout<<arm(n);
}
