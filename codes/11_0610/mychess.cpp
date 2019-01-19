#include <iostream>
using namespace std;
#define bs 4
int board[bs][bs]={};
int cnt=0;

void PrintBoard(){
    for (int i=0;i<bs;i++){
        for (int j=0;j<bs;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------------"<<endl;
}

void Solve(int tmoves, int x, int y, int moves ){
    board[x][y]=moves;
    if (moves==tmoves){
        if (x==bs-1 && y==bs-1){
            cnt++;
            PrintBoard();
        }
        board[x][y]=0;
        return;
     }
     for (int i=y+1; i<bs; i++){
        Solve (tmoves,x,i,moves+1);
     }
     for (int i=x+1;i<bs;i++){
        Solve(tmoves,i, y, moves+1);
     }
     board[x][y]=0;
}


int main(){
    Solve(3,0,0,0);
    cout<<cnt<<endl;
}

