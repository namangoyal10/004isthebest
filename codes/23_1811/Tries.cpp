#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
private:
    char data;
    bool isTerminal;
    unordered_map<char,TrieNode*> childmap;
public:
    TrieNode(char ch){
        data=ch;
        isTerminal=false;
    }
    friend class Tries;
};

class Tries{
private:
    TrieNode *root;
    void AddWord(char * word, TrieNode *rt){
        if (word[0]=='\0'){
            rt->isTerminal=true;
            return;
        }
        char ch=word[0];
        TrieNode *cn;
        auto it=rt->childmap.find(ch);
        if(it==rt->childmap.end()){
            cn=new TrieNode(ch);
            rt->childmap[ch]=cn;
        } else cn=it->second;
        AddWord(word+1,cn);

    }
public:
    Tries(){
        root= new TrieNode('/0');
    }
    void AddWord(char * word){
        AddWord(word,root);
    }
    bool Search(char * word){
        TrieNode *t=root;

        for (int i=0;word[i]!='\0';i++){
            auto it=t->childmap.find(word[i]);
            if (it==t->childmap.end()){
                return false;
            }
            t=it->second;
        }
        return t->isTerminal;
    }
};

int main(){
    Tries T;
    T.AddWord("but");
    T.AddWord("cut");
    T.AddWord("cute");
    T.AddWord("cry");
    T.AddWord("bat");
    T.AddWord("crow");

    cout<<T.Search("cry")<<endl;
    cout<<T.Search("cut")<<endl;
    cout<<T.Search("cute")<<endl;
    cout<<T.Search("cu")<<endl;
    cout<<T.Search("rest")<<endl;

}
