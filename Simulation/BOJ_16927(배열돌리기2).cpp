#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

// 배열의 가장자리를 한칸씩 돌리고 안으로 점점 들어가면서 마찬가지의 방향으로 한칸씩 돌림 (소용돌이)
// 대각선으로 마주보는 꼭짓점을 두개 선정하여 가에서부터 돌린 후, 꼭짓점을 안으로 조여 들어가며 선택하며 반복한다.

using namespace std;

int row,col,rot;
int board[301][301];
int temp[301][301];

void rotate(int x1, int y1, int x2, int y2){ // (0,0), (row,col) 선택 꼭짓점에 대해서 한칸씩 회전 시킴
    
    int tmp = board[x1][y1];
    
    for(int i=y1; i<y2; i++) board[x1][i] = board[x1][i+1];
    for(int i=x1; i<x2; i++) board[i][y2] = board[i+1][y2];
    for(int i=y2; i>y1; i--) board[x2][i] = board[x2][i-1];
    for(int i=x2; i>x1; i--) board[i][y1] = board[i-1][y1];
    
    board[x1+1][y1] = tmp;
    
}

void rotScale(int rot){ // 꼭짓점 선택
    int x1 = 0; int y1 = 0; int x2 = row-1; int y2 = col-1;
    for(; x1 < x2 && y1 < y2; x1++, y1++, x2--, y2--){ 
        
        int t = rot%(2*(x2-x1+y2-y1));
        while(t--) rotate(x1, y1, x2, y2);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>row>>col>>rot;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>board[i][j];
            //temp[i][j] = board[i][j];
        }
    }
    
    rotScale(rot);
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cout<<board[i][j]<<" ";
        cout<<"\n";
    }
    
    return 0;
}
