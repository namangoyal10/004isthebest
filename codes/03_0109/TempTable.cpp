#include<iostream>
using namespace std;

int main(){
    int iv,fv,sv;
    cin>>iv>>fv>>sv;
    for (;iv<=fv;iv=iv+sv){
        cout<<iv<<" "<<(5/9)*(iv-32)<<endl;
    }
}
