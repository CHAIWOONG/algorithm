#include <bits/stdc++.h>
using namespace std;

// kruskal 알고리즘의 시간복잡도는 union-find의 사용을 통하여 O(ElogE)

vector<int> p(10005,-1);

int find(int x){ // find
    if(p[x] < 0) return x; // 해당 node가 root
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){ // union
  
    u = find(u); v = find(v);

    if(u == v) return 0; // 같은 gruop
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int v, e;
tuple<int,int,int> edge[100005]; // 비용, 정점1, 정점2의 순서로 graph를 tuple 형태로 받음

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + e); // 비용의 순서로 edge를 오름차순 정렬

    int cnt = 0;
    int ans = 0;

    for(int i = 0; i < e; i++) // kruscal algorithm
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue; // union-find를 통해 같은 group이면 제외

        ans += cost; // 선택한 edge의 cost만큼 증가
        cnt++;
        if(cnt == v-1) break; // edge의 개수가 node-1이면 종료 
    }
    cout << ans;

    return 0;
}
