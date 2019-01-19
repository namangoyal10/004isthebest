#include<iostream>
using namespace std;

void Replace(char str[], char outstr[],int j){
if(str[0]=='\0')  { outstr[j]='\0'; return;}
if(str[0]!=str[1]) {outstr[j]=str[0]; j=j+1;}
if(str[0]==str[1]) { outstr[j]=str[0];outstr[j+1]='*';j=j+2;}

Replace(str+1,outstr,j);

}
int main(){
 char str[]="hello";
 char outstr[100];
 Replace(str,outstr,0);
 cout<<outstr;

}
