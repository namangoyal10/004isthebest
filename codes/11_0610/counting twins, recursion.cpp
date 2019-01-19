#include<iostream>
using namespace std;

int count_twins(char str[], int n){
    if(n<=2) return 0;
    int cnt=0;
    if(str[0]==str[2])
        cnt++;
    return cnt+count_twins(str+1,n-1);
}

int main(){
    char str[100];
    cin.getline(str,100);
    for(int i=0;str[i]!='\0';i++)
    cout<<count_twins(str,i);
}
