#include<iostream>
using namespace std;
///create a string array here

int SubSequence (char str[], char outstr[][5]){
    if (str[0]=='\0') {
        outstr[0][0]='\0';
        return 1;
    }
    int cnt=SubSequence(str+1,outstr);
    for (int i=0;i<cnt;i++){
        outstr[cnt+i][0]=str[0];
        int j;
        for (j=0;outstr[i][j]!='\0';j++){
            outstr[cnt+i][j+1]=outstr[i][j];
        }
        outstr[cnt+i][j+1]='\0';
    }
    return 2*cnt;
}

int main(){
    char str[5]="abc";
    char outstr[100][5];
    int i=SubSequence(str,outstr);
    for (int j=0;j<i;j++) cout<<outstr[j]<<endl;
}
