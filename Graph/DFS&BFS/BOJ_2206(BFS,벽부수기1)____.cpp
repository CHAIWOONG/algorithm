#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int row, col, ocnt = 0;
int board[1001][1001];
int dis[1001][1001][2]; // *******벽을 뚫고 온 경로와 그렇지 않은 경로를 구분시켜 줘야 한다

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<pii, int>> q;

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

        if (temp.X == row - 1 && temp.Y == col - 1) {
            return dis[temp.X][temp.Y][block];
        }

        for (int i = 0; i < 4; i++) {

            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

            // 목적지가 벽이고, 아직 뚫지 않았을 때,
            if (board[nx][ny] && block) {
                dis[nx][ny][block - 1] = dis[temp.X][temp.Y][block] + 1;
                q.push({ {nx,ny},block - 1 });
            }

            // 목적지가 갈 수 있는 곳이고 아직 방문하지 않았을 때,
            if (!board[nx][ny] && !dis[nx][ny][block]) {

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