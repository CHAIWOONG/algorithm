#include <iostream>
#include <algorithm>
#include <deque> 
#include <string> 
#include <vector> 
#include <queue> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 0; cin >> n;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    while (n--)
    {
        int x; cin >> x;
        minHeap.push(x);
    }

    // 그리디 알고리즘을 사용하여 무조건 최소의 값만 가지도록 한다
    // 최소의 값의 합을 다시 minHeap에 넣고 최소 2개씩 뽑아서 더한다
    while (minHeap.size() > 1)
    {
        int temp1 = minHeap.top(); minHeap.pop();
        int temp2 = minHeap.top(); minHeap.pop();
        ans += temp1 + temp2;
        minHeap.push(temp1 + temp2);
    }

    cout << ans;
    return 0;
}