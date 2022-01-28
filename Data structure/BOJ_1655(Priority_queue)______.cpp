#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// maxheap과 minheap으로 중앙값 만들기

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

// maxheap이 항상 minheap보다 1개 크거나 같은 경우
// 데이터의 개수가 짝수이면 중간의 두개의 수 중에서 작은 수에 저장 (max heap.top 반환)
// 새로운 데이터가 기존 데이터의 중앙값보다 작으면 최대힙에 저장, 크면 최소힙에 저장

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;

    while (n--)
    {
        int data; cin >> data;

        // 개수 맞춰줌
        if (maxHeap.size() > minHeap.size()) minHeap.push(data);
        else maxHeap.push(data);

        if (maxHeap.size() && minHeap.size() && maxHeap.top() > minHeap.top())
        {
            // maxHeap 항상 1 크거나 같은 개수를 맞춰줘야함
            int a = maxHeap.top(); maxHeap.pop();
            int b = minHeap.top(); minHeap.pop();
            maxHeap.push(b); minHeap.push(a);
        }

        cout << maxHeap.top() << "\n";
    }

    return 0;
}
