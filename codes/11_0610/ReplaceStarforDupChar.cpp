#include<iostream>
using namespace std;

int Replace(char str[],char outstr[]){
    if (str[0]=='\0'){
        outstr[0]='\0';
        return 0;
    }
    if (str[1]==str[0]){
        outstr[0]=str[0];
        outstr[1]='*';
        return 1+ Replace(str+1,outstr+2);
    }
    else{
        outstr[0]=str[0];
        return Replace(str+1,outstr+1);
    }

}

int main(){
    char str[]="helllo";
    char outstr[100];
    cout<<Replace (str,outstr)<<endl;
    cout<<outstr;
}
