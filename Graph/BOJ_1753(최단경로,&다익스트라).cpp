#include <bits/stdc++.h>
#define X first
#define Y second

// 다익스트라 알고리즘 = 하나의 시작점으로부터 다른 모든 정점까지의 최단 거리를 구하는 알고리즘
// 플로이드 알고리즘 = 모든 정점 쌍 사이의 최단 거리를 구하는 알고리즘

using namespace std;
using pii = pair<int,int>;

int v,e,st;
vector<pair<int,int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005]; // 시작점 st에 대한 최단 거리 1차원 테이블

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin>>v>>e>>st;
  fill(d,d+v+1, INF); // 최단거리 테이블 INF로 초기화
  
  while(e--){
    int u,v,w;
    cin >> u >> v >> w; // u에서 v로 가는 cost가 w인 edge의 입력
    adj[u].push_back({w,v}); // {비용, 정점 번호}
  }
  
  // *** min heap은 우선순위를 cost에 대해서 비교하도록 구현되어야 한다
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > mnHp;
  d[st] = 0;
  
  // heap에 (cost, 시작점) 추가
  mnHp.push({d[st],st});
  
  // heap이 비면 종료
  while(!mnHp.empty()){
    auto cur = mnHp.top(); mnHp.pop(); // {비용, 정점 번호}    
    
    // 거리가 d에 있는 값과 다를 경우 넘어감 (heap에서는 삭제된다)
    if(d[cur.Y] != cur.X) continue;
    
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
      // cur를 거쳐가는 것이 더 작은 값을 가질 경우
      // d[nxt.Y]을 갱신하고 heap에 (거리, nxt.Y)를 일단 추가
      d[nxt.Y] = d[cur.Y]+nxt.X;
      mnHp.push({d[nxt.Y],nxt.Y}); //heap에 (cost, 시작점) 추가
    }
  }
  
  // st에서 각 node까지의 최단거리 출력
  for(int i = 1; i <= v; i++){
    if(d[i] == INF) cout << "INF\n";
    else cout << d[i] << "\n";
  }
  
  return 0;
}
