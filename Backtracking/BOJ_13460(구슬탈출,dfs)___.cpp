#include <bits/stdc++.h>

using namespace std;

int n,m,rx,ry,bx,by,fx,fy;
int ans=INT_MAX;
char board[11][11];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int wallcheck(int r, int c){ // 벽이면 1
    
    if(board[r][c]=='#') return 1;
    else return 0;
}

void dfs(int k, int redR, int redC, int bluR, int bluC){
    
    if(k==11) return; // 10단계 넘어가면 실패로 취급
    if(k>=ans) return; // 이미 최소답 보다 k가 크면 볼필요 없음 (복잡도 최소화)

    for(int i=0; i<4; i++){
    
        int nx1=redR+dx[i]; int ny1=redC+dy[i];
        int nx2=bluR+dx[i]; int ny2=bluC+dy[i];
        int rflag=0, bflag=0;
        int rcnt=1, bcnt=1;
        
        while(1){
            
            if(wallcheck(nx1,ny1)) break;
            if(board[nx1][ny1]=='O'){ rflag=1; break;}
            
            nx1+=dx[i]; ny1+=dy[i];
            rcnt++; // 한 단계에서 공의 이동횟수 count
        }
        nx1-=dx[i]; ny1-=dy[i]; rcnt--;
        
        while(1){
            
            if(wallcheck(nx2,ny2)) break;
            if(board[nx2][ny2]=='O'){ bflag=1; break;}
            
            nx2+=dx[i]; ny2+=dy[i];
            bcnt++; // 한 단계에서 공의 이동횟수 count
        }
        nx2-=dx[i]; ny2-=dy[i]; bcnt--;
        
        // 공이 구멍에 빠지는 경우가 발생하면 종료 조건
        if(bflag) continue; // 파란색이 빠졌으면 해당 과정 제외
        else if(!bflag&&rflag){ans=min(k,ans); continue;} // 빨간색만이면 update후 제외
        
        // 빨간공과 파란공의 최종점이 같은 경우 처리해줘야 됨
        if(nx1==nx2&&ny1==ny2){
            
            if(rcnt>bcnt){ // 빨간공이 더 많이 움직였으면 빨간공이 늦게와서 겹친거임
                nx1-=dx[i]; ny1-=dy[i];
            }
            else{ // 파란공이 더 많이 움직였으면 파란공이 늦게와서 겹친것이므로 하나 빼줌
                nx2-=dx[i]; ny2-=dy[i];
            }
        }
        dfs(k+1, nx1, ny1, nx2, ny2); // 다음 단계로 재귀
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++){ 
        cin>>board[i][j];
        if(board[i][j]=='R') rx=i,ry=j;
        if(board[i][j]=='B') bx=i,by=j;
        if(board[i][j]=='O') fx,i,fy=j;
    }
    
    dfs(1,rx,ry,bx,by);
    
    if(ans==INT_MAX) cout<<"-1";
    else cout<<ans;
    return 0;
}
