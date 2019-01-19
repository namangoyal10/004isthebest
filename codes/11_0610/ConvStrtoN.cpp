#include<iostream>
using namespace std;

int StrtoN(char str[], int &pv){
    if (str[0]=='\0'){
        pv=1;
        return 0;
    }
    int ans=StrtoN(str+1,pv);
    ans= (str[0]-'0')*pv+ans;
    pv*=10;
    return ans;
}


int main(){
    char str[]="1234";
    int pv=1;
    cout<<StrtoN(str,pv);
}
