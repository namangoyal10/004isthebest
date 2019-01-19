#include<iostream>
using namespace std;

void SpiralPrint(int arr[][3],int m, int n){
    int rs=0,re=m-1,cs=0,ce=n-1;
    while (rs<=re && cs<=ce){
        for (int i=cs;i<=ce;i++) cout<<arr[rs][i]<<" ";
        rs++;
        for (int i=rs;i<=re;i++) cout<<arr[i][ce]<<" ";
        ce--;
        if (rs>re || cs>ce) break;
        for (int i=ce;i>=cs;i--) cout<<arr[re][i]<<" ";
        re--;
        for (int i=re;i>=rs;i--) cout<<arr[i][cs]<<" ";
        cs++;
    }

}

void WavePrint(int arr[][3],int m, int n){
    int inc=1;int r=0;
    for (int c=0;c<n;c++){
         for (int j=0;j<m;j++){
            cout<<arr[r][c]<<" ";
            r+=inc;
        }
        r-=inc;inc=-inc;
    }
}
void WavePrint1(int arr[][3],int m, int n){
    for (int c=0;c<n;c++){
        if (c%2==0) {
            for (int r=0;r<m;r++){
                cout<<arr[r][c]<<" ";
            }
        } else {
            for (int r=m-1;r>=0;r--){
                cout<<arr[r][c]<<" ";
            }

        }
    }
}

int main(){
    int arr[4][3]={{1,2,3},
                 {4,5,6},
                 {7,8,9},
                 {10,11,12}};

    SpiralPrint (arr,4,3);
    /*
    int arr[3][4]={{1,2,3,10},
                 {4,5,6,11},
                 {7,8,9,12}};

    SpiralPrint (arr,3,4);
    */
}
