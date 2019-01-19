#include<iostream>
using namespace std;
class Node{
private:
    int data;
    Node* next;
public:
    Node(int d=0){
        data=d;
        next=NULL;
    }
friend class Stack;
};

class Stack{
private:
    Node* head;
public:
    Stack(){
        head =NULL;
    }
    void push_back(int d){
        Node* nn=new Node(d);
        nn->next=head;
        head=nn;
    }
    void pop_back(){
        if (head==NULL) return;
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    int top(){
        if (head==NULL) return -1;
        return head->data;
    }
    bool isEmpty(){
        if (head==NULL) return true; else return false;
    }
};

int main(){
    Stack s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    cout<<s.top()<<" ";
    s.pop_back();
    s.push_back(5);
    while (!s.isEmpty()){
        cout<<s.top()<< " ";
        s.pop_back();
    }
}
