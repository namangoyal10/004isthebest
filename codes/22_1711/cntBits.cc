
#include <iostream>
using namespace std;

int cntBits(int x){
    int cnt = 0;

    while(x != 0){
        int isOne = x & 1;
        if (isOne == 1) ++cnt;
        x = x >> 1;
    }
    return cnt;
}

int fastCntBits(int x){
    int cnt = 0;
    while(x != 0){
        int isSet = x & (-x);
        if (isSet) ++cnt;   // integers are convertible to bool
        ///cout<<x<<" "<<isSet<<endl;
        x = x & (~isSet);
    }
    return cnt;
}

int fastCntBits1(int x){
    int cnt = 0;
    while(x != 0){
        x=x&(x-1);
        ++cnt;   // integers are convertible to bool
        ///cout<<x<<endl;
    }
    return cnt;
}

int main(){
    ///cout<<(1<<4)<<endl;
    int x;
    cin >> x;
    int ans = fastCntBits(x);
    cout << ans;
}
