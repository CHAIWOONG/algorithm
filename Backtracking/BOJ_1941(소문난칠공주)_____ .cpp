#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second

using namespace std;

int board[26]; // 5*5 �ڸ���ġ�� ���������� �����Ͽ� ���
int selected[8]; // 7�ڸ��� ������ �����ϱ� ���� selected �迭 (��Ʈ��ŷ���� ���)
int used[26]; // �ߺ� ���Ÿ� ���� ���Ǿ����� �Ǵ�

int cnt = 0;

int bfs_board[5][5]; // bfs �� 5*5 �迭
int vis[5][5];       // bfs �� 5*5 visted �迭

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> q; // bfs �� queue

void bfs(queue<pair<int, int>>& q) { // ���� ���� �Ǵ��� ���� bfs

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

int adjacency() {// �ּҰ� ���� ���� ���ҿ� ���̰� 1 or 5������ ���� T ���´� �ľ� �Ұ�
                // bfs�� 1ť�� �������� �Ǵ�?

    int vis_cnt = 0;

    for (int i = 0; i < 7; i++) { // selected ������ �迭�� ���ؼ� 5*5 �迭 ����
        bfs_board[selected[i] / 5][selected[i] % 5] = 1;
        if (i == 0) q.push({ selected[i] / 5,selected[i] % 5 }); // ù��°�� queue�� �߰�
    }

    bfs(q); // ù��° ���Ұ� �߰��� queue�� ���ؼ� bfs ����

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (vis[i][j] == 1) vis_cnt++; // bfs�� 1���� �ؼ� vis= 1�� 7������ �ľ�
            vis[i][j] = 0;
            bfs_board[i][j] = 0; // �迭�� ���������� ���������Ƿ� ���� �ٽ� �ʱ�ȭ
        }
    }

    if (vis_cnt == 7) return 1;
    else return 0;
}

int s_checked() { // 7���� ���� �߿��� [S>=4] �� ������ �����ϴ� �͸� true�� �Ǵ�

    int sflag = 0;

    for (int i = 0; i < 7; i++)
        if (board[selected[i]] == -1) sflag++;

    if (sflag >= 4) return 1;
    else return 0;
}

void func(int k) { // ��Ʈ��ŷ���� 7���� ���� ���� (25���� ĭ�� �� index�� ������)

    if (k == 7) { // 7���� ���� �߿���, [����] , [S>=4] �� ������ �����ϴ� �͸� count

        if (s_checked())
            if (adjacency()) cnt++;
        return;
    }
    else {
        for (int i = 0; i < 25; i++) {
            if (!used[i]) {

                // �̿��̸� ������������ �ؼ� �ִ��� ����
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

        for (int j = 0; j < row.length(); j++) {

            if (row[j] == 'Y') board[5 * i + j] = 1;
            else if (row[j] == 'S') board[5 * i + j] = -1;
        }
    }

    func(0);

    cout << cnt << "\n";

    return 0;
}