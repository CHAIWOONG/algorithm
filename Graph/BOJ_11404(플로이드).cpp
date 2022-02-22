#include <bits/stdc++.h>
using namespace std;

// 현재 테이블에 채워진 값을 불완전한 최단 거리가 아닌, 중간에 다른 정점을 거치지 않았을 때의 현재의 최단 거리로 생각하여 update
// 시간 복잡도는 O(v^3)

const int INF = 0x3f3f3f3f; // 거리가 무한임을 최대의 값으로 나타냄
int d[105][105];
int n, m;

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
  }
  
  for(int i = 1; i <= n; i++) d[i][i] = 0; // 자기 자신과의 거리는 0

  for(int k = 1; k <= n; k++) // 중간에 거쳐가야 하는 변수의 for문이 제일 바깥이다
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]); // 3중 for문을 통해 전부 다 접근하여 update
        // i를 시작점 j를 끝점, k는 중간점
  
  // 최단 거리 행렬을 출력
  
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(d[i][j] == INF) cout << "0 ";
      else cout << d[i][j] << ' ';
    }
    cout << '\n';
  }
}
