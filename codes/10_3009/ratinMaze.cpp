#include <iostream>
using namespace std;
#define M 4
#define N 5
char Maze[4][5]={{'N','N','N','X','N'},
                 {'N','X','N','N','N'},
                 {'N','N','X','N','X'},
                 {'N','N','N','N','N'}};

void PrintMaze(){
    for(int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cout<<Maze[i][j];
        }
        cout<<endl;
    }
    cout<<"--------------"<<endl;
}
void RatInMaze(int x, int y, int &cnt){
    Maze[x][y]='@';
    if (x==M-1 && y==N-1){
        PrintMaze();
        cnt++;
        return;
    }
    ///right move
    if (y+1<N && Maze[x][y+1]!='X'){
        RatInMaze(x,y+1,cnt);
    }
    ///Bottom move
    if (x+1<M && Maze[x+1][y]!='X'){
        RatInMaze(x+1,y,cnt);
    }
    Maze[x][y]='N';
}


int main(){
    int cnt=0;
    RatInMaze(0,0,cnt);
    cout<<cnt;
}
