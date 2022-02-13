#include <bits/stdc++.h>

using namespace std;

int n, mxW;
int weight[101];
int value[101];
int dp[101][100001];
// dp[i][j] = i개를 확인했을 때, 무게가 j인 경우

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> mxW;
    for (int i = 1; i <= n; i++) cin >> weight[i] >> value[i];

    // 가방에 현재의 물건을 담을 수 있나 없나를 판단해야됨
    // 해당 물건을 담을 수 있어도 담는게 이득인지 아닌지 판단해야됨

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= mxW; k++) {

            // k가 max weight까지 커질 때, 
            // k가 현재 i번째의 무게를 감당할 수 있게 된다면,
            // i-1번쨰에서 k 무게였던 것과, i-1번째에서 [k-현재 짐 무게]의 자리에서 가치합중 최대 값을 선택한다 

            if (k >= weight[i]) dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - weight[i]] + value[i]);
            else dp[i][k] = dp[i - 1][k];
        }
    }

    cout << dp[n][mxW];
    return 0;
}

