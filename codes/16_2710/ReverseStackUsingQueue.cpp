#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void ReverseStack(stack<int> &s){
    queue<int> q;
    while (!s.empty()){
        int e=s.top();
        q.push(e);
        s.pop();
    }
    while (!q.empty()){
        s.push(q.front());
        q.pop();
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
