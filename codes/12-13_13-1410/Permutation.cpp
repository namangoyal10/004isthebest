#include<iostream>
using namespace std;

void printPermutations(char str[],int spos){
    if (str[spos]=='\0'){
        cout<<str<<endl; return;
    }
    for (int i=spos; str[i]!='\0';i++){
        ///swap (str[i],str[spos]);
        char temp=str[i];
        for (int j=i;j>spos;j--) str[j]=str[j-1];
        str[spos]=temp;
        printPermutations(str,spos+1);
        temp=str[spos];
        for (int j=spos;j<i;j++) str[j]=str[j+1];
        str[i]=temp;
        ///swap (str[i],str[spos]);
    }
}

int main(){
    char str[]="abcd";
    printPermutations(str,0);
}

