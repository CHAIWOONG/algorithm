#include <bits/stdc++.h>
using namespace std;

// 프림 알고리즘의 시간복잡도는 O(ElogE)

#define X first
#define Y second

int v, e;
vector<pair<int,int>> adj[10005]; // {비용, 정점 번호}
bool chk[10005]; // chk[i] : i번째 정점이 최소 신장 트리에 속해있는가? 

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> v >> e;
  for(int i = 0; i < e; i++){
    int a, b, cost;
    cin >> a >> b >> cost;
    adj[a].push_back({cost, b});
    adj[b].push_back({cost, a});
  }

  int cnt = 0; // 현재 선택된 간선의 수
  int ans = 0;
  
  // tuple<int,int,int> : {비용, 정점 1, 정점 2}
  priority_queue< tuple<int,int,int>,
                  vector<tuple<int,int,int>>,
                  greater<tuple<int,int,int>> > pq; // edge의 cost에 대하여 Min Heap 생성

  chk[1] = 1; // 첫번째 node인 1에 대해서 MST에 속한채로 시작
  for(auto nxt : adj[1])
    pq.push({nxt.X, 1, nxt.Y}); // 첫번째 node 1과 연결된 Edge에 대하여 실행

  while(cnt < v - 1){ // node-1 = edge를 만족할 때 까지,
    int cost, a, b;
    tie(cost, a, b) = pq.top(); pq.pop();
    
    if(chk[b]) continue; // 이미 node가 MST에 포함되어서 checked 가 1이라면 제외
    ans += cost;
    chk[b] = 1;
    cnt++;
    
    for(auto nxt : adj[b]){ // 새로 MST에 추가된 인접 node에 대해서 확인하여 아직 checked = 0이면, heap에 새롭게 push
      if(!chk[nxt.Y])
        pq.push({nxt.X, b, nxt.Y});
    }
  }
  cout << ans;
}
