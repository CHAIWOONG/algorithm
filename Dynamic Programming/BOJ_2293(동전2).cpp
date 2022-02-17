#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
int dp[10001]; // dp[i] = i원을 만들 수 있는 가짓수
int c[101]; // 동전의 집합

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 1; i <= k; i++) // ***각 배열을 불가능한 최댓값으로 일단 채워 넣음
        dp[i] = 10001;

    // ****배낭 챙기기와 비슷하게 구현
    for (int i = 1; i <= n; i++) {
        for (int j = c[i]; j <= k; j++) {   // j=c[i],.....c[i+1].....k까지 돌게 돌게 되며 i역시 증가
            dp[j] = min(dp[j], dp[j - c[i]] + 1);
        }
    }

    if (dp[k] == 10001)cout << -1;
    else cout << dp[k];

    return 0;
}