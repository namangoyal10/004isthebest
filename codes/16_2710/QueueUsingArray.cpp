#include<iostream>
using namespace std;
class Queue{
private:
    int * arr;
    int size;
    int sPos;
    int ePos;
public:
    Queue(int s=5){
        size=s;
        arr=new int[size];
        sPos=-1;
        ePos=-1;
    }
    void push_back(int d){
        int nextPos=(ePos+1)%size;
        if (nextPos!=sPos){///queue is not full
            ePos=nextPos;
            arr[ePos]=d;
            if (sPos==-1) sPos=ePos;
        }
    }

    void pop_back(){
        if (sPos==-1) return;
        if (sPos==ePos){
            sPos=-1;
            ePos=-1;
        } else {
            sPos=(sPos+1)%size;
        }
    }
    int first(){
        if (sPos==-1) return -1; else return arr[sPos];
    }
    bool isEmpty(){
        return (sPos==-1);
    }


};

int main(){
    Queue q(10);
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    cout<<q.first()<< " ";
    q.pop_back();
    q.push_back(5);
    while (!q.isEmpty()){
        cout<<q.first()<< " ";
        q.pop_back();
    }

}
