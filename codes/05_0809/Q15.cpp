#include<iostream>
using namespace std;
void values(int &n1,int &n2)
{   int i=0;
    while(i<n1)
    {
        int num=3*i+2;
        if(! ( num % n2==0))
            cout<<num<<" ";
        ++i;


    }

}
int main()
{
    int n1,n2;
    cout<<"enter number";
    cin>>n1;
    cout<<"enter number 2";
    cin>>n2;
    values(n1,n2);
}
