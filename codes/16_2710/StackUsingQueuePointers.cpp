#include<iostream>
#include<queue>
using namespace std;


class Stack{
private:
    queue<int> *qp;
public:
    Stack(){
        qp=new queue<int>;
    }
    void push_back(int d){
        qp->push(d);
    }
    void pop_back(){
        queue<int> *qh = new queue<int>;
        int temp=-1;
        while (!qp->empty()){
            temp=qp->front();
            qp->pop();
            if (!qp->empty()) qh->push(temp);
        }
        queue<int> *t=qp;
        qp=qh;
        delete t;
    }
    int top(){
        queue<int> *qh = new queue<int>;
        int temp=-1;
        while (!qp->empty()){
            temp=qp->front();
            qp->pop();
            qh->push(temp);
        }
        queue<int> *t=qp;
        qp=qh;
        delete t;
        return temp;
    }
    bool isEmpty(){
        return qp->empty();
    }
    queue<int> *ReturnQAddress(){
        return qp;
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

    Stack s1;
     cout<<s.ReturnQAddress()<<" "<<s1.ReturnQAddress()<<endl;
   s1=s;
    cout<<s.ReturnQAddress()<<" "<<s1.ReturnQAddress()<<endl;
    cout<<s1.top();
    cout<<" " <<s.top()<<endl;
    cout<<s.ReturnQAddress()<<" "<<s1.ReturnQAddress()<<endl;
    /*queue<int> *t = s1.ReturnQAddress();
    cout<<t->front();
    while (!t->empty()){
        cout<<t->front()<<" ";
        t->pop();
    }*/
}
