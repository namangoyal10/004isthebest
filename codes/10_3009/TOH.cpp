#include<iostream>
using namespace std;

void TOH(int n, char fmt, char tot, char ht){
    if (n==0) return;
    TOH(n-1,fmt,ht,tot);
    cout<<"Move ring#"<<n<<" from:"<<fmt<<" to:"<<tot<<endl;
    TOH(n-1,ht,tot,fmt);
}

int main(){
    TOH(3,'A','B','C');
}
