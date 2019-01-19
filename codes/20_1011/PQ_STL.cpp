#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

class printJob{
public:
    int p;
    string toPrint;
    printJob(){};
    printJob(int pr, string tp){
        p=pr;
        toPrint=tp;
    }
    bool operator()(printJob p1, printJob p2){
        return (p1.p>p2.p);
    }
};
class myclass{
public:
    bool operator()(int a, int b){
        return (a>b);
    }
};

int main(){
    ///priority_queue<int> pq;
    priority_queue<int, vector<int>, myclass> pq;
    pq.push(5);
    pq.push(4);
    pq.push(6);
    pq.push(8);
    pq.push(3);
    pq.push(9);
    while (!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    priority_queue<printJob,vector<printJob>,printJob> pqp;
    pqp.push(printJob(2,"Priority 2 data 1"));
    pqp.push(printJob(3,"Priority 3 data 1"));
    pqp.push(printJob(1,"Priority 1 data 1"));
    pqp.push(printJob(2,"Priority 2 data 2"));
    pqp.push(printJob(4,"Priority 4 data 1"));
    pqp.push(printJob(1,"Priority 1 data 2"));
    while (!pqp.empty()){
        printJob pj=pqp.top();
        cout<<pj.toPrint<<endl;
        pqp.pop();
    }
}




