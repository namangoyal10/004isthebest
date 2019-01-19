#include<iostream>
using namespace std;

char num_to_char(char* str,int digits,int &i){
    int num;
    if(digits==0){
        num = (int)(*str-'0');
        //temp = 0;
    }
    else{
        if(*str=='1'){
            num = (10+(int)(*(str+1)-'0'));
            //temp = 1;
        }
        else if((*str=='2')&&(*(str+1)<='6')){
            num = (20+(int)(*(str+1)-'0'));
            //temp = 2;
        }
        else{
            num = (int)(*str-'0');
            i = i-1;
            //temp = 3;
        }
        //cout<<"incrementing index"<<endl;
        i = i+1;
        //temp = temp+1;
    }
    //cout<<"temp - "<<temp<<" "<<"i - "<<i<<" "<<(char)('a'+num-1)<<" ";
    if((char)('a'+num-1)=='0') return '\0';
    return (char)('a'+num-1);
}
void print_code(char* str,char* res,int i,int j,int gr){
    if(str[i+1]=='\0'){
        res[j] = num_to_char(str+i,gr,i);
        res[j+1] = '\0';
        cout<<res<<endl;
        return;
    }
    if(i>=0&&j>=0){
        res[j] = num_to_char(str+i,gr,i);
        //cout<<" "<<i<<" "<<res[j]<<" ";
    }
    //if(str[i+temp]!='\0')
    {
        print_code(str,res,i+1,j+1,0);
    }

    //if(str[i+num-2]!='\0')
    {
        print_code(str,res,i+1,j+1,1);
    }
}
int main(){
    char str[100] = {},res[100]= {};
    cin>>str;

    print_code(str,res,-1,-1,0);
}
