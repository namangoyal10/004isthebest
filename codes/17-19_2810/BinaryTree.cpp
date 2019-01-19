#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left, *right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
typedef pair<int,pair<Node*,int> > PINI;

class BinaryTree{
private:
    Node * root;
public:
    BinaryTree(){root=NULL;}

    Node* TakeInputRec(){///private function
        int d,c;
        cout<<"Enter the data";
        cin>>d;
        if (d==-1) return NULL;
        Node*n=new Node(d);
        n->left=TakeInputRec();
        n->right=TakeInputRec();
        return n;
    }

    void TakeInput(){///public function
        root=TakeInputRec();
        cout<<endl;
    }

    void PrintPreOrder(Node* rt){
        if (rt==NULL) return;
        cout<<rt->data<<" ";
        PrintPreOrder(rt->left);
        PrintPreOrder(rt->right);
    }

    void PrintPreOrder(){///public function
        cout<<"PreOrder:";
        PrintPreOrder(root);
        cout<<endl;
    }
    void PrintPostOrder(Node* rt){
        if (rt==NULL) return;
        PrintPostOrder(rt->left);
        PrintPostOrder(rt->right);
        cout<<rt->data<<" ";
    }

   void PrintPostOrder(){///public function
        cout<<"PostOrder:";
        PrintPostOrder(root);
        cout<<endl;
    }

   void PrintInOrder(Node* rt){
        if (rt==NULL) return;
        PrintInOrder(rt->left);
        cout<<rt->data<<" ";
        PrintInOrder(rt->right);
    }

   void PrintInOrder(){///public function
        cout<<"InOrder:";
        PrintInOrder(root);
        cout<<endl;
    }

    Node* LevelOrderInput(){
        int d;
        cout<<"enter root data:";
        cin>>d;
        Node * n=new Node(d);

        queue<Node*> q;
        q.push(n);
        while (!q.empty()){
            Node* f=q.front();
            q.pop();
            cout<<"Enter data for left node for data-"<<f->data<<":";
            cin>>d;
            if (d!=-1) {
                f->left=new Node(d);
                q.push(f->left);
            }
            cout<<"Enter data for right node for data-"<<f->data<<":";
            cin>>d;
            if (d!=-1) {
                f->right=new Node(d);
                q.push(f->right);
            }
         }
        return n;
    }
    void TakeLOInput(){
        root=LevelOrderInput();
        cout<<endl;
    }

    void PrintLevelOrder(){
        if (root==NULL) return;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()){
            Node* f=q.front();
            q.pop();
            if (f==NULL){
                cout<<endl;
                if (!q.empty()) q.push(NULL);
            } else{
                cout<<f->data<<" ";
                if (f->left!=NULL) q.push(f->left);
                if (f->right!=NULL) q.push(f->right);
           }
        }
        cout<<endl;
    }
    void PrintAllLeaves(Node* rt){
        if (rt==NULL) return;
        if (rt->left==NULL && rt->right==NULL) cout<<rt->data<<" ";
        PrintAllLeaves(rt->left);
        PrintAllLeaves(rt->right);
    }
    void PrintAllLeaves(){
        cout<<"Leaves:";
        PrintAllLeaves(root);
        cout<<endl;
    }
    int Height(Node* rt){
        if (rt==NULL) return -1;
        return max(Height(rt->left),Height(rt->right))+1;
    }
    int Height(){
        return Height(root);
    }
    int Depth (Node* rt, int k, int d){
        if (rt==NULL) return -1;
        if (rt->data==k) return d;
        int ans=Depth(rt->left,k,d+1);
        if (ans!=-1) return ans;
        return Depth(rt->right,k,d+1);
    }
    int Depth(int k){
        return Depth(root,k,0);
    }

    PINI getDia(Node* rt){
        PINI ans;
        if (rt==NULL){
            ans.first=0;
            ans.second.first=NULL;
            ans.second.second=0;
            return ans;
        }
        PINI lans=getDia(rt->left);
        PINI rans=getDia(rt->right);
        ans.first=max(lans.first,rans.first)+1;
        int mydia=lans.first+rans.first+1;
        if (mydia>=lans.second.second && mydia>=rans.second.second){
            ans.second.first=rt;
            ans.second.second=mydia;
        } else if (lans.second.second>=rans.second.second){
            ans.second.first=lans.second.first;
            ans.second.second=lans.second.second;
        } else {
            ans.second.first=rans.second.first;
            ans.second.second=rans.second.second;
        }
        return ans;
    }
    void getDia(){
        if (root==NULL) return;
        PINI ans=getDia(root);
        cout<<"Diameter of tree is:"<<ans.second.second<<" and is passing thru-"
            <<ans.second.first->data;
    }

    Node* FillPreOrderInOrder(int arrpo[],int pos, int poe, int arrio[], int ios, int ioe){
        if (pos>poe || ios>ioe) return NULL;
        int d=arrpo[pos],i;
        Node * rt=new Node(d);
        for (i=ios;i<=ioe;i++){
            if (arrio[i]==d){
                break;
            }
        }
        rt->left=FillPreOrderInOrder(arrpo,pos+1,pos+(i-ios),arrio,ios,i-1);
        rt->right=FillPreOrderInOrder(arrpo,pos+(i-ios)+1,poe,arrio,i+1,ioe );
        return rt;
    }
    void FillPreOrderInOrder(){
        int arrpo[]={1,2,4,7,8,5,3,6,9};
        int arrio[]={7,4,8,2,5,1,9,6,3};
        int n=9;
        root=FillPreOrderInOrder(arrpo, 0,n-1,arrio, 0,n-1);
    }
};


int main(){
    BinaryTree T;
    ///T.TakeInput();
    ///T.TakeLOInput();
    T.FillPreOrderInOrder();
    T.PrintPreOrder();
    T.PrintInOrder();
    T.PrintPostOrder();
    T.PrintLevelOrder();
    T.PrintAllLeaves();
    cout<<"Height:"<<T.Height()<<endl;
    cout<<"Depthof 5 is " <<T.Depth(5)<<endl;
    T.getDia();

}
///PO input
///1 2 4 7 -1 -1 8 -1 -1 5 -1 -1 3 6 9 -1 -1 -1 -1
///LO input
///1 2 3 4 5 6 -1 7 8 -1 -1 9 -1 -1 -1 -1 -1 -1 -1

///LO input for dia
///1 2 3 4 5 6 -1 7 8 -1 -1 9 -1 10 -1 -1 11 -1 -1 12 -1 -1 13 14 -1 -1 15 16 -1 -1 17 18 -1 -1 19 -1 -1 -1 -1

