#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int row, col, ocnt = 0;
int board[1001][1001];
int dis[1001][1001][2]; // ******** 벽을 뚫고 온 경로와 그렇지 않은 경로를 구분시켜 줘야 한다 (상태가 분화되므로 이를 차원을 늘려서 구현)

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<pii, int>> q;  // int block = 1이면 아직 벽돌은 꺤적이 없는 것이다

/*void crash(int r, int c){

    if( r+1<row )board[r+1][c] = 0;
    if( r-1>=0 )board[r-1][c] = 0;
    if( c+1<col )board[r][c+1] = 0;
    if( c-1>=0 )board[r][c-1] = 0;

}*/

int bfs() {

    while (!q.empty()) {

        pii temp = q.front().first;
        int block = q.front().second;
        q.pop();

        if (temp.X == row - 1 && temp.Y == col - 1) { // 현재의 값이 목적지의 좌표이면 return
            return dis[temp.X][temp.Y][block];
        }

        for (int i = 0; i < 4; i++) {

            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
 
            if (board[nx][ny] && block) {  // -------------- 목적지가 벽이고, 아직 벽돌을 뚫지 않아봤을 때
                dis[nx][ny][block - 1] = dis[temp.X][temp.Y][block] + 1;
                q.push({ {nx,ny},block - 1 }); // block은 -1 감소시킨 채로 queue에 넣는다
            }
            // if (board[nx][ny] && block && !dis[nx][ny][block-1]) ---- 깰 수 있는 벽돌이 여러개라면 깼을 때의 해당 위치가 방문한 적이 있는지도 확인해야 한다
            
            if (!board[nx][ny] && !dis[nx][ny][block]) { // -----목적지가 갈 수 있는 곳이고 아직 방문하지 않았을 때,

                dis[nx][ny][block] = dis[temp.X][temp.Y][block] + 1;
                q.push({ {nx,ny},block });
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> row >> col;

    for (int i = 0; i < row; i++) {

        string str; cin >> str;
        for (int j = 0; j < str.length(); j++) {
            board[i][j] = str[j] - '0';
        }
    }

    q.push({ {0,0},1 });
    dis[0][0][1] = 1;

    cout << bfs();

    return 0;
}
