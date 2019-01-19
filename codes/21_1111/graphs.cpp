#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Graph{
private:
    int V;
    list<int> *l;
public:
    Graph(int vertices){
        V=vertices;
        l=new list<int>[V];
    }
    void addEdge(int src, int dest, bool isbidir=true){
        l[src].push_back(dest);
        if (isbidir) l[dest].push_back(src);
    }
    void PrintAdjList(){
        for (int i=0;i<V;i++){
            cout<<i<<"->";
            ///list<int>::iterator
            for (auto it=l[i].begin();it!=l[i].end();it++){
                cout<<*it<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void bfs(int s){
        bool *visited=new bool[V];
        for (int i=0;i<V;i++) visited[i]=false;
        queue<int> q;
        q.push(s);
        visited[s]=true;
        while (!q.empty()){
            int f=q.front();
            q.pop();
            cout<<f<<" ";
            for (auto it=l[f].begin();it!=l[f].end();it++){
                if (!visited[*it]){
                    q.push(*it);
                    visited[*it]=true;
                }
            }
        }
        cout<<endl;
        delete [] visited;
    }

    void bfspath(int s, int d){
        int *distance = new int[V];
        int *parent=new int[V];
        for (int i=0; i<V;i++) {
            distance[i]=-1;
            parent[i]=-1;
        }

        queue<int> q;
        q.push(s);
        distance[s]=0;
        while (!q.empty()){
            int f=q.front();
            q.pop();
            for (auto it=l[f].begin();it!=l[f].end();it++){
                if (distance[*it]==-1){
                    q.push(*it);
                    distance[*it]=distance[f]+1;
                    parent[*it]=f;
                }
            }
        }
        cout<<"Distance of vertex:"<<d<<" is "<<distance[d]<<endl;
        cout<<"Path:"<<d<<"<<";
        int p=parent[d];
        while (p!=-1){
            cout<<p<<"<<";
            p=parent[p];
        }
        cout<<endl;
    }

    void dfs(int s, bool *visited){
        if (visited[s]) return;
        cout<<s<<" ";
        visited[s]=true;
        for (auto it=l[s].begin();it!=l[s].end();it++){
            dfs(*it,visited);
        }
    }
    void dfs(int s){
        cout<<"dfs:";
        bool *visited = new bool[V];
        for (int i=0;i<V;i++) visited[i]=false;
        dfs(s,visited);

        cout<<endl;
    }
    void dfsAll(){
        cout<<"dfsall:"<<endl;
        bool *visited = new bool[V];
        for (int i=0;i<V;i++) visited[i]=false;
        for (int i=0;i<V;i++){
            dfs(i,visited);
            cout<<endl;
        }
        cout<<endl;

    }
};

int main(){
    Graph sl(37);
    int board[37];
    for (int i=1;i<37;i++) board[i]=i;
    board[2]=15;
    board[5]=7;
    board[9]=27;
    board[18]=29;
    board[25]=35;
    board[34]=12;
    board[32]=30;
    board[24]=16;
    board[20]=6;
    board[17]=4;


    for (int i=1;i<36;i++){
        for (int j=1;j<=6;j++){
            if (i+j<=36){
                sl.addEdge(i,board[i+j],false);
            }
        }
    }
    sl.bfspath(1,36);

    return 0;
    Graph g(9);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,5);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(6,7);
    g.addEdge(7,8);
    g.addEdge(6,8);
    g.PrintAdjList();
    g.bfs(0);
    g.bfs(3);
    g.bfspath(0,5);
    g.dfs(0);
    g.dfsAll();

}
