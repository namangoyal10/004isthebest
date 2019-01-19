#include<iostream>
#include<cmath>
using namespace std;

int main(){
    char str[]="rajesh";
    char str2[100];

    int i,j=0;
    for (i=0;str[i]!='\0';i++){
        str2[j]=str[i];j++;
        if (str[i+1]!='\0'){
            int gap=abs(str[i]-str[i+1]);
            if (gap<=9) {
                str2[j]=gap+'0';j++;
            } else{
                str2[j]=gap/10+'0';j++;
                str2[j]=gap%10+'0';j++;
            }
        }
    }
    str2[i]='\0';
    cout<<str2;
}
