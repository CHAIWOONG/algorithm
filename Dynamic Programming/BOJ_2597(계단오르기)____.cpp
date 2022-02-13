#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

// 연속으로 3개의 계단을 오르면 안되는 조건이 있으므로 이를 구현하기 위해 dp 배열을 2차원으로 구성
// 현재 문제를 표현하는 상태(state)를 잘 정의

int dp[301][2]; // dp[i][j] 배열은 i번째 계단을 밟는 상황에서 
                // 지금 밟으면 연속으로 j번의 계단을 밟을 때의 최댓값을 저장하며 이에 따라서 j는 3이상이 될수 없다.

int s[301]; // 각 index의 계단이 가지는 점수
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    dp[1][1] = s[1]; dp[1][2] = 0;
    dp[2][1] = s[2]; dp[2][2] = s[1] + s[2];

    for (int i = 3; i <= n; i++) {

        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + s[i];
        dp[i][2] = dp[i - 1][1] + s[i];

    }
    // dp[i][1]은 현재 i번째 계단을 밟고, 연속 계단은 1이므로 i-1은 밟지 않고 i-2를 밟은 것이다. 이에 따라서 max(dp[i-2][1],dp[i-2][2])로 i-2 계단에서의 최댓값을 받아 자기의 점수 s[i]와 더한다
    // dp[i][2]은 현재 i번째 계단을 밟고, 연속 계단은 2이므로 i-1을 밟은 것이다. 이 때, i-1번째가 연속 2번인 상황을 가져오면 연속으로 3 계단을 밟는 것이므로 이를 제외하고 dp[i-1][1]만 받아서 자기의 점수 s[i]와 더한다

    cout << max(dp[n][1], dp[n][2]);


    return 0;
}
