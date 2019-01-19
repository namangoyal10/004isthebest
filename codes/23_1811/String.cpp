#include <iostream>
#include<cstring>
using namespace std;

void test(string &s){
    cout<<s<<endl;
    s="Sachdev";
    cout<<s<<endl;
}

int main(){
    string s1;
    ///s1[5]='d';
    s1="Rajesh";
    test(s1);
    cout<<s1<<endl;
    cout<<s1[2]<<endl;
    string s2="abc"+ s1;
    cout<<s2<<endl;
}
