#include<iostream>
using namespace std;

int Length(char str[]){
    int i;
    for (i=0;str[i]!='\0';i++);
    return i;
}

int main(){
    char str[100];

    cin.getline(str,100);

    cout<<str;
    cout<<Length(str);

    /*cin>>str;
    cout<<str;*/

}
