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

class BST{
private:
    Node * root;
public:
    BST(){root=NULL;}
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

    Node* FillBST(Node* rt, int d){
        if (rt==NULL){
            return new Node(d);
        }
        if (d<=rt->data){
            rt->left=FillBST(rt->left,d);
        } else {
            rt->right=FillBST(rt->right,d);
        }
        return rt;
    }

    void FillBST(){
        ///cout<<"How many nodes to be added:";
        ///int n; cin>>n;
        int arr[]={15,8,28,14,20,13,12,8,21,20};
        int n=10;
        for (int i=0;i<n;i++){
            ///int a; cin>>a;
            root=FillBST(root,arr[i]);
        }
    }

    bool SearchBST(Node* rt, int d){
        if (rt==NULL) return false;
        if (rt->data==d) return true;
        if (d<=rt->data) return SearchBST(rt->left,d);
        return SearchBST(rt->right,d);
    }
    bool SearchBST(int d){
        return SearchBST(root,d);
    }

    bool isBST(Node* rt, int mn, int mx){
        if (rt==NULL) return true;
        if (rt->data<mn || rt->data>mx) return false;
        return (isBST(rt->left,mn,rt->data)&& isBST(rt->right,rt->data,mx));
    }
    bool isBST(){
        return isBST(root,INT_MIN,INT_MAX);
    }
    Node* FillSortedArray(int arr[],int spos, int epos){
        if (spos>epos) return NULL;
        int mid=(spos+epos)/2;
        Node * rt=new Node(arr[mid]);
        rt->left=FillSortedArray(arr,spos,mid-1);
        rt->right=FillSortedArray(arr,mid+1,epos);
        return rt;
    }
    void FillSortedArray(){
        int arr[]={1,2,3,4,5,6,7,8,9};
        int n=9;
        root=FillSortedArray(arr,0,8);
    }
    Node* DeleteNode(Node* rt, int d){
        if (rt==NULL) return NULL;
        if (rt->data==d){
            if (rt->left==NULL && rt->right==NULL){
                delete rt;
                return NULL;
            }
            if (rt->left==NULL) {
                Node* temp=rt->right;
                delete rt;
                return temp;
            }
            if (rt->right==NULL) {
                Node* temp=rt->left;
                delete rt;
                return temp;
            }
            ///we have both left and right element.
            ///lets find right most from the left subtree
            Node * temp=rt->left;
            while (temp->right!=NULL){
                temp=temp->right;
            }
            swap(rt->data,temp->data);
            rt->left=DeleteNode (rt->left,d);
        } else {
            if (d<=rt->data) rt->left=DeleteNode(rt->left,d);
            else rt->right=DeleteNode(rt->right,d);
            return rt;
        }

    }
    void DeleteNode(int d){
        root=DeleteNode(root,d);
    }
};


int main(){
    BST T;
    ///T.FillPreOrderInOrder();
    ///T.FillBST();
    T.FillSortedArray();
    T.PrintPreOrder();
    T.PrintInOrder();
    T.PrintPostOrder();
    T.PrintLevelOrder();
    T.DeleteNode(5);
    cout<<"After deletion : "<<endl;
    T.PrintLevelOrder();
    cout<<T.SearchBST(5)<<endl;
    cout<<"isBST:"<<T.isBST()<<endl;
}
