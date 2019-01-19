#include<iostream>
using namespace std;

int main(){
    char ch;
    int cnt=0;
    do {
        ch=cin.get();
        ///if (ch=='$') break;
        cnt++;
    } while (ch!='$');
    cout<<cnt-1;
}

/*
int main(){
    char ch;
    int cnt=0;
    ///ch=cin.get();
    ///ch='x';
    ///while (ch!='$'){
    while (true){
        ch=cin.get();
        if (ch=='$') break;
        cnt++;
    }
    cout<<cnt;
}*/

/*int main(){
    char ch;
    int cnt=0;
    ch=cin.get();
    while (ch!='$'){
        cnt++;
        ch=cin.get();
    }
    cout<<cnt;
}*/
