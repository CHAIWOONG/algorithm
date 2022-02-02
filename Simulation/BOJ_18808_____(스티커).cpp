#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int row, col; // 노트북 행,열
int stk; // 스티커 개수

int board[41][41]; // 노트북 모눈종이
int vis[41][41]; // 노트북 모눈종이 visited

int srow, scol; // 스티커 모눈종이의 행,열
int stker[11][11]; // 스티커 모눈종이

//int stkarr[101]; // 스티커 모눈종이 일직선 배열?

int attch(int x, int y) { // 노트북의 (x,y)에서 시작하여 스티커를 붙일 수 있는지 확인 

    //스티커의 크기 만큼만으로 하여 확인

    for (int i = 0; i < srow; i++) {
        for (int j = 0; j < scol; j++)
            if (board[x + i][y + j] == 1 && stker[i][j] == 1) return 0;
    }
    // board(노트북)이 이미 1인데 스티커도 1이면 붙일 수 없으므로 false return

    for (int i = 0; i < srow; i++) {
        for (int j = 0; j < scol; j++)
            if (stker[i][j] == 1) board[x + i][y + j] = 1;
    }
    // false가 return 되었으므로 나머지는 모두 붙일 수 있는 상황만 존재
    // 스티커가 1이면 해당 board의 자리를 1로 update

    return 1;
}

void rotation() {

    int temp[11][11]; // 임시 스티커 변수

    for (int i = 0; i < srow; i++) {
        for (int j = 0; j < scol; j++) {
            temp[i][j] = stker[i][j]; // 임시에 옮기고 초기화
            stker[i][j] = 0;
        }
    }

    for (int i = 0; i < srow; i++) {
        for (int j = 0; j < scol; j++)
            stker[j][srow - 1 - i] = temp[i][j]; //90도 회전
    }

    int tempnum = 0;
    tempnum = scol;
    scol = srow;
    srow = tempnum; // 가로와 세로 swap
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col >> stk;

    while (stk--) {

        cin >> srow >> scol;

        for (int i = 0; i < srow; i++) {
            for (int j = 0; j < scol; j++)
                cin >> stker[i][j];
        }

        for (int r = 0; r < 4; r++) { // 회전의 방향 4개

            int attchflag = 0;

            for (int i = 0; i <= row - srow; i++) {
                if (attchflag) break;
                for (int j = 0; j <= col - scol; j++) {

                    if (attch(i, j)) { // 해당 좌표에서 붙여졌으면 flag 1로 update
                        attchflag = 1;
                        break;
                    }
                }
            }

            if (attchflag) break;
            else rotation(); // 안붙여졌으면 회전해서 시도
        }

        for (int i = 0; i < srow; i++) {
            for (int j = 0; j < scol; j++)
                stker[i][j] = 0; // 스티커 초기화
        }
    }

    int cnt = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cnt += board[i][j];
        }
    } // 스티커 모두 붙인 노트북에서 차있는 칸 count

    cout << cnt;

    return 0;
}