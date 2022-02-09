#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll mndiff;
ll a[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> mndiff;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    // 첫번째로 i가 증가함에 따라 a[j] - a[i]가 m 이상이 되는 최초의 지점 j 또한 증가
    // 두번째로 각 i에 대해 a[j] - a[i]가 m 이상이 되는 최초의 지점 j를 찾은 이후에는 a[j+1], a[j+2], …을 확인할 필요가 없다

    int en = 0;
    ll tmpdiff = 0, mn = 2000000001;

    for (int st = 0; st < n; st++) { // 하나의 pase에서 st는 n전까지 증가

        // 차이가 작을 때, en이 n을 넘지 않는 범위에서 en을 증가시킴
        while (en < n && a[en] - a[st] < mndiff) en++;
        if (en == n) break; // 증가한 en이 n과 같아져 버리면 종료
        mn = min(mn, a[en] - a[st]); // 최소의 차이를 구해야 하므로 갱신
    }

    cout << mn;
    return 0;
}