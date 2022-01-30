#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

using namespace std;

int board[1001][1001];
int vis[1001][1001]; 
int dis[1001][1001]; // board의 bfs 시작점에서 거리를 저장할 배열

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int row,col;

void bfs(queue<pair<int,int>>& q) // 함수에서 STL 인자를 받을 때, 참조자로 받아서 복사를 진행하지 않고 원본에 접근할 수 있도록 함 (메모리 고려)
{
    while(!q.empty())
    {
        pair<int,int> temp= q.front(); q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i]; // 상하좌우 탐색
            
            if(nx<0 || nx>=row || ny<0 || ny>=col) continue; // 인접 노드가 주어진 조건의 범위를 초과할 경우 제외
            if(vis[nx][ny] || board[nx][ny] == -1 ) continue; // 이미 방문했거나, 조건에 따라서 방문할 수 없는 노드 제외
            
            vis[nx][ny] = 1;
            dis[nx][ny] = dis[temp.X][temp.Y] + 1; 
            q.push({nx,ny});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>col>>row;
    
    int app_flag = 0;
    int empty_flag = 0;
    queue<pair<int,int>> q;
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) {
            cin>>board[i][j];
            if(board[i][j]==1) { // bfs의 시작 순서가 여러개이므로 판별
                q.push({i,j});
                vis[i][j] = 1;
                dis[i][j] = 1; // 구분을 위해 dis를 1부터 시작
                app_flag++;
            }
            if(board[i][j]==-1) { // -1은 지나갈 수 없으므로 dis 배열에도 -2로 저장
                dis[i][j] = -2;
                empty_flag++;
            }
        }
    }
    
    if(app_flag + empty_flag == row*col) { // 전체를 통틀어서 0이 입력되지 않은 경우는 0출력
        cout<<"0";
        return 0;
    }
    
    bfs(q); // 삽입된 queue를 통해 bfs 실행
    
    int mx = -1; // 최대 값은 -1로 시작
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(dis[i][j] == 0) { // dis에 0이 남아있으면 익지 않은 사과가 존재하는 것
                cout<<"-1";
                return 0;
            }
            mx = max(mx,dis[i][j]); //dis의 최대 값을 계속 업데이트
        }
    }
    
    cout<<mx-1;
    
    
    return 0;
}


