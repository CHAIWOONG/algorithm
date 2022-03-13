#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii=pair<int,int>;

int n,m,ans=0;
char board[501][501];
int vis[501][501]; 
// 아직 가지 않은 곳=-1, 갔는데 탈출 못하는 지점=0, 갔는데 탈출할 수 있는곳 =1

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int mapcheck(int x, int y){
    
    if(board[x][y]=='U') return 2;
    else if(board[x][y]=='R') return 1;
    else if(board[x][y]=='D') return 0;
    else if(board[x][y]=='L') return 3;
}

int outCheck(int x, int y){ // 범위 넘으면 return 1
    
    if(x<0||x>=n||y<0||y>=m) return 1;
    else return 0;
}

int dfs(int x, int y){ //dp 개념으로 이미 간 지점의 정보를 vis배열에 저장해두고 사용
    
    if(outCheck(x,y)) return 1; // 탈출이 가능한 지점이면 return 1 (base condition)
    if(vis[x][y]!=-1) return vis[x][y]; // 가봤으면 그 값으로 return
    
    vis[x][y]=0; // 처음 온 x,y 아므로, 일단은 0으로 update
    int dirIdx = mapcheck(x,y);
    vis[x][y] = dfs(x+dx[dirIdx], y+dy[dirIdx]); 
    // 해당 x,y에서 가게되는 최종 목적지의 정보로 update
    return vis[x][y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>board[i][j];
    memset(vis,-1,sizeof(vis));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) ans+=dfs(i,j);
    cout<<ans;
    
    return 0;
}
