#include<iostream>
using namespace std;
///create a string array here

void SubSequence (char str[], char out[], int opos){
    if (str[0]=='\0'){
        out[opos]='\0';
        cout<<out<<endl;
        return;
    }
    ///leke chalte hain
    out[opos]=str[0];
    SubSequence(str+1,out,opos+1);
    ///nahi leke chalte
    SubSequence(str+1,out,opos);

}

int main(){
    char str[5]="abc";
    char out[5]="";
    SubSequence(str,out,0);
}
