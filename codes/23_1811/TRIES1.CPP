#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
private:
    char data;
    bool isTerminal;
    unordered_map <char, TrieNode*> childmap;
public:
    TrieNode(char ch){
        data=ch;
        isTerminal=false;
    }
    friend class Tries;
};

class Tries{
private:
    TrieNode* root;
public:
    Tries(){
        root=new TrieNode('\0');
    }
    void addWord(char *word){
        TrieNode *t=root;
        for (int i=0;word[i]!='\0';i++){
            auto it=t->childmap.find(word[i]);
            if (it==t->childmap.end()){
                TrieNode* cNode=new TrieNode(word[i]);
                t->childmap[word[i]]=cNode;
                t=cNode;
            } else {
                t=t->childmap[word[i]];
            }
        }
        t->isTerminal=true;
    }
    bool SearchWord(char *word){
        TrieNode *t=root;
        for (int i=0;word[i]!='\0';i++){
            auto it=t->childmap.find(word[i]);
            if (it==t->childmap.end()){
                return false;
            } else {
                t=t->childmap[word[i]];
            }
        }
        return t->isTerminal;
    }
};

int main(){
    Tries T;
    T.addWord("Cat");
    T.addWord("Cry");
    T.addWord("Try");
    T.addWord("Took");
    cout<<T.SearchWord("Cat")<<endl;
    cout<<T.SearchWord("Too")<<endl;
    cout<<T.SearchWord("What")<<endl;

}
