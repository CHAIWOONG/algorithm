#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int n, m,m1, oil;
int board[25][25];
int dis[25][25];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int used[404];

struct INFO // 고객 좌표의 정보
{
    int X;
    int Y;
    int desX;
    int desY;
};

queue<pii> q;
vector<INFO> pV(404); // 고객의 정보 저장 vector

// *****고객의 좌표애서 행,열의 오름 차순으로 최단거리를 가지는 걸 챙기도록 미리 정렬해둠
bool Info_Cmp(INFO A, INFO B) 
{
    if (A.X <= B.X)
    {
        if (A.X == B.X)
        {
            if (A.Y < B.Y)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void disReset(){
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        dis[i][j] = 0;
    }
}

int findShort(){ // 현재 위치에서 최단거리의 사람 index 확인
    
    int mn = 999999999;
    int idx = 500;
    
    for(int i=0; i<=m1; i++){
        
        if(used[i]) continue;
        if(mn> dis[pV[i].X][pV[i].Y] && dis[pV[i].X][pV[i].Y] && i!=0){ 
            mn = dis[pV[i].X][pV[i].Y];
            idx = i;
        }
    }
    oil -= mn-1; // 태워가는데 까지의 oil 제거
    used[idx] = 1; // 최단거리 사람은 사용했으므로 check

    return idx;
}

void bfs(const int& x, const int& y){ // 시작점 받아서 bfs
    
    q.push({x,y});
    
    while(!q.empty()){
        
        pii temp = q.front(); q.pop();
        
        for(int i=0; i<4; i++){
            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];
            
            if(nx<1 || nx>n || ny<1 || ny>n) continue;
            if(board[nx][ny] || dis[nx][ny]) continue;
            
            dis[nx][ny] = dis[temp.X][temp.Y] + 1;
            q.push({nx,ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m>>oil;
    m1 = m;
    
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>board[i][j];
    
    int carX, carY;
    cin>>carX>>carY;
    
    dis[carX][carY] = 1;
    bfs(carX,carY);

    pV[0].X = 25; pV[0].Y = 25;
    pV[0].desX = 25; pV[0].desY = 25;
        
    for(int i=1; i<=m; i++){
        int pX, pY, desX, desY; 
        cin>>pV[i].X>>pV[i].Y>>pV[i].desX>>pV[i].desY;
    }
    
    sort(pV.begin()+1, pV.begin()+m+1, Info_Cmp); // 고객 좌표를 행, 열의 오름차순으로 정렬
    
    int flag = 0;
    while(m--){
        
        int idx = findShort(); // 고객의 최단 거리 확인
        if(oil<0 || idx == 500) {flag = 1; break;} //중간에 oil 다쓰거나 갈 때 없으면 out
        disReset();
        
        dis[pV[idx].X][pV[idx].Y] = 1;
        bfs(pV[idx].X, pV[idx].Y); // 최단 거리 고객을 태운 다음에서 목표지점으로의 거리 확인
        
        if(dis[pV[idx].desX][pV[idx].desY] == 0) {flag = 1; break;} // 중간에 oil 다쓰면 out
        oil -= (dis[pV[idx].desX][pV[idx].desY] -1); 

        if(oil<0) {flag = 1; break;} // 중간에 oil 다쓰면 out
        oil += (dis[pV[idx].desX][pV[idx].desY] -1)*2; // 충전
        disReset();

        dis[pV[idx].desX][pV[idx].desY] = 1;
        bfs(pV[idx].desX,pV[idx].desY); // 최단 거리 고객을 목표지 까지 데려다 준다음 다시 고객의 위치 거리
    }
    
    if(flag) cout<<"-1"<<"\n";
    else cout<<oil;
    
    return 0;
}
