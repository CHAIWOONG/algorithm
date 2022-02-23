#include <bits/stdc++.h>
using namespace std;

// 현재 테이블에 채워진 값을 불완전한 최단 거리가 아닌, 중간에 다른 정점을 거치지 않았을 때의 현재의 최단 거리로 생각하여 update
// 시간 복잡도는 O(v^3)

// 상세 경로의 저장 테이블을 통해 실제 최단 경로 출력 가능하도록 구현

const int INF = 0x3f3f3f3f; // 거리가 무한임을 최대의 값으로 나타냄
int d[105][105];
int pass[105][105];
int n, m; // n = node, m = edge

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    fill(d[i], d[i]+1+n, INF); // 일단 모든 값을 무한으로 초기화
  
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c); // 입력을 통해 정해진 edge의 cost는 적용해줌
    pass[a][b] = b; // a에서 b로 갈 때의 거치는 중간점을 일단 초기 입력으로 저장
  }
  
  for(int i = 1; i <= n; i++) d[i][i] = 0; // 자기 자신과의 거리는 0
  
   for(int mid = 1; mid <= n; mid++)
     for(int st = 1; st <= n; st++)
       for(int en = 1; en <= n; en++)
         if(d[st][mid] + d[mid][en] < d[st][en]) {
             d[st][en] = d[st][mid] + d[mid][en];
             pass[st][en] = pass[st][mid]; // mid가 생기게 된다면, 경로 저장에 반영해줌
         }
  
  // 최단거리 테이블 전체 출력
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(d[i][j] == INF) cout << "0 ";
      else cout << d[i][j] << ' ';
    }
    cout << '\n';
  }
  
  // 각 최단 거리의 경로 상세 출력
  for(int i = 1; i <= n; i++){
      for(int j=1; j<=n; j++){
          
        if(d[i][j]==0 || d[i][j] ==INF){ cout<<"0\n"; continue;}
        
        vector<int> path; // 경로 저장해둘 vector
        
        int st = i;
        while(st!=j){
          path.push_back(st); // 경로 저장
          st = pass[st][j]; // 시작점 업데이트 
        }
        path.push_back(j); // 마지막 도착 node 까지 저장
        
        cout<<path.size()<<" "; // 경로의 크기 출력
        for(auto& element: path) cout<<element<<" "; // 실제 경로 출력
        cout<<"\n";
      }
  }
}
