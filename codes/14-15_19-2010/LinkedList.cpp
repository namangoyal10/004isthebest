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
friend class LinkedList;
};

class LinkedList{
private:
    Node* head;
    bool Search(Node* h, int k){
        if (h==NULL) return false;
        return h->data==k || Search(h->next,k);
    }

public:
    LinkedList(){
        head =NULL;
    }
    void InsertatBegin(int d){
        Node* nn=new Node(d);
        nn->next=head;
        head=nn;
    }
    void InsertatEnd(int d){
        if (head==NULL) {InsertatBegin(d); return;}
        Node* temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        ///Node* nn=new Node(d);
        temp->next=new Node(d);
    }
    void InsertatPos(int d, int pos){
        if (head==NULL || pos==1) {InsertatBegin(d);return;}
        Node* temp=head;
        int cnt=1;
        while (temp->next!=NULL && cnt<pos-1){
            temp=temp->next;
            cnt++;
        }
        Node* nn=new Node(d);
        nn->next=temp->next;
        temp->next=nn;
    }
    void Print(){
        Node* temp=head;
        while (temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void DeleteatBegin(){
        if (head==NULL) return;
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    void DeleteAtEnd(){
        if (head==NULL) return;
        if (head->next==NULL) {DeleteatBegin();return;}
        Node* temp=head;
        while (temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }

    void DeleteAtPos(int pos){
        if (head==NULL) return;
        if (pos==1) {DeleteatBegin(); return;}
        int cnt=1; Node* temp=head;
        while (temp->next->next!=NULL && cnt<pos-1){
            temp=temp->next;
            cnt++;
        }
        if (cnt==pos-1){
            Node * t=temp->next;
            temp->next=t->next;
            delete t;
        }
    }
    bool Search(int k){
        return Search(head, k);
    }
    Node* Reverse1 (Node * n){
        if (n==NULL) return head;
        int val=n->data;
        Node * t=Reverse1 (n->next);
        t->data=val;
        return t->next;
    }
    void Reverse(){
        ///if (head!=NULL) Reverse1(head);
        ///Reverse2();
        Reverse3(head);
    }

    void Reverse2(){
        if (head==NULL || head->next==NULL) return;
        Node* prev=NULL, *cur=head,*nxt;
        while (cur!=NULL){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        head=prev;
    }

    Node* Reverse3(Node *n){
        if (n==NULL || n->next==NULL) return n;
        Node* nh=Reverse3(n->next);
        n->next->next=n;
        if (n==head){
            head=nh;
            n->next=NULL;
        }
        return nh;
    }

    Node* Merge(Node *h1, Node* h2){
        ///if (h1==NULL && h2==NULL) return NULL;
        if (h1==NULL) return h2;
        if (h2==NULL) return h1;
        if (h1->data<h2->data){
            h1->next=Merge(h1->next,h2);
            return h1;
        } else {
            h2->next=Merge (h1, h2->next);
            return h2;
        }
    }

    Node * Mid (Node *h){
        Node * sp=h, *fp=h;
        while (fp->next!=NULL && fp->next->next!=NULL){
            sp=sp->next;
            fp=fp->next->next;
        }
        Node* sl=sp->next;
        sp->next=NULL;
        return sl;
    }

    Node* MergeSort(Node * h){
        if (h==NULL || h->next==NULL) return h;
        Node * sl=Mid (h);
        h=MergeSort(h);
        sl=MergeSort(sl);
        Node * nh=Merge(h,sl);
        return nh;
    }

    void MergeSort(){
        head=MergeSort(head);
    }

    void SelectionSort1(Node * h){
        ///Swaping Data
        if (h==NULL || h->next==NULL) return;
        Node* smallest=h, *temp=h->next;
        while (temp!=NULL){
            if (temp->data<smallest->data){
                smallest=temp;
            }
            temp=temp->next;
        }
        swap(h->data,smallest->data);
        SelectionSort1(h->next);
    }

    Node* SelectionSort2(Node * h){
        ///Swaping Data
        if (h==NULL || h->next==NULL) return h;
        Node* smallest=h, *cur=h->next, *smallestPrev=NULL, *prev=h;
        while (cur!=NULL){
            if (cur->data<smallest->data){
                smallestPrev=prev;
                smallest=cur;
            }
            prev=cur;
            cur=cur->next;
        }
        if (smallest!=h) {
            smallestPrev->next=smallest->next;
            smallest->next=h;
        }

        smallest->next=SelectionSort2(smallest->next);
        return smallest;
    }


    void SelectionSort(){
        head=SelectionSort2(head);
    }

    Node * BubbleSort(Node * h, Node * kahatak){
        if (h==kahatak || h->next==kahatak) return h;
        Node *prev=NULL, *cur=h, *nxt=h->next;
        while (cur->next!=kahatak){
            nxt=cur->next;
            if (cur->data>nxt->data){
                if (prev==NULL) h=nxt; else prev->next=nxt;
                cur->next=nxt->next;
                nxt->next=cur;
                prev=nxt;
            } else {
                prev=cur;
                cur=nxt;
            }
        }
        return BubbleSort(h,cur);
    }

    void BubbleSort(){
        head=BubbleSort(head,NULL);
    }
    void CreateCycle(int d){
        Node* cn, *temp=head;
        while (temp->next!=NULL){
            if (temp->data==d) cn=temp;
            temp=temp->next;
        }
        temp->next=cn;
    }
    int DetectCycle(){
        Node *s=head, *f=head;
        while (f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
            if (s==f) break;
        }
        if (f==NULL || f->next==NULL) return -1;
        s=head;
        while (s!=f){
            s=s->next;
            f=f->next;
        }
        return s->data;
    }
};

int main(){
    LinkedList l;
    l.InsertatBegin(1);
    l.InsertatBegin(2);
    l.InsertatBegin(3);
    l.InsertatBegin(4);
    l.InsertatEnd(5);
    l.InsertatPos(4,13);

    l.Print();
    l.CreateCycle(3);
    cout<<l.DetectCycle();
    /*l.DeleteatBegin();
    l.Print();
    l.DeleteAtEnd();
    l.Print();
    l.DeleteAtPos(10);
    l.Print();
    l.DeleteAtPos(3);
    l.Print();
    cout<<l.Search(6)<<endl;*/
    //l.Reverse();
    //l.Print();
    ///l.MergeSort();
    ///l.SelectionSort();
    ///l.BubbleSort();
    ///l.Print();
}
