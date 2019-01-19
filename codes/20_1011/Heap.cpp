#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue{
private:
    vector<int> V;
public:
    PriorityQueue(){
        V.push_back(-1);
    }
    void push_back(int d){
        V.push_back(d);
        int child=V.size()-1;
        int parent=child/2;
        while (parent>0 && V[parent]>V[child]){
            swap (V[parent],V[child]);
            child=parent;
            parent=child/2;
        }
    }
    int getmin(){
        if (V.size()<=1) return -1; else return V[1];
    }
    void ReHeapify(int i){
        int min_i=i;
        int left=2*i, right=2*i+1;
        if (left<V.size()){
            if (V[left]<V[min_i]) min_i=left;
        }
        if (right<V.size()){
            if (V[right]<V[min_i]) min_i=right;
        }
        if (i!=min_i){
            swap(V[i],V[min_i]);
            ReHeapify(min_i);
        }
    }
    void pop(){
        if (V.size()<=1) return;
        if (V.size()==2) {
            V.pop_back(); return;
        }
        swap(V[1],V[V.size()-1]);
        V.pop_back();
        ReHeapify(1);
    }
    bool isempty(){
        if (V.size()>1) return false; else return true;
    }
    int size(){
        return V.size()-1;
    }
};

int main(){
    PriorityQueue pq;
    pq.push_back(5);
    pq.push_back(4);
    pq.push_back(6);
    pq.push_back(8);
    pq.push_back(3);
    pq.push_back(9);
    while (!pq.isempty()){
        cout<<pq.getmin()<<" ";
        pq.pop();
    }
}
