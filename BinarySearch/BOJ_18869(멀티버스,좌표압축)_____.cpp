#include <bits/stdc++.h>

using namespace std;

int num, planet, cnt = 0;

// 좌표 압축, 중복 제거, 2차원 vector
// 행성의 크기가 1,000,000 까지 가능하므로 압축하여 크기순 idx를 받아 판별할 수 있다

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> num >> planet;

    // *** 2차원 vector
    vector<vector<int>> uni(num, vector<int>(planet));

    for (int i = 0; i < num; i++) { // 각 우주에 대해서 시행

        for (int j = 0; j < planet; j++) cin >> uni[i][j]; // 각 우주의 행성을 크기 받음

        auto I = uni[i]; // 우주[i] 복사본
        sort(I.begin(), I.end()); // 복사본 정렬
        I.erase(unique(I.begin(), I.end()), I.end());//복사본 중복제거

        for (int j = 0; j < planet; j++)
            uni[i][j] = lower_bound(I.begin(), I.end(), uni[i][j]) - I.begin();
        // 우주[i]에서 특정 행성 j에 대해서, 우주[i]의 중복 제거 복사본 I에 따라서 lower_bound에서의 값을 받아 I.begin()을 뺴서 index 형태로 변환하여 저장
        // 복사본 중복 제거를 토대로 우주[i]에 좌표 압축 idx 할당
    }

    // ***** vector를 통째로 받아서 == operator를 통해 같은지 판단
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (uni[i] == uni[j]) cnt++; // 각 우주 별로 비교하여 같으면 count;
        }
    }

    cout << cnt;
    return 0;
}