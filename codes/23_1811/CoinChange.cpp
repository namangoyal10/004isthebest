#include <iostream>
using namespace std;
int arr[4]={2,4,7,8};
int cc=4;
int memo[1000];

int MinCoin(int cur){
    if (cur==0) return 0;
    if (memo[cur]!=-1) return memo[cur];
    int minreq=10000;
    for (int i=0;i<cc;i++){
        if (arr[i]<=cur) {
            int req=MinCoin(cur-arr[i]);
            if (req+1<minreq) minreq=req+1;
        }
    }
    memo[cur]=minreq;
    return minreq;

}

int main(){
    for (int i=0;i<1000;i++){
        memo[i]=-1;
    }
    cout<<MinCoin(800);
}
