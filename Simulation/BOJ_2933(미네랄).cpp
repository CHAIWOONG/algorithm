#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int row, col, num;
int clustercnt = 1;
char board[102][102];
int vis[102][102];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

vector<int> v; // 막대기 던지는 row, (row-i)로 저장되어있음
vector<pii> clusterV;

void stkThr(int flag) { // vector에 저장한 막대기 높이 받아와 던짐

    if (flag % 2 == 0) { // 왼쪽에서 던짐

        for (int j = 0; j < col; j++) {
            if (board[row - v[flag]][j] == 'x') {
                board[row - v[flag]][j] = '.'; break;
            }
        }
    }
    else if (flag % 2 != 0) { // 오른쪽 에서 던짐

        for (int j = col - 1; j >= 0; j--) {
            if (board[row - v[flag]][j] == 'x') {
                board[row - v[flag]][j] = '.'; break;
            }
        }
    }
}

void clusterDown() {

    int dis = 100;
    int visflag = vis[clusterV[0].X][clusterV[0].Y];

    for (int i = 0; i < clusterV.size(); i++) {

        int tmpX = clusterV[i].X;
        int tmpY = clusterV[i].Y;
        int tmpdis;

        if (tmpX == row - 1) { // 해당 클러스터가 바닥과 닿아있으면 내릴꺼 없이 함수 종료
            clusterV.clear();
            return;
        }

        // 그렇지 않으면 내릴 거리 계산
        int nrow = 1;
        while (1) {

            if ((tmpX + nrow == row)) break; // 바닥에 닿으면 증가를 멈춤
            if ((board[tmpX + nrow][tmpY] == 'x' && vis[tmpX + nrow][tmpY] != visflag)) break;
            // 미네랄에 닿았는데 그것이 vis로 보았을 때 다른 미네랄이라면 증가를 멈춤
            nrow++;
        }
        if (nrow - 1 < dis) dis = nrow - 1;
    }

    for (int i = 0; i < clusterV.size(); i++) {

        int tmpX = clusterV[i].X;
        int tmpY = clusterV[i].Y;

        board[tmpX + dis][tmpY] = 'x';
        board[tmpX][tmpY] = '.';

        vis[tmpX + dis][tmpY] = visflag;
        vis[tmpX][tmpY] = 0;

    }

    if (!clusterV.empty()) clusterV.clear(); // 완전히 종료되면 해당 cluster의 vector는 clear
    return;
}

void clusterBfs(int& r, int& c) { // bfs로 같은 클러스터 인지 확인

    queue<pii> q; q.push({ r,c }); clusterV.push_back({ r,c });
    vis[r][c] = clustercnt;

    while (!q.empty()) {

        pii temp = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {

            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if (board[nx][ny] == '.' || vis[nx][ny] == clustercnt) continue;

            vis[nx][ny] = clustercnt; // 같은 클러스터 끼리 vis에 구분하여 표기
            q.push({ nx,ny });
            clusterV.push_back({ nx,ny });
        }
    }
    clustercnt++;
}

void clusterCheck() {

    for (int i = row - 1; i >= 0; i--) for (int j = 0; j < col; j++) {
        if (board[i][j] == 'x' && !vis[i][j]) {
            clusterBfs(i, j);
            clusterDown(); // vector에 담긴 해당 cluster에 대해서만 바닥으로 내리는 과정 실행
        }
    }
    clustercnt = 1; // 한 term이 끝나면 클러스터 변수 초기화
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> row >> col;
    for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) {
        //char c; cin>>c;
        cin >> board[i][j];
        //BdGet(c,i,j);
    }

    cin >> num;
    for (int i = 0; i < num; i++) {
        int x; cin >> x; v.push_back(x);
    }

    for (int j = 0; j < v.size(); j++) {

        stkThr(j); // 막대기 던짐
        clusterCheck(); // 미네랄 떨어질꺼 떨어지고

        for (int i = 0; i < row; i++) for (int j2 = 0; j2 < col; j2++) vis[i][j2] = 0; // vis 초기화
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << board[i][j];
        cout << "\n";
    }
    cout << "\n";

    return 0;
}

