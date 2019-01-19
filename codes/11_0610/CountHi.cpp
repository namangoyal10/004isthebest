#include<iostream>
using namespace std;

int counthi(char str[], char str1[]){
    if (str[0]=='\0'){
        return 0;
    }
    if (str[0]=='h'&& str[1]=='i'){
        return 1+counthi(str+2);
    }
    return counthi(str+1);
}

int main(){
    char str[]="abchaicbhi";
    cout<<counthi(str);
}
