#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int,int>;

// row와 col이 1500까지 가능하므로 매번 bfs를 진행하면 시간초과가 일어나게 되므로 버퍼를 만들어서
// 메모이제이션을 진행하도록 구현한다.

// 현재의 얼음을 녹이는 큐와 다음 날에 녹일 얼음을 담아둘 버퍼 큐를 사용

int row,col, cnt=0;
int board[1501][1501];
int vis[1501][1501]; //  백조[1]의 백조[2]로의 이동 가능 체크

queue<pii> meltq;
queue<pii> temp_meltq; // 메모리 감소를 위해 버퍼를 만들어서 하루 마다 진행과정 따로 저장
queue<pii> swanq;
queue<pii> temp_swanq;

vector<pii> swanv;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void queueReset(){ // 버퍼 초기화
    
    while(!temp_meltq.empty()) temp_meltq.pop();
    while(!temp_swanq.empty()) temp_swanq.pop();
}

void bdGet(const char& C, const int& r, const int& c){
    
    if(C == '.') {board[r][c] = 0; meltq.push({r,c}); }
    else if(C == 'X') board[r][c] = 1;
    else if(C == 'L') {
        swanv.push_back({r,c}); // 백조 좌표 vector push
        board[r][c] = 0; 
        meltq.push({r,c}); // 백조도 물위에 있으므로 인접 빙판이 녹아야됨 (?)
    }
}

void melting(){ 
    
    while(!meltq.empty()){
        
        pii temp = meltq.front(); meltq.pop();
        
        for(int i=0; i<4; i++){
            
            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];
            
            if(nx<0 || nx>=row || ny<0 || ny>=col) continue;
            if(!board[nx][ny]) continue;
            
            board[nx][ny] = 0;
            temp_meltq.push({nx,ny}); // 하루에 한칸씩 녹으므로 녹은건 일단 버퍼에만 저장
        }
    }
    cnt++;
}

int swanCheck(){ // 백조의 이동 bfs
    
    while(!swanq.empty()){
        
        pii temp = swanq.front(); swanq.pop();
        
        for(int i=0; i<4; i++){
            
            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];
            
            if(nx<0 || nx>=row || ny<0 || ny>=col) continue;
            if(vis[nx][ny]) continue; // 이미 방문했으면 제외
            if(board[nx][ny]){ // 백조가 인접하여 이동한 곳이 얼음이라면,
                vis[nx][ny] = 1; // 방문했다고 체크하고,
                temp_swanq.push({nx,ny}); // 백조의 버퍼에 이만큼 이동한 것을 저장하고,
                continue; // 그냥 백조의 queue에는 push하지 않고서 진행하여 얼음을 이동하지 못하게 한다
            }
            
            vis[nx][ny] = 1;
            swanq.push({nx,ny});
        }
    }
    
    return vis[swanv[1].X][swanv[1].Y]; // 백조[2] 좌표로 방문이 되었는지 결과 return
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>row>>col;
    for(int i=0; i<row; i++) for(int j=0; j<col; j++){
        char c; cin>>c;
        bdGet(c,i,j);
    }
    
    swanq.push({swanv[0].X, swanv[0].Y}); // 초기 백조[1]의 좌표 저장
    
    while(1){
        
        melting();
        int flag = swanCheck();
        
        if(flag == 1){ // 백조끼리 만날 수 있음
            cout<<cnt;
            return 0;
        } 
        
        // if(flag == 0) 아직 백조끼리 갈 수 없으므로 while문 계속 진행 
        meltq = temp_meltq; //  하루 완료 후 진행 과정이 저장된 버퍼 다시 옮겨서 기억해줌
        swanq = temp_swanq;

        queueReset(); // 버퍼 초기화
    }

    return 0;
}
