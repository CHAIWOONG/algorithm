#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int,int>;

// 벽부수기 2,3,4와 비슷한 

int row,col,k;
int board[201][201];
int dis[201][201][31]; // k는 0이상 30이하

int dx[4]={1,0,-1,0}; // 원숭이로써의 움직임
int dy[4]={0,1,0,-1};

int dx2[8]={-2,-1,1,2,2,1,-1,-2}; // horse로써의 움직임
int dy2[8]={-1,-2,-2,-1,1,2,2,1};

queue<pair<pii,int>> q;

int bfs(){ // 어짜피 목표점에서 최솟값에 도달하는것을 찾는 것이므로 도달하면 바로 종료
    
    while(!q.empty()){
        
        pii temp = q.front().first; 
        int num = q.front().second;
        q.pop();
        
        if(temp.X==row-1 && temp.Y==col-1) return dis[temp.X][temp.Y][num]-1;
        
        //원숭이로써의 움직임
        for (int i = 0; i < 4; i++) {

            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];

            if(nx<0 || nx>=row || ny<0 || ny>=col) continue;
            if(board[nx][ny]) continue; // 벽은 못감
            
            if (!dis[nx][ny][num]) { // 이미 방문한 곳이 아닐 때,

                dis[nx][ny][num] = dis[temp.X][temp.Y][num]+1;
                q.push({ {nx,ny},num });
            }
        }
        
        if(num){ // horse 로써의 움직임은 (num=기회)가 남아있을 때만 가능
            
            for (int i = 0; i < 8; i++) {

                int nx = temp.X + dx2[i];
                int ny = temp.Y + dy2[i];
    
                if(nx<0 || nx>=row || ny<0 || ny>=col) continue;
                if(board[nx][ny]) continue; // 벽은 못감
                
                if (!dis[nx][ny][num-1]) { // 현재 기회를 한번 사용하고 나서 방문한 곳이 아닐 때,
                    dis[nx][ny][num-1] = dis[temp.X][temp.Y][num]+1;
                    q.push({ {nx,ny},num-1 }); 
                }
            }
        }
    }
    return -1; // 도착하지 못하면 -1 출력
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>k>>col>>row;
    for(int i=0; i<row; i++) for(int j=0; j<col; j++) cin>>board[i][j];
    
    q.push({ {0,0}, k});
    dis[0][0][k] = 1;
    
    cout<<bfs()<<"\n";
    return 0;
}
