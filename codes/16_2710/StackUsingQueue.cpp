#include<iostream>
#include<queue>
using namespace std;


class Stack{
private:
    queue<int> qp;
    queue<int> qh;
public:
    Stack(){

    }
    void push_back(int d){
        qp.push(d);
    }
    void pop_back(){
        int temp=-1;
        while (!qp.empty()){
            temp=qp.front();
            qp.pop();
            if (!qp.empty()) qh.push(temp);
        }
        while (!qh.empty()){
            qp.push(qh.front());
            qh.pop();
        }

    }
    int top(){
        int temp=-1;
        while (!qp.empty()){
            temp=qp.front();
            qp.pop();
            qh.push(temp);
        }
        while (!qh.empty()){
            qp.push(qh.front());
            qh.pop();
        }
        return temp;
    }
    bool isEmpty(){
        return qp.empty();
    }
};

int main(){
    Stack s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    ///cout<<s.top()<<" ";
    s.pop_back();
    s.push_back(5);
    /*while (!s.isEmpty()){
        cout<<s.top()<< " ";
        s.pop_back();
    }*/

    Stack s1=s;
    cout<<s1.top()<<" " <<s.top()<<endl;
}
