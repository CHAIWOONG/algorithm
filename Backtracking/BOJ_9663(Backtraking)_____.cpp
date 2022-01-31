#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, cnt = 0;
//int arr[16]; //출력할 것이 없으므로 필요 없음

// ---------------행 k에 대하여 다음 행에서의 판단 배열 ------------------------
int checked1[50]; // 열이 같은 것에 대해 true/false (i(열) 확인)
int checked2[50]; // 오른쪽 대각선 확인하여 true/false ( [i(열)+ k(행)] 확인)
int checked3[50]; // 왼쪽 대각선 확인하여 true/false 
                  // (index 범위 고려하여 [n-i(열)-k(행) -1] 확인)

void func(int k)
{
    if (k == n) {
        cnt++;
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            // 이미 true로 체크된 자리는 둘수 없으므로 제외
            if (checked1[i] || checked2[k + i] || checked3[n - i + k - 1]) continue;

            checked1[i] = 1;
            checked2[k + i] = 1;
            checked3[n - i + k - 1] = 1;
            func(k + 1);
            checked1[i] = 0;
            checked2[k + i] = 0;
            checked3[n - i + k - 1] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    func(0);
    cout << cnt;

    return 0;
}