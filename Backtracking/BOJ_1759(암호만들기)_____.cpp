#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

// 오름차순, 중복제외 등의 조건에 맞춰서 arr vector에 조건을 만족하는 조합을 집어넣는다.
// 이 후, 출력을 하기 전에 모음의 수, 자음의 수와 같은 조건을 만족하는지 파악하여 해당 조건까지 만족하는 것 만, 출력을 하도록 구현

using namespace std;

int n, m;

vector<char> str; // 입력 character 저장을 위한 vector
vector<char> arr; // 비밀번호 완성 character 저장을 위한 vector

int used[200]; // 아스키 코드에 따라 소문자 알파벳 used 배열 구현

int check() { // 조건에 알맞은 상황만 출력하기 위한 check 함수

    int m_flag = 0; // 모음 확인 flag
    // 모음 개수 파악
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') m_flag++;
    }
    // 자음 2개이상, 모음 1개 이상인 경우만 true
    if (m_flag >= 1 && n - m_flag >= 2) return 1;
    return 0;
}

void func(int k) {

    if (k == n) { // base condition
        if (check()) // 자,모음 개수 조건에 맞는거만 출력
        {
            for (int i = 0; i < n; i++)
                cout << arr[i];
            cout << "\n";
        }
        return;
    }
    else {
        for (int i = 0; i < m; i++) {

            if (!used[str[i]]) { // 중복 제거를 위해 사용한 것 확인

                if (k != 0 && arr[k - 1] > str[i]) continue; // 앞자리보다 작으면 제외
                else arr.push_back(str[i]);

                used[str[i]] = 1;
                func(k + 1); // 조건이 모두 맞으면 다음 자릿수 재귀로 추가
                used[str[i]] = 0; // 다음 케이스에서의 사용을 위해 전 사용은 다시 used 0
                arr.pop_back(); // 해당 자릿수에서 확인된거는 pop
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        char temp; cin >> temp;
        str.push_back(temp); // vector는 되도록이면 push_back으로 추가
    }

    sort(str.begin(), str.end());
    func(0);

    return 0;
}
