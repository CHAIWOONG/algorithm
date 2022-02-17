#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, mxjump;
int sjump[21];
int bjump[21];
int dp[25][2]; // dp[i][j] = i번째 도착했을 때 max jump를 j번 썼을 때의 최소 에너지

// *****max jump를 쓰고 안쓰고의 상태가 바뀌는데 이를 2차원 배열을 통해 나타낼 수 있다. (BOJ 2206 벽부수고 이동하기 1)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n - 1; i++) cin >> sjump[i] >> bjump[i];
    cin >> mxjump;

    for (int i = 1; i <= n; i++) { dp[i][0] = dp[i][1] = 99999999; } // *****일단 매우 큰 값으로 초기화

    dp[1][0] = 0; dp[1][1] = 0; // 1번째는 시작점이므로 에너지의 사용이 둘다 0이다

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < 2; j++) {  // max jump를 j번 썼을 때는 일단 항상 앞으로 sjump, bjump만 사용 한걸로 할당
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + sjump[i]);
            dp[i + 2][j] = min(dp[i + 2][j], dp[i][j] + bjump[i]);
        }
        // j=1에 대해서 max jump를 쓴 상황이므로 이에 대해 i+3에서의 최소 에너지를 비교한다.
        dp[i + 3][1] = min(dp[i + 3][1], dp[i][0] + mxjump);
    }

    cout << min(dp[n][0], dp[n][1]); // j=0,1에 대해서 비교하여 최소 출력

    return 0;
}