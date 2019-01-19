#include<iostream>
using namespace std;

void print_code(char str[], char res[],int ipos, int oPos){
    if (str[ipos]=='\0'){
        res[oPos]='\0';
        cout<<res<<endl;
        return ;
    }
    if (str[ipos]>'0' && str[ipos]<='9'){
        res[oPos]=str[ipos]-'1'+'A';
        print_code(str,res,ipos+1,oPos+1);
    }
    if (str[ipos+1]!='\0'){
        int num=(str[ipos]-'0')*10+(str[ipos+1]-'0');
        if (num>9 && num<=26){
            res[oPos]=num+'A'-1;
            print_code(str,res,ipos+2,oPos+1);
        }
    }
}

int main(){
    char str[100] = {},res[100]= {};
    cin>>str;
    ///cout<<str;
    print_code(str,res,0,0);
}
