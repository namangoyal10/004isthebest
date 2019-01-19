#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void ReverseStack (stack<int> &s, stack<int> &hs){
    if (s.empty()) return;
    int val=s.top();
    s.pop();
    ReverseStack(s,hs);
    hs.push(val);
}

void ReverseStack(stack<int> &s){
    stack<int> hs;
    ReverseStack(s,hs);
    while (!hs.empty()){
        s.push(hs.top());
        hs.pop();
    }
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.push(4);

    ReverseStack(s);

    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
