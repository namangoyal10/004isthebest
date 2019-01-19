///separating all duplicate characters in a string by * using recursion
#include<iostream>
using namespace std;

void separate(char str[],char str1[] ,int i, int j){
    if(str[i]=='\0'){
        str1[j]='\0';
        return;
    }
    cout<<i<<" "<<j<<endl;
    if(i>0 && str[i-1]==str[i]){
        str1[j]='*';
        str1[j+1]=str[i];
        separate(str,str1,i+1,j+2);
    }
    else{
        str1[j]=str[i];
        separate(str,str1,i+1,j+1);
    }
    ///cout<<str1;
}

int main(){
    char str[100]="Hello",str1[100];
    ///cin.getline(str,100);
    separate(str,str1,0,0);
    cout<<str1;
}
