#include<iostream>
using namespace std;
int value(char str[])
{
    for(int i=0;i<=10;i++)
    {
        if(str[i]!=str[i+1])  return 0;
        else
        {
            for(int k=0,l=i+2;k<=i,l<=10;k++,l++)
                cout<<str[k]<<str[l];
        }
    }
}
int main()
{
    char str[10]={"H","E","L","L","O","M","O","T","O"};
    cout<<value(str);
}
