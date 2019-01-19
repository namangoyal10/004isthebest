#include <iostream>
using namespace std;
int arr[4]={2,4,7,8};
int cc=4;

int MinCoin(int cur){
    if (cur==0) return 0;
    int minreq=10000;
    for (int i=0;i<cc;i++){
        if (arr[i]<=cur) {
            int req=MinCoin(cur-arr[i]);
            if (req+1<minreq) minreq=req+1;
        }
    }
    return minreq;

}

int main(){
    cout<<MinCoin(14);
}
