#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int num;
ll mnsum;
ll a[100001];

// 문제에서 요구하는 상황을 정확하게 파악할 필요가 있다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> num >> mnsum;

    for (int i = 0; i < num; i++)
        cin >> a[i];

    //sort(a, a + num);

    int en = 0;
    int mnlen = num;
    ll tmpsum = 0;

    // 먼저 최소 시작 인덱스에 대해서 부분합을 만족하는 종료 인덱스를 구하면, (길이를 일단 매우 벌려봄)
    // 시작 인덱스가 증가하게 될 경우, 종료 인덱스는 같거나 하나씩 증가한다 (추후에 줄여나갈 수 있을 것)
    for (int st = 0; st < num; st++) {

        while (en < num && tmpsum < mnsum) { // 부분합 조건이 만족되면 빠져 나감
            en++;
            if (en != num) tmpsum += a[en];
        }
        if (en == num) break; // 증가한 en이 배열 마지막 num과 같아져 버린 상황이면 종료
        mnlen = min(mnlen, en - st + 1);
        tmpsum -= a[st]; // st는 증가할 것이므로 부분합에서 빼줌
    }

    if (mnlen == num) mnlen = 0;
    cout << mnlen;

    return 0;
}