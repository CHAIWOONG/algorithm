#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int row, col, mn = 99999999, flag = 0;
int dirtcnt;
int Rx, Ry; // 로봇 좌표 저장

int board[21][21];
int dis[21][21];

int used[11]; // 처리된 먼지 저장 (조합 중복 확인을 위해)
int dirtArr[11]; // 먼지 순서 조합 저장

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

vector<pii> dirstV; // 먼지의 좌표 저장
int RtoD[11]; // 로봇과 각 먼지 사이의 거리
int DtoD[11][11]; // 먼지와 먼지 사이의 거리

void BdGet(const char& C, const int& r, const int& c) {

    if (C == '.') board[r][c] = 0;
    else if (C == '*') { board[r][c] = 1; dirstV.push_back({ r,c }); }
    else if (C == 'x') board[r][c] = -1;
    else if (C == 'o') { Rx = r; Ry = c; }; // 로봇 좌표 저장
}

void disReset() {
    for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) {
        dis[i][j] = 0;
    }
}

void BdReset() {

    for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) {
        dis[i][j] = 0; board[i][j] = 0;
    }

    for (int i = 0; i < 11; i++) {
        used[i] = 0; dirtArr[i] = 0;
    }
}

// bfs 시작점과 목표점을 받아서 거리 return
int bfs(const int& sr, const int& sc, const int& er, const int& ec) {

    queue<pii> q; q.push({ sr,sc });
    dis[sr][sc] = 1; // *****dis 시작점 초기화

    while (!q.empty()) {

        pii temp = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if (dis[nx][ny] || board[nx][ny] == -1) continue;

            dis[nx][ny] = dis[temp.X][temp.Y] + 1;
            q.push({ nx,ny });
        }
    }
    return dis[er][ec] - 1;
}

//******방문 순서를 먼저 정한 다음에 bfs를 실행하여 그 때 마다 거리를 구하면 시간초과
// 거리를 먼저 계산한 후, 조합으로 방문할 순서를 정하여 계산하는 것이 훨씬 빠르다

void RouteDesic(int k) { // 로봇 -> 먼지 후 먼지 끼리의 방문 순서 조합 결정

    if (k == dirtcnt) {

        int tmpdis = RtoD[dirtArr[0]]; // 초기 값은 로봇에서 시작한다

        for (int i = 0; i < dirtcnt - 1; i++)
            tmpdis += DtoD[dirtArr[i]][dirtArr[i + 1]];

        if (mn > tmpdis) mn = tmpdis;
        return;
    }
    else {
        for (int i = 0; i < dirtcnt; i++) { // 먼지 끼리 조합 원소 중복 제거
            if (!used[i]) {

                dirtArr[k] = i;
                used[i] = 1;
                RouteDesic(k + 1);
                used[i] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1) {

        cin >> col >> row;
        if (!row && !col) break;

        for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) {
            char c; cin >> c; BdGet(c, i, j);
        }
        dirtcnt = dirstV.size();

        // 로봇과 각 먼지 사이의 거리를 일단 저장
        for (int i = 0; i < dirtcnt; i++) {
            int tmp = bfs(Rx, Ry, dirstV[i].X, dirstV[i].Y);
            if (tmp == -1) { flag = 1; break; } // 갈 수 없으면 바로 종료
            else RtoD[i] = tmp;
            mn += tmp * 2;
            disReset(); // *****dis초기화
        }
        disReset();

        // 각 먼지 끼리의 거리를 저장
        for (int i = 0; i < dirtcnt; i++) {
            for (int j = i + 1; j < dirtcnt; j++) {
                if (!DtoD[i][j] && !DtoD[j][i]) {
                    int tmp = bfs(dirstV[i].X, dirstV[i].Y, dirstV[j].X, dirstV[j].Y);
                    DtoD[i][j] = DtoD[j][i] = tmp;
                    disReset();// *****dis초기화
                }
            }
        }

        // 출력
        if (flag == 1) cout << "-1\n";
        else {

            RouteDesic(0); // 이동 순서 조합 결정
            cout << mn << "\n";
        }

        //*********초기화
        BdReset();
        dirstV.clear();
        mn = 99999999;
        flag = 0;

        for (int i = 0; i < dirtcnt; i++) {
            RtoD[i] = 0;
            for (int j = 0; j < dirtcnt; j++)
                DtoD[i][j] = 0;
        }


    }

    return 0;
}

