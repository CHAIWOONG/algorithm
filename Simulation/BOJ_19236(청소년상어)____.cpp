#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int,int>;

struct Fish{
    
    int tmpX;
    int tmpY;
    int tmpDir;
};

Fish fish[20]; // 물고기 구조체 크기순 배열
int board[4][4]; // 물고기 위치별 크기
int eaten[20]; // 먹힌 물고기 크기는 1로 저장

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

int ans = 0;

int rangecheck(const int& x, const int& y){
    
    if(x<0 || x>=4 || y<0 || y>=4) return 0; // 범위 넘음
    else return 1;
}

void copyBd(int tmpBd[][4], int origin[][4], Fish tmpf[], Fish ofish[]){ // copy board

    for(int i=0; i<4; i++) for(int j=0; j<4; j++){
        tmpBd[i][j] = origin[i][j];
    }
    
    for (int i = 1; i <=16; i++) tmpf[i] = ofish[i];
}

void stateChange(int x, int y, int desx, int desy, int eat, int flag){
    
    if(flag){ // 상태를 변화 시킴
        board[x][y] = 0; // 상어 있던 자리는 0
        eaten[board[desx][desy]] = 1; // 먹힌 것 표시
        board[desx][desy] = -1; // 상어는 -1
    }
    else{ // 상태를 복귀 시킴
        board[x][y] = -1;
        board[desx][desy] = eat; 
        eaten[board[desx][desy]] = 0;
    }
}

void fishMv(){ // 물고기가 크기순으로 이동하는 함수
    
    for(int i=1; i<=16; i++){
        
        if(eaten[i]) continue; // 물고기가 잡아먹혔으면 건너뜀
        
        int tempX = fish[i].tmpX, tempY = fish[i].tmpY;
        int desX, desY;
        
        while(1){
            
            desX = tempX + dx[(fish[i].tmpDir-1)%8]; // 물고기 목적지
            desY = tempY + dy[(fish[i].tmpDir-1)%8];
            
            if(!rangecheck(desX,desY) || (board[desX][desY]==-1)) {fish[i].tmpDir++;}
            else break;
        }
        
        int dFish = board[desX][desY]; // 목적지에 있는 물고기 크기
        
        // 원래 누가 있었으면 swap
        if(dFish){
            
            fish[dFish].tmpX = tempX; fish[dFish].tmpY = tempY;
            board[fish[i].tmpX][fish[i].tmpY] = dFish;
            
            fish[i].tmpX = desX; fish[i].tmpY = desY;
            board[desX][desY] = i;
        }
        else if(!dFish){ // 아니면(==0)그냥 들어감
            
            board[fish[i].tmpX][fish[i].tmpY] = 0;
            fish[i].tmpX = desX;  fish[i].tmpY = desY;
            board[desX][desY] = i;
        }
    }
}

void sDecis(int x, int y, int dir, int sum){ // 상어 이동범위 결정 backtracking(dfs)
    
    int desX, desY, tempsum;
    int count = 1;
    if(sum > ans) ans = sum;
    
    int tmpBd[4][4]; // 임시의 board 선언으로 이 후 계산 진행
    Fish tmpfish[20];
    
    copyBd(tmpBd, board, tmpfish, fish); // 이동 전에 임시 배열에 복사해둠
    fishMv();
    
    for(int i=1; i<=3; i++){ // 최대 3칸 이동 가능

        desX = x + (dx[(dir-1)%8]*i); // 상어 목적지
        desY = y + (dy[(dir-1)%8]*i);

        if(!rangecheck(desX, desY)) break;
        else{
            
            if(!board[desX][desY]) continue;
        
            int eatf = board[desX][desY];
            int ndir = fish[eatf].tmpDir; // ****상어의 방향 update
            tempsum = sum + eatf;
            
            stateChange(x, y, desX, desY, eatf, 1); // 상어의 위치 상태 변화
            sDecis(desX, desY, ndir, tempsum); //******재귀
            stateChange(x, y, desX, desY, eatf, 0); // 상태 변화 복귀시킴
            
        }
    }
    // 상태 되돌리는 함수
    copyBd(board, tmpBd, fish, tmpfish); // 다시 되돌린다
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for(int i=0; i<4; i++) for(int j=0; j<8; j+=2){ // 물고기의 위치와 방향 저장
        int d;
        cin>>board[i][j/2]>>d;
        fish[board[i][j/2]] = { i, j/2, d };
    }
    
    // 상어는 (0,0)에서 부터 시작
    int sDir = fish[board[0][0]].tmpDir; // 상어의 위치, 방향 update
    
    int firstEat = board[0][0];
    eaten[firstEat] = 1;
    board[0][0] = -1; // 상어는 -1
    
    sDecis(0, 0, sDir, firstEat);

    cout<<ans;
    
    return 0;
}
