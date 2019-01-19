#include<iostream>
using namespace std;

int main(){
    char ch;
    int alpha=0,digits=0,ws=0,others=0;
    ch=cin.get();
    while (ch!='$'){
        if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
            alpha++;
        } else if (ch>='0'&&ch<='9'){
            digits++;
        }else if (ch==' ' || ch=='\n'){
            ws++;
        } else others++;

        ch=cin.get();
    }
    cout<<alpha<<digits<<ws<<others;
}
