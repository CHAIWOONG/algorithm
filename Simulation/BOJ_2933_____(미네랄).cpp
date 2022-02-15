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

void stkThr(int flag) { // ------------------------------------------------------vector에 저장한 막대기 높이 받아와 던짐

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

void clusterDown() { // ------------------------------------------------------------- 같은 클러스터에서 원소가 같은 거리 만큼 뭉쳐서 중력으로 내려옴

    int dis = 100;
    int visflag = vis[clusterV[0].X][clusterV[0].Y];

    for (int i = 0; i < clusterV.size(); i++) {

        int tmpX = clusterV[i].X;
        int tmpY = clusterV[i].Y;
        int tmpdis;

        if (tmpX == row - 1) { // ----------------------------------------해당 클러스터가 바닥과 닿아있으면 내릴꺼 없이 함수 종료
            clusterV.clear();
            return;
        }

        // 그렇지 않으면 내릴 거리 계산
        int nrow = 1;
        while (1) {

            if ((tmpX + nrow == row)) break; // ------------------------------------------------바닥에 닿으면 증가를 멈춤
            if ((board[tmpX + nrow][tmpY] == 'x' && vis[tmpX + nrow][tmpY] != visflag)) break;
            // ---------------------------------------------------------------미네랄에 닿았는데 그것이 vis로 보았을 때 다른 미네랄이라면 증가를 멈춤
            nrow++;
        }
        
        if (nrow - 1 < dis) dis = nrow - 1; // ----------------------------------------------최소값의 내림 거리 계산
    }
    
    //******** 삭제와 추가를 동시에 진행하면 같은 클러스터에서 같은 열의 다른 행이 존재하는 경우 엉켜서 지워진다. 
    // 삭제 따로 마무리 하고 dis만큼 더하여 한번에 추가하는 방식으로 해야 한다.
    
    for (int i = 0; i < clusterV.size(); i++) { // -----------------------------------******** 이동하기 전에 것은 삭제

        int tmpX = clusterV[i].X;
        int tmpY = clusterV[i].Y;
        
        board[tmpX][tmpY] = '.';
        vis[tmpX][tmpY] = 0;
    }
    
    for (int i = 0; i < clusterV.size(); i++) { //------------------------------------ ********* dis 만큼 이동하여 추가

        int tmpX = clusterV[i].X;
        int tmpY = clusterV[i].Y;
        
        board[tmpX + dis][tmpY] = 'x';
        vis[tmpX + dis][tmpY] = visflag;
    }

    if (!clusterV.empty()) clusterV.clear(); // 완전히 종료되면 해당 cluster의 vector는 clear
    return;
}

void clusterBfs(int& r, int& c) { // ----------------------------------------------- 출발점 받아서 bfs로 같은 클러스터 인지 확인

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
    clustercnt++; // 하나의 bfs에서 클러스터 구분을 위해 증가
}

void clusterCheck() { // --------------------------------------------------- 아래에서부터 (제일 높은 행) bfs를 통해 같은 클러스터 인지 확인

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
    for (int i = 0; i < row; i++) for (int j = 0; j < col; j++)
        cin >> board[i][j];

    cin >> num;
    for (int i = 0; i < num; i++) {
        int x; cin >> x; v.push_back(x);
    }

    for (int j = 0; j < v.size(); j++) {

        stkThr(j); // ----------------------------------------막대기 던짐
        clusterCheck(); // ----------------------------------미네랄 떨어질꺼 떨어지고
        
        for (int i = 0; i < row; i++) for(int j2 = 0; j2 < col; j2++) vis[i][j2] = 0; // vis 초기화
    }
    
    // 출력
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << board[i][j];
        cout << "\n";
    }
    cout << "\n";

    return 0;
}
