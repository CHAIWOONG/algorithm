#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#define X first
#define Y second

using namespace std;

int n; // n*n board의 행,열
int mx = 0; // 최종적인 최대 블록의 저장

int board1[21][21];
int board2[21][21];
int arr[6]; // 5번동안 움직임 방향에 대한 조합의 저장

void rotation() { // 90도 회전

    int tmp[21][21];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            tmp[i][j] = board2[i][j]; // 회전해도 원본 유지를 위해 임시 배열 할당
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board2[j][n - 1 - i] = tmp[i][j]; // 90도 회전한 만큼 원본에 새롭게 할당
        }
    }
}

int moving() { // 좌로 미는 것만 구현하고 나머지 방향은 rotation하여 좌로 만들어 사용 (******* 문제를 간단하게 만들기)

    int tempmx = 0;
    //---------------------------------------- 판을 움직여서 계산하는 부분 --------------------------------------------
    
    for (int i = 0; i < n; i++) { // 하나의 행에 대해서 따로 처리 (******* 문제를 나눠서 풀기 + 규칙을 찾기(행끼리 연산됨은 자명함))

        int tmp[21] = { 0, }; // 행에 대해서 계산을 임시로 저장할 일직선 배열
        int idx = 0;

        for (int j = 0; j < n; j++) {

            if (board2[i][j] == 0) continue; // 실제 board의 값이 0이면 무시

            if (tmp[idx] == 0)                     // <tmp가 0이면> 그냥 바로 board의 값에서 tmp 배열에 저장
                tmp[idx] = board2[i][j];
            else if (tmp[idx] != 0) {              // <tmp에 저장된 값이 존재 할 때>
                if (tmp[idx] == board2[i][j]) {    // <tmp 저장값이 현재의 값과 같으면> 한번 더하고 더이상 계산 못하도록 index 증가시킴
                    tmp[idx] += board2[i][j]; 
                    idx++;                           
                }
                else tmp[++idx] += board2[i][j];  // <tmp 저장값이 현재의 값과 다르면> 기존 idx 다음의 index 칸에 board의 값을 추가하여 쌓음
            }
        }
        for (int j = 0; j < n; j++)         // 각 행의 처리에 대해 원래 board2에 삽입
            board2[i][j] = tmp[j];
    }
    
    //----------------------------------------최대 블록 찾는 부분--------------------------------------------
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (board2[i][j] > tempmx) tempmx = board2[i][j];
    }
    return tempmx; // board2에서 최대 블록 저장해서 return
}

void moveDics(int k) { // 5번의 이동에서 방향의 조합을 백트래킹으로 구함

    if (k == 5) { // 1개의 5번 회전 방향 조합이 완성되었을 때,

        int temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                board2[i][j] = board1[i][j];  // 원본은 같은걸 재사용해야하니 복사해둠
        }

        for (int i = 0; i < 5; i++) {

            int rotcnt = arr[i] - 1; // 좌(k=1), 하(k=2), 우(k=3), 상(k=4)
                                     // 좌(0회전), 하(1회전), 우(2회전), 상(3회전)
            while (rotcnt--) rotation();
            temp = moving();         // 다시 회전을 되돌리지 않아도 조합에서 전부 다른 방향으로 처리 될것이므로 되돌리지 
        }

        if (mx < temp) mx = temp; // 한번의 시도에서 받아온 최대 블록 temp가 기존보다 크면 update
        return;
    }
    else {
        for (int i = 1; i <= 4; i++) { // 중복 제거 필요X, 오름차순 필요 X
            arr[k] = i;
            moveDics(k + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> board1[i][j];
    }

    moveDics(0);
    cout << mx;

    return 0;
}
