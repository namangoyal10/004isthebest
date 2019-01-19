#include<iostream>
using namespace std;

int main()
{

    int i,j,n,eqi=0,eqj=0;
    cin>>n;
    for(i=1; i<=2*n-1; i++)
    {
        for(j=1; j<=2*n-1; j++)
        {
            if(i<=n)
            {
                eqi=i;
            }
            else
            {
                eqi=2*n-i;
            }
            if(j<=n)
            {
                eqj=j;
            }
            else
            {
                eqj=2*n-j;
            }

            if(eqi+eqj>=n+1)
                cout<<eqi+eqj-(n-eqi+1);
            else
                cout<<" ";
        }
        cout<<endl;
    }

}





