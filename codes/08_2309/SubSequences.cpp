#include<iostream>
using namespace std;

int Power(int a, int b){
    int p=1;
    for (int i=1;i<=b;p*=a,i++);
    return p;
}

int main(){
    char str[]="abc";
    int length=0;
    for (;str[length]!='\0';length++);
    for (int i=0;i<Power(2,length);i++){
        int ci=i,bp=0;
        while (ci>0){
            int r=ci%2;
            if (r==1) cout<<str[bp];
            ci=ci/2;bp++;
        }
        cout<<endl;
    }
}
