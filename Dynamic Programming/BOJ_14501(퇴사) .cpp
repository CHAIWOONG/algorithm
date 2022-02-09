#include <bits/stdc++.h>
#define day first
#define money second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll dp[16]; // dp[i] : i일 째에 최대금액
int n;
vector<pii> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    v.push_back({ 0,0 });

    for (int i = 1; i <= n; i++) {
        int t, plus; cin >> t >> plus;
        v.push_back({ t,plus });
    }
    v.push_back({ 0,0 });

    for (int i = 1; i <= n; i++) {

        int en = i + v[i].day; //  해당 index에서의 상담 종료일
        dp[en] = max(dp[en], dp[i] + v[i].money); // 이미 채워진 값과 새로 채울 값에서 중 큰 것으로 저장
        dp[i + 1] = max(dp[i + 1], dp[i]);
        // ***i일을 포함하지 않는 경우, 그 다음 일을 정할 수 있는 날은 i+1일이므로,
    }

    int mx = dp[1];
    for (int i = 1; i <= n + 1; i++) if (mx < dp[i]) mx = dp[i];

    cout << mx;

    return 0;
}