#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class hashNode{
private:
    int data;
    string key;
    hashNode * next;
public:
    hashNode(int d, string k){
        data=d;
        key=k;
        next=NULL;
    }
friend class hashtable;
};

class hashtable{
private:
    hashNode ** buckets;   /// pointer to array of hashnodes
    int tbSize;
    int curSize;
    int myhash(string k){
        int mh=0,pv,rightpos;
        int l=k.length();                  /// naman=5
        char ch;
        for (int i=0;i<l;i++){
            ch=k[i];
            rightpos=l-i+1;
            pv=int(pow(37,rightpos))%tbSize;
            mh+=ch*pv;
            mh%=tbSize;
        }
        return mh%tbSize;
    }
    void Rehash(){
        ///int oldSize=curSize;
        cout<<"rehashing"<<endl;
        hashNode ** ob=buckets;
        int oldTBSize=tbSize;

        curSize=0;
        tbSize*=2;
        buckets=new hashNode*[tbSize];
        for (int i=0;i<tbSize;i++) buckets[i]=NULL;
        for (int i=0;i<oldTBSize;i++){
            hashNode *t =ob[i];
            while (t!=NULL){
                Add(t->key,t->data);
                t=t->next;
            }
        }
        ///Release all memories here
    }
public:
    hashtable( int s=7){
        tbSize=s;
        curSize=0;
        buckets=new hashNode*[tbSize];
        for (int i=0;i<tbSize;i++) buckets[i]=NULL;
    }
    void Add(string k, int d){
        int pos=myhash(k);
        hashNode *hn= new hashNode(d,k);
        hn->next=buckets[pos];
        buckets[pos]=hn;
        curSize++;
        float ff=(float)curSize/tbSize;
        if (ff>0.7){
            Rehash();
        }
    }
    int Search(string k){
        int pos=myhash(k);
        hashNode *t=buckets[pos];
        while (t!=NULL){
            if (t->key==k) return t->data;
            t=t->next;
        }
        return -1;
    }
};

int main(){
    hashtable ht(3);
    ht.Add("Rajesh",85888);
    ht.Add("Ravi",98730);
    ht.Add("Ramesh",12345);
    ht.Add("Suresh",45678);
    cout<<ht.Search("Ravi")<<endl;
    cout<<ht.Search("NahiPata")<<endl;
}
