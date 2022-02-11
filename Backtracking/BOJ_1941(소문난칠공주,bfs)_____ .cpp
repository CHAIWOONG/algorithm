#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second

using namespace std;

int board[26]; // 5*5 자리배치를 일직선으로 나열하여 사용
int selected[8]; // 7자리의 조합을 저장하기 위한 selected 배열 (백트래킹에서 사용)
int used[26]; // 중복 제거를 위해 사용되었는지 판단

int cnt = 0;

int bfs_board[5][5]; // bfs 용 5*5 배열
int vis[5][5];       // bfs 용 5*5 visted 배열

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> q; // bfs 용 queue

void bfs(queue<pair<int, int>>& q) { // 인접 원소 판단을 위한 bfs

    while (!q.empty()) {

        pair<int, int> temp = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {

            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (vis[nx][ny] || bfs_board[nx][ny] != 1) continue;

            vis[nx][ny] = 1;
            q.push({ nx,ny });
        }
    }
}

int adjacency() {// 최소값 부터 다음 원소와 차이가 1 or 5인지만 보면 T 형태는 파악 불가
                // --> bfs로 1큐에 끝나는지 판단하면 구불거리는 모양도 한번에 판단할 수 있다

    int vis_cnt = 0;

    for (int i = 0; i < 7; i++) { // selected 일직선 배열에 대해서 5*5 배열 생성
        bfs_board[selected[i] / 5][selected[i] % 5] = 1;
        if (i == 0) q.push({ selected[i] / 5,selected[i] % 5 }); // 첫번째는 queue에 추가
    }

    bfs(q); // 첫번째 원소가 추가된 queue에 대해서 bfs 실행

    for (int i = 0; i < 5; i++) { // 조합에 대해서 bfs를 실행한 것에 대해서 bfs_board의 결과를 확인
        for (int j = 0; j < 5; j++) {
            if (vis[i][j] == 1) vis_cnt++; // bfs를 1번만 해서 vis=1의 개수가 7개인지 파악

            vis[i][j] = 0;
            bfs_board[i][j] = 0; // 배열은 전역변수로 선언했으므로 직접 다시 초기화
        }
    }

    if (vis_cnt == 7) return 1;
    else return 0;
}

int s_checked() { // 7개의 조합 중에서 [S>=4] 의 조건을 만족하는 것만 true로 판단

    int sflag = 0;

    for (int i = 0; i < 7; i++)
        if (board[selected[i]] == -1) sflag++;

    if (sflag >= 4) return 1;
    else return 0;
}

void func(int k) { // 백트래킹으로 7개의 조합 구현 (25개의 칸의 각 index로 구성된)

    if (k == 7) { // 7개가 모인 조합 1개에 대해서 각각 [S>=4]조건 만족 후 [인접]의 조건까지 만족하는 조합만 count

        if (s_checked()) 
            if (adjacency()) cnt++;
        return;
    }
    else {
        for (int i = 0; i < 25; i++) {
            if (!used[i]) {

                // 이왕이면 오름차순으로 해서 최대한 줄임
                if (k != 0 && selected[k - 1] > i) continue;
                else selected[k] = i;
                used[i] = 1;
                func(k + 1);
                used[i] = 0;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; i++) {
        string row;
        getline(cin, row);

        for (int j = 0; j < row.length(); j++) {  // 문자열 입력을 "\n" 구분 없이 그대로 받아서 board 에는 index를 계산하여 1,-1로 채워 넣도록 함

            if (row[j] == 'Y') board[5 * i + j] = 1;    
            else if (row[j] == 'S') board[5 * i + j] = -1;
        }
    }

    func(0);

    cout << cnt << "\n";

    return 0;
}