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
friend class Queue;
};

class Queue{
private:
    Node* head;
public:
    Queue(){
        head =NULL;
    }
    void push_back(int d){
        if (head==NULL) {head=new Node(d); return;}
        Node* temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        ///Node* nn=new Node(d);
        temp->next=new Node(d);
    }

    void pop_back(){
        if (head==NULL) return;
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    int first(){
        if (head==NULL) return -1;
        return head->data;
    }
    bool isEmpty(){
        if (head==NULL) return true; else return false;
    }


};

int main(){
    Queue q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    while (!q.isEmpty()){
        cout<<q.first()<< " ";
        q.pop_back();
    }

}
