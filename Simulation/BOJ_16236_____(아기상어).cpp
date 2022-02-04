#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int board[21][21];
int dis[21][21];

int n, fishcnt = 0;
int timecnt = 0;
int slevel = 2; // slevel = 상어의 크기
int fishEat = 0;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pii> q;

void fishPos() { // bfs로 거리 먹이의 거리 판단

    while (!q.empty()) {

        pii temp = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {

            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 넘는거 제외
            if (board[nx][ny] > slevel) continue; // 먹이가 자기보다 크면 못감
            if (dis[nx][ny] > 0) continue; // 먹이를 먹기 전까지 갔던 곳은 제외

            q.push({ nx,ny });
            dis[nx][ny] = dis[temp.X][temp.Y] + 1;
        }
    }
}

int sEat() { // board와 dis[][]를 확인하여 다음 먹을 물고기 하나만 체크

    vector<pii> food; // 다음 먹이의 저장 바구니
    int mn = 99999;  // mn의 초기값은 매우 크게.
    int flag = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 0 && board[i][j] < slevel) { // 먹을수 있는 먹이가 있으면,

                if (dis[i][j] < mn && dis[i][j] != 0) { // ****방문한 것 중에 거리가 작은거만 넣음 (거리가 같은거는 왼쪽 위부터 확인되므로 어짜피 안먹음)
                    mn = dis[i][j];
                    if (food.size()) food.pop_back();
                    food.push_back({ i,j });
                    flag = 1;
                }
            }
        }
    }

    // 먹이의 대상을 찾았으면 flag가 1
    if (flag) {
        timecnt += dis[food[0].X][food[0].Y] - 1; // 시간은 거기까지의 dis를 추가하는 방식으로 구현

        q.push({ food[0].X, food[0].Y }); //해당 먹이 위치를 시작점으로 초기화 하여 queue에 push
        fishEat++; // 먹은 개수 체크

        if (fishEat == slevel) { // 먹은 개수가 크기와 같으면 크기 증가
            slevel++; fishEat = 0;
        }

        board[food[0].X][food[0].Y] = 0; // 먹이는 먹었으므로 0 초기화
        fill(&dis[0][0], &dis[n][n], 0); // 거리의 dis 배열 초기화
        dis[food[0].X][food[0].Y] = 1; // dis 배열에다 새로운 시작 위치의 값 1 초기화

        food.pop_back(); // 먹이 바구니 비움
    }

    return flag;
}

void sMove() {

    int flag; // sEat()에서 받아오는 return 값으로 먹을께 없는 경우 판단

    while (1) {
        fishPos(); // 상어의 현재 크기에서 먹이들의 거리 계산
        flag = sEat(); // 계산 거리에 따라서 무엇을 먹을지 판단
        if (flag == 0) return; // 먹을께 없는 경우 flag를 0으로 받으므로 탈출
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 6) fishcnt++; // 먹이 수 체크
            else if (board[i][j] == 9) { //상어 위치 저장

                q.push({ i,j });
                board[i][j] = 0;
                dis[i][j] = 1;
            }
        }
    }

    if (fishcnt == 0) { // 시작 부터 먹을 물고기 없으면 종료
        cout << fishcnt;
        return 0;
    }
    else sMove();  // 먹을 수 있는 먹이가 있을 때,

    cout << timecnt;
    return 0;
}