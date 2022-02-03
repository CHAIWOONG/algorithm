#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

// ------------------------------------------------------ bfs의 시작점이 여러개인 경우 ----------------------------------------------------------------------

using namespace std;

int row,col,height;

int board[101][101][101]; // height*row*col (실제 board)
int dis[101][101][101]; // board의 bfs 시작점에서 거리를 저장할 배열
// int vis가 존재하여 1,0으로 구분할 수도 있다

queue<tuple<int,int,int>> q;

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

void bfs(queue<tuple<int,int,int>> &q){ // 함수에서 STL 인자를 받을 때, 참조자로 받아서 복사를 진행하지 않고 원본에 접근할
    
    while(!q.empty()){
        
        tuple<int,int,int>temp = q.front(); q.pop();
        
        for(int i=0; i<6; i++){

            int tmpz = get<0>(temp);
            int tmpx = get<1>(temp);
            int tmpy = get<2>(temp); 
            
            int nx = tmpx + dx[i];
            int ny = tmpy + dy[i];
            int nz = tmpz + dz[i]; // for문 1번에서 상,하,좌,우, 위, 아래 한번 씩 탐색
            
            if(nx<0 || nx>=row || ny<0 || ny>=col || nz<0 || nz>=height) continue; // 인접 노드가 주어진 조건의 범위를 초과할 경우 제외
            if(dis[nz][nx][ny]>0 || board[nz][nx][ny] == -1) continue; // 이미 방문했거나, 조건에 따라서 방문할 수 없는 노드 제외
            
            //  vis[nz][nx][ny] = 1 존재할 경우, (*******queue에 넣을 때,) 해당 노드를 받문했다는 표시를 남긴다
            dis[nz][nx][ny] = dis[tmpz][tmpx][tmpy] + 1;
            q.push({nz,nx,ny}); // queue에 넣는다.
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>col>>row>>height;
    
    int h_idx = 0;
    int app_flag =0;
    int empty_flag=0;
    int height2 = height;
    
    while(height2--){
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin>>board[h_idx][i][j];
                if(board[h_idx][i][j] == 1) { // bfs의 시작 순서가 여러개이므로 판별
                    q.push({h_idx,i,j});
                    dis[h_idx][i][j] = 1; // 구분을 위해 dis를 1부터 시작 // (vis[i][j] = 1; 존재할 경우) 시작 노드를 방문처리 하는것을 잊지 않는다.
                    app_flag++;
                }
                if(board[h_idx][i][j] == -1){ // -1은 지나갈 수 없으므로 dis 배열에도 -2로 저장
                    dis[h_idx][i][j] = -1;
                    empty_flag++;
                }
            }
        }
        h_idx++;
    }
    
    if(app_flag + empty_flag == row*col) { // 전체를 통틀어서 0이 입력되지 않은 경우는 0출력
        cout<<"0";
        return 0;
    }
    
    bfs(q); 
    
    int mx = -1; // 최대 값은 -1로 시작
    
    for(int h=0; h<height; h++){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(dis[h][i][j] == 0) { // 이중 for문을 통해 확인 결과, dis에 0이 남아있으면 익지 않은 사과가 존재하는 것
                cout<<"-1";
                return 0;
                }
                mx = max(mx,dis[h][i][j]); //dis의 최대 값을 계속 업데이트
            }
        }
    }
    
    cout<<mx-1<<"\n";
    
}
