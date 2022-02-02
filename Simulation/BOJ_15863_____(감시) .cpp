#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second

using namespace std;

vector<pair<int, int>> v;
vector<int> cntVec;

int row, col;
int board[8][8];
int vis[8][8];
int backArr[8]; // 백트래킹으로 나온 cctv의 종류별 방향 조합 저장 배열

int dx[4] = { 0,-1,0,1 }; // 우, 상, 좌, 하
int dy[4] = { 1,0,-1,0 };

void seeDirect(pair<int, int>& temp, int k) { // cctv에서 오른 방향 확인

    // 우(k=0), 상(k=1), 좌(k=2), 하(k=3)

    queue<pair<int, int>> cctvq; cctvq.push({ temp.X,temp.Y });

    vis[temp.X][temp.Y] = 1;

    while (!cctvq.empty()) {

        pair<int, int> pos = cctvq.front(); cctvq.pop();

        int nx = pos.X + dx[k];
        int ny = pos.Y + dy[k];

        if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
        if (board[nx][ny] == 6) continue;

        vis[nx][ny] = 1;
        cctvq.push({ nx,ny });
    }
}

int cctvGet() {

    int tempcnt = 0;

    for (int i = 0; i < v.size(); i++) {

        pair<int, int> temp = v[i];

        if (board[v[i].X][v[i].Y] == 1) { // 1번 cctv (단방향)
            seeDirect(temp, backArr[i] % 4);
        }
        else if (board[v[i].X][v[i].Y] == 2) { // 2번 cctv (반대 2방향)
            seeDirect(temp, backArr[i] % 4); seeDirect(temp, (backArr[i] + 2) % 4);
        }
        else if (board[v[i].X][v[i].Y] == 3) { // 3번 cctv (수직 2방향)
            seeDirect(temp, backArr[i] % 4); seeDirect(temp, (backArr[i] + 1) % 4);
        }
        else if (board[v[i].X][v[i].Y] == 4) { // 4번 cctv (3방향)
            seeDirect(temp, backArr[i] % 4); seeDirect(temp, (backArr[i] + 1) % 4);
            seeDirect(temp, (backArr[i] + 2) % 4);
        }
        else if (board[v[i].X][v[i].Y] == 5) { // 5번 cctv (4방향) 
            seeDirect(temp, backArr[i] % 4); seeDirect(temp, (backArr[i] + 1) % 4);
            seeDirect(temp, (backArr[i] + 2) % 4); seeDirect(temp, (backArr[i] + 3) % 4);
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!vis[i][j] && board[i][j] != 6) tempcnt++; //vis에서 0 개수 파악

            vis[i][j] = 0; // 각 case에서 vis 초기화
        }
    }

    return tempcnt;
}


// cctv는 [1,3,4는 4방향], [2는 2방향], [5는 1방향]
// cctv의 최대 개수는 8개

void func(vector<pair<int, int>>& v, int k) {// 백트래킹으로 회전 조합??

    // 우(k=0), 상(k=1), 좌(k=2), 하(k=3)
    if (k == v.size()) {

        cntVec.push_back(cctvGet());
        return;
    }
    else {
        for (int i = 0; i < 4; i++) {

            if (board[v[k].X][v[k].Y] == 1) { // 1번 cctv (0,1,2,3)
                backArr[k] = i;
                func(v, k + 1);
            }
            else if (board[v[k].X][v[k].Y] == 2) { // 2번 cctv (0,1)
                if (i == 0 || i == 1) backArr[k] = i;
                else backArr[k] = i - 2;
                func(v, k + 1);
            }
            else if (board[v[k].X][v[k].Y] == 3) { // 3번 cctv (0,1,2,3)
                backArr[k] = i;
                func(v, k + 1);
            }
            else if (board[v[k].X][v[k].Y] == 4) { // 4번 cctv (0,1,2,3)
                backArr[k] = i;
                func(v, k + 1);
            }
            else if (board[v[k].X][v[k].Y] == 5) { // 5번 cctv (0) 
                backArr[k] = 0;
                func(v, k + 1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5) { // cctv는 vector에 좌표 할당
                v.push_back({ i,j });
            }
        }
    }

    func(v, 0);

    sort(cntVec.begin(), cntVec.end()); cout << cntVec[0];

    return 0;
}