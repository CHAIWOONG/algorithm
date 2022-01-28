#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//priority_queue<pair<int,int>> mxhp; // 컵라면수, 데드라인의 max heap
//priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mnhp;
// 데드라인과 컵라면 수에 대한 min Heap
// ***** heap을 여러개 만들어서 이를 삭제하는 과정을 반복하게 되면 시간복잡도가 증가할 것이다

priority_queue<int, vector<int>, greater<int>> mnhp; // 컵라면 수에 대한 min heap

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> v; // 데드라인과 컵라면 수의 저장

    while (n--)
    {
        int deadline, num; cin >> deadline >> num;
        v.push_back({ deadline,num });
    }

    sort(v.begin(), v.end()); // 데드라인에 대해 오름차순으로 정렬후 라면 수에 대해 판단
    int count = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int deadline = v[i].first;
        mnhp.push(v[i].second); // min heap은 컵라면 수에 대해 push
        if (mnhp.size() > deadline) mnhp.pop();
        // min heap의 사이즈에 대해 같은 데드라인 값에서 컵라면 수가 더 작은 값을 pop하여 삭제
        // *****heap의 사이즈를 조절하여, heap 안에서 원소를 삭제하는 과정을 최대한 줄이고 필요한 것만 저장하여 사용하도록 구현한다
    }

    while (!mnhp.empty())
    {
        count += mnhp.top(); // heap에는 같은 데드라인에서 최대의 컵라면 수의 것만 저장되어있을 것임
        mnhp.pop();
    }
    cout << count;

    return 0;
}