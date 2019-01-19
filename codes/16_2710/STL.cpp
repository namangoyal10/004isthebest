#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.front()<<" ";
    q.pop();
    q.push(4);
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<" ";
    s.pop();
    s.push(4);
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
