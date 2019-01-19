#include <iostream>
#include <cmath>
using namespace std;

void TOW(int arr[],int n, int spos, int team[],int minteam[],
         int &mindiff, int tsum, int team1Size, int team1Sum){
    if (team1Size==n/2){
        int diff=abs(2*team1Sum-tsum);
        if (diff<mindiff){
            mindiff=diff;
            for (int i=0;i<n;i++) minteam[i]=team[i];
        }
        return;
    }
    if (spos>=n) return;
    ///consider spos element in team 1
    team[spos]=1;
    TOW(arr,n,spos+1,team,minteam,mindiff,tsum,team1Size+1,team1Sum+arr[spos]);
    ///DO NOT consider spos element in team 1
    team[spos]=0;
    TOW(arr,n,spos+1,team,minteam,mindiff,tsum,team1Size,team1Sum);

}


int main(){
    int arr[11]={1,2,3,4,5,6,7,8,9,100,10};
    int n=11;
    int team[11]={};
    int minteam[11]={};
    int mindiff=1000000;
    int tsum=0;
    for (int i=0;i<n;i++) tsum+=arr[i];
    TOW (arr,n,0,team,minteam,mindiff,tsum,0,0);
    int sum=0;
    for (int i=0;i<n;i++){
        if (minteam[i]==1) {cout<<arr[i]<<" ";sum+=arr[i];}
    }
    cout<<sum<<endl;
    sum=0;
    for (int i=0;i<n;i++){
        if (minteam[i]!=1) {cout<<arr[i]<<" ";sum+=arr[i];}
    }
    cout<<sum<<endl;
}
