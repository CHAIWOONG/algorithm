#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii=pair<int,int>;

int n,m;
int ans=INT_MAX;
char board[21][21];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int outcheck(int r, int c){ // 나가면 return 1
    
    if(r<0||r>=n||c<0||c>=m) return 1;
    else return 0;
}

void backTK(int k, int r1, int c1, int r2, int c2){
    
    if(k==10) return; // 10번까지 오면 실패로 취급
    else{
        for(int i=0; i<4; i++){ // bfs함수 따로 만들어서 일일이 보지말고 하나씩 조건에 맞는것으로 dfs 실행
        
            int nx1=r1+dx[i]; int ny1=c1+dy[i];
            int nx2=r2+dx[i]; int ny2=c2+dy[i];
            
            if(outcheck(nx1,ny1)&&outcheck(nx2,ny2)) continue; // 둘다 나가면 out
            else if(!(outcheck(nx1,ny1))&&(!outcheck(nx2,ny2))){ // 둘다 안나갔을 때
                
                if(board[nx1][ny1]=='#'&&board[nx2][ny2]=='#') continue; // 둘다 벽이면 제외
                if(board[nx1][ny1]=='#') nx1=r1, ny1=c1;
                if(board[nx2][ny2]=='#') nx2=r2, ny2=c2; // 벽과 닿는 곳이면 변화 없음
                
                backTK(k+1, nx1, ny1, nx2, ny2); // 재귀
            }
            else{ // 하나만 나가게 되었을 때, 개수 세서 종료
                ans = min(k+1, ans);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vector<pii> ballv;
    
    cin>>n>>m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++){ 
        cin>>board[i][j];
        if(board[i][j]=='o') ballv.push_back({i,j});
    }
    
    backTK(0,ballv[0].X,ballv[0].Y,ballv[1].X,ballv[1].Y);
    
    if(ans==INT_MAX) cout<<"-1";
    else cout<<ans;
    return 0;
}
