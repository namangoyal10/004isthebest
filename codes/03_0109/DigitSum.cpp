#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int cnt,sum;
    for (cnt=0,sum=0;n>0;sum=sum+n%10,cnt=cnt+1,n=n/10);
    cout<<"Sum:"<<sum<<endl;
    cout<<"Count:"<<cnt<<endl;
}
/*
int main(){
    int n; cin>>n;
    int cnt,sum;
    for (cnt=0,sum=0;n>0;n=n/10){
        int d=n%10;
        sum=sum+d;
        cnt=cnt+1;
    }
    cout<<"Sum:"<<sum<<endl;
    cout<<"Count:"<<cnt<<endl;
}
*/

/*
int main(){
    int n; cin>>n;
    int cnt=0,sum=0;
    while (n>0){
        int d=n%10;
        sum=sum+d;
        cnt=cnt+1;
        n=n/10;
    }
    cout<<"Sum:"<<sum<<endl;
    cout<<"Count:"<<cnt<<endl;
}
*/
