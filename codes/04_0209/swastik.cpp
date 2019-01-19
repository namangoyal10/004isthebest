#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int hn=(n+1)/2;
    int eqi, eqj;
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (i<=hn) eqi=i; else eqi=n-i+1;
            if (j<=hn) eqj=j; else eqj=n-j+1;
            ///if (i==hn||j==hn||(i==1&&j>hn)) cout<<"* "; else cout<<". ";
            ///if (eqi==eqj) cout<<"* "; else cout<<". ";
            ///if (eqi+eqj<=hn+1) cout<<"* "; else cout<<"  ";
            if (eqi<=eqj) cout<<"* "; else cout<<"  ";
        }
        cout<<endl;
    }
}
