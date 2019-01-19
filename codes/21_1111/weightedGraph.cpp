#include<iostream>
#include<queue>
#include<list>
using namespace std;
typedef pair<int,int> pii;

class mycompare{
public:
    bool operator()(pii p1, pii p2){
        return p1.second>p2.second;
    }
};

class WGraph{
private:
    list<pii> *l;
    int V;
public:
    WGraph(int n){
        V=n;
        l=new list<pii>[V];
    }
    void addEdge(int s, int d, int wt){
        l[s].push_back(make_pair(d,wt));
    }
    int dijikstra(int s, int d){
        priority_queue<pii,vector<pii>,mycompare> pq;
        int * distance = new int[V];
        for (int i=0;i<V;i++) distance[i]=INT_MAX;
        distance[s]=0;
        pq.push(make_pair(s,0));
        while(!pq.empty()){
            pii f=pq.top();
            pq.pop();
            if (f.second!=distance[f.first]) continue;
            for (auto it=l[f.first].begin();it!=l[f.first].end();it++){
                int cd=distance[f.first]+it->second;
                if (cd<distance[it->first]){
                    distance[it->first]=cd;
                    pq.push(make_pair(it->first,cd));
                }
            }
        }
        cout<<"Shortest distance is "<<distance[d]<<endl;

        for (int i=0;i<V;i++){
            cout<<i<<":"<<distance[i]<<endl;
        }
    }
};


int main(){
    WGraph g(7);
    g.addEdge(0,1,20);
    g.addEdge(0,2,15);
    g.addEdge(0,3,15);
    g.addEdge(1,4,10);
    g.addEdge(2,4,17);
    g.addEdge(2,5,16);
    g.addEdge(3,5,15);
    g.addEdge(4,6,8);
    g.addEdge(5,6,6);
    cout<<g.dijikstra(0,6)<<endl;
}
