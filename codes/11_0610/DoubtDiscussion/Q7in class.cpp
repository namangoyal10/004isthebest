#include<iostream>
using namespace std;
void repeatstar(char str[],char outstr[])
{   if(str[0]=='\0') return;
    if(str[1]!=str[0])
        outstr[0]=str[0];
      return   repeatstar(str+1,outstr+1);
    if(str[0]==str[1])
        {outstr[0]='*';
        outstr[1]=str[0];}
       return repeatstar(str+1,outstr+1);
}
int main()
{
    char str[]="hello";
    char outstr[100];
    repeatstar(str,outstr);
    cout<<outstr;
}







