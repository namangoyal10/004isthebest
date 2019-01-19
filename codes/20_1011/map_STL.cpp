#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;
    m["rajesh"]=85888;
    m["Ravi"]=98730;
    m["Suresh"]=123456;
    pair<string,int> p;
    p.first="ABC";
    p.second=67890;
    m.insert(p);
    cout<<m["Ravi"]<<endl;
    cout<<m["ABC"]<<endl;
}

