#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

// 점수의 최댓값이 되도록 구하는 상황 -> 그리디 알고리즘
// 점수가 가장 높은 것부터 확인하여 선택한다.
// 점수가 가장 높은 것 부터 확인하게 되는데,
// 해당 과제 마감날짜 만큼의 날에는 그 과제를 하는 것으로 하며,
// 이미 그 날에 다른 더 점수가 높은 과제를 해야하는 경우는,
// 그날의 앞을 확인하면서 할 수 있는 날짜에 그 과제를 하도록 한다.

int n, ans = 0;
int day[1001];
vector<pii> vec; // 점수, 기간의 순서로 저장

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int d, w; cin >> d >> w;
        vec.push_back({ w,d });
    }

    sort(vec.begin(), vec.end(), greater<pii>()); // 점수의 순서대로 내림차순 정렬

    for (auto& element : vec) {

        int tmpd = element.second;
        while (tmpd) {

            if (!day[tmpd]) { // 날짜가 비어있으면 해당 과제를 하기로 하고 반복 종료
                day[tmpd] = 1;
                ans += element.first;
                break;
            }
            tmpd--; // 이미 차있으면 앞의 날짜를 확인함
        }
    }
    cout << ans;
    return 0;
}