#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;

int n, result=0;

vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq; // min heap 생성

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        int pay,day; cin>>pay>>day;
        v.push_back({day,pay});
    }
    sort(v.begin(), v.end()); // day 기준으로 vector 정렬
    
    // priority queue를 통해 min heap을 생성하여
    // 사이즈에 따른 주머니를 생성한 후,
    // 새로 체크하는 값에 대해서 top과 비교하여
    // pop하여 새로 넣거나, 그냥 지나가거나를 결정함
  
    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);
        result += v[i].second;
 
        if (pq.size() > v[i].first) { 
            result -= pq.top();// 최소힙에서 top을 빼고
            pq.pop(); 
        }
    }
    cout << result;
    return 0;
}
