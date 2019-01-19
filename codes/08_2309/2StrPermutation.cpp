#include<iostream>
using namespace std;

int main(){
    char str1[]="abcc";
    char str2[]="bacc";

    int cc[26]={};
    int i;
    for (i=0;str1[i]!='\0'&&str2[i]!='\0';i++){
        cc[str1[i]-'a']++;
        cc[str2[i]-'a']--;
    }
    if (str1[i]!='\0'||str2[i]!='\0'){
        cout<<"Not a permutation";
        return 0;
    }
    for (i=0;i<26;i++){
        if (cc[i]!=0){
            cout<<"Not a permutation";
            return 0;
        }
    }
    cout<<"It is a permutation";
}
