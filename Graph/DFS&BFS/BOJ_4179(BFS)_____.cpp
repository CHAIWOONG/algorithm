#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

using namespace std;

//int board[1001][1001]; board를 두어 입력에서 바로 체크 한후 확인할 수 있으나 해당 문제는 생략
int man_dis[1001][1001];
int fire_dis[1001][1001]; // 불이 퍼지는 것에 대한 distance 배열
// int vis[1001][1001]; // 방문한 자리에 대해서 1로 체크하여 구분하기 위한 단순 vis 배열은 dis로 대체

int dx[4] = {1,0,-1,0}; 
int dy[4] = {0,1,0,-1}; // x,y 좌표에 대해서 index별로 상,하,좌,우 구현

int row,col; // board의 행과 열의 전역변수 

void fire_bfs(queue<pair<int,int>>& q) // 불에 대한 bfs (일반적 bfs)
{
    while(!q.empty())
    {
        pair<int,int> temp = q.front(); q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i]; // queue에서 빼왔을 때 인접 노드의 체크
            
            if(nx<0 || nx>=row || ny<0 || ny>=col) continue; // 경계선을 넘는 경우 제외
            if(fire_dis[nx][ny]>=0 || fire_dis[nx][ny]== -2) continue; // 조건에 따라 벽을 제외하고 이미 방문한 노드도 제외
            
            q.push({nx,ny}); 
            fire_dis[nx][ny] = fire_dis[temp.X][temp.Y]+1; // dis 배열의 특성에 맞춰 현재 temp좌표 (queue의 top)의 값에서 1 더한 채로 업데이트하여  
        }
    }
}

void bfs(queue<pair<int,int>>& q) 
{
    while(!q.empty())
    {
        pair<int,int> temp = q.front(); q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];
            
            if(nx<0 || nx>=row || ny<0 || ny>=col) // 범위를 벗어났으므로 성공
            {
                cout<< man_dis[temp.X][temp.Y]+1;
                return;
            }
            if(man_dis[nx][ny] >=0 || man_dis[nx][ny] ==-2) continue; // 벽(-2),이미 간곳(>=0) 제외
            if(fire_dis[nx][ny] != -1 && fire_dis[nx][ny] <= man_dis[temp.X][temp.Y]+1) 
                continue; 
            // 불의 이동 계산 (불이 -1인 자리 중에서)
            // 자신이 도착한 시간과 동시에 불이 도착하거나, 자신이 불보다 늦게 도착하는 경우
            
            q.push({nx,ny});
            man_dis[nx][ny] = man_dis[temp.X][temp.Y] +1;
        }
    }
    cout<< "IMPOSSIBLE"; // 빠져나가지 못하고 마지막 까지 왔으면 실패
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>row>>col; cin.ignore();
    queue<pair<int, int>> manq; // 지훈이에 대한 bfs를 위한 queue
    queue<pair<int, int>> fireq; // 불에 대한 bfs를 위한 queue
    
    for(int i = 0; i < row; i++){
        fill(man_dis[i], man_dis[i]+col, -1);
        fill(fire_dis[i], fire_dis[i]+col, -1);    
    }
    
    for(int i=0; i<row; i++){
        string str; getline(cin,str);
        for(int j=0; j<str.length(); j++)
        {
            if(str[j] == '#'){
                man_dis[i][j] = -2;
                fire_dis[i][j] = -2;
            }
            if(str[j] == 'J'){ 
                manq.push({i,j});
                man_dis[i][j] = 0;
            }
            if(str[j] == 'F') {
                fireq.push({i,j});
                fire_dis[i][j] = 0;
            }
        }
    }
    
    fire_bfs(fireq); // 불의 전파에 대해 먼저 bfs 실행
    bfs(manq); // 지훈의 이동에 대해 bfs 실행
    
    return 0;
}


