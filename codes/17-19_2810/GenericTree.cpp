#include<iostream>
#include<queue>
using namespace std;


class Node{
private:
    int data;
    Node** children;
    int child_count;
public:
    Node(int d){
        data=d;
        children=NULL;
        child_count=0;
    }
    friend class GenericTree;
};
typedef pair<int,pair<Node*,int> > PINI;
class myOutput{
public:
    Node * n;
    int M;
};
class GenericTree{
private:
    Node * root;
public:
    GenericTree(){
        root=NULL;
    }

    void FillData(Node* &rt){
        int d; cin>>d;
        rt=new Node (d);
        cout<<"enter no of children for-"<<d<<":";
        int c; cin>>c;
        rt->child_count=c;
        rt->children=new Node*[c];
        for (int i=0;i<c;i++){
            FillData(rt->children[i]);
        }
    }
    void FillData(){
        FillData(root);
    }

    void Print_PreOrder(Node* rt){
        if (rt==NULL) return;
        cout<<rt->data<<" ";
        for (int i=0;i<rt->child_count;i++){
            Print_PreOrder(rt->children[i]);
        }
    }

    void Print_PreOrder(){
        cout<<endl<<"Pre-Order:";
        Print_PreOrder (root);
        cout<<endl;
    }
     void Print_PostOrder(Node* rt){
        if (rt==NULL) return;
        for (int i=0;i<rt->child_count;i++){
            Print_PostOrder(rt->children[i]);
        }
        cout<<rt->data<<" ";
    }
   void Print_PostOrder(){
       cout<<"Post Order:";
        Print_PostOrder (root);
        cout<<endl;
    }
    void FillLO(){
        int d; cin>>d;
        root=new Node(d);
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            Node* t=q.front();
            q.pop();
            cout<<"Enter no of children for "<<t->data<<":";
            int c; cin>>c;
            t->child_count=c;
            t->children=new Node*[c];
            for(int i=0;i<c;i++){
                cout<<"enter data for child#"<<i+1<<" of "<<t->data<<":";
                cin>>d;
                t->children[i]=new Node(d);
                q.push(t->children[i]);
            }
        }
    }
    bool Search(Node* rt, int k){
        if (rt==NULL) return false;
        if (rt->data==k) return true;
        for (int i=0;i<rt->child_count;i++){
            if (Search(rt->children[i],k)) return true;
        }
        return false;
    }
    bool Search(int k){
        return Search(root,k);
    }

    int Max (Node* rt){
        if (rt==NULL) return INT_MIN;
        int M=rt->data;
        for (int i=0;i<rt->child_count;i++){
            int ans=Max(rt->children[i]);
            if (ans>M) M=ans;
        }
        return M;
    }

    int Max(){
        return Max(root);
    }
    void PrintatKDepth (Node* rt, int DPrint, int curDepth){
        if (rt==NULL) return;
        if (curDepth>DPrint) return;
        if (DPrint==curDepth) cout<<rt->data<<" ";
        for (int i=0; i<rt->child_count;i++){
            PrintatKDepth(rt->children[i],DPrint, curDepth+1);
        }
    }
    void PrintatKDepth(int k){
        PrintatKDepth(root,k,0);
    }
    int NoofNodes (Node* rt){
        if (rt==NULL) return 0;
        int cnt=1;
        for (int i=0;i<rt->child_count;i++){
            cnt+=NoofNodes(rt->children[i]);
        }
        return cnt;
    }
    int NoofNodes(){
        return NoofNodes(root);
    }
    int NoofNodesGTK (Node* rt, int k){
        if (rt==NULL) return 0;
        int cnt=0;
        if (rt->data>=k) cnt++;
        for (int i=0;i<rt->child_count;i++){
            cnt+=NoofNodesGTK(rt->children[i],k);
        }
        return cnt;
    }
    void NoofNodesGTK(Node* rt, int k, int &cnt){
        if (rt==NULL) return;
        if (rt->data>=k) cnt++;
        for (int i=0;i<rt->child_count;i++){
            NoofNodesGTK(rt->children[i],k,cnt);
        }
    }
    int NoofNodesGTK(int k){
        ///return NoofNodesGTK(root,k);
        int cnt=0;
        NoofNodesGTK (root, k, cnt);
        return cnt;
    }
    myOutput NodeWithMaxChildSum(Node* rt){
        myOutput ans;
        if (rt==NULL) {
            ans.M=INT_MIN;
            ans.n=NULL;
            return ans;
        }
        int myfamilysum=rt->data;
        for (int i=0;i<rt->child_count;i++) {
            if (rt->children[i]!=NULL) myfamilysum+=rt->children[i]->data;
        }
        ans.M=myfamilysum;
        ans.n=rt;
        for (int i=0;i<rt->child_count;i++){
            myOutput cans=NodeWithMaxChildSum(rt->children[i]);
            if (cans.M>ans.M){
                ans.M = cans.M;
                ans.n = cans.n;
            }
        }
        return ans;
    }
    void NodeWithMaxChildSum(){
        myOutput ans=NodeWithMaxChildSum(root);
        if (root!=NULL) cout<<"Node with data="<<ans.n->data<<" has max sum="<<ans.M<<endl;
    }

    PINI NodeWithMaxSubTreeSum (Node* rt){
        PINI ans;
        if (rt==NULL){
            ans.first=0;
            ans.second.first=NULL;
            ans.second.second=INT_MIN;
            return ans;
        }
        ans.first=rt->data;
        ans.second.first=NULL; //discuss
        ans.second.second=INT_MIN;
        for (int i=0;i<rt->child_count;i++){
            PINI cans=NodeWithMaxSubTreeSum(rt->children[i]);
            ans.first+=cans.first;
            if (cans.second.second>ans.second.second) {
                ans.second.first=cans.second.first;
                ans.second.second=cans.second.second;
            }
        }
        if (ans.first>ans.second.second){
            ans.second.first=rt;
            ans.second.second=ans.first;
        }
        return ans;
    }

    void NodeWithMaxSubTreeSum(){
        PINI ans=NodeWithMaxSubTreeSum(root);
        cout<<"Node with data:"<<ans.second.first->data<<" has max sum of subtree="
            <<ans.second.second<<endl;
    }
};

int main(){
    GenericTree t;
    //t.FillData();
    t.FillLO();
    t.Print_PreOrder();
    t.Print_PostOrder();
    cout<<t.Search(15)<<endl;
    cout<<t.Max()<<endl;
    t.PrintatKDepth(2); cout<<endl;
    cout<<t.NoofNodes()<<endl;
    cout<<t.NoofNodesGTK(5)<<endl;
    t.NodeWithMaxChildSum();
    t.NodeWithMaxSubTreeSum();


}
///1 3 2 2 5 2 10 0 11 0 6 0 3 2 7 0 8 1 12 0 4 1 9 0
///1 3 2 3 4 2 5 6 2 7 8 1 9 2 10 11 0 0 1 12 0 0 0 0
//////PO input for max sybtree
///-1 3 -2 -300 -400 2 -5 -6 2 7 8 1 9 2 10 11 0 0 1 12 0 0 0 0
