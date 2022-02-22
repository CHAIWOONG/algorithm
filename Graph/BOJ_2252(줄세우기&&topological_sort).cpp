#include <bits/stdc++.h>

using namespace std;

vector<int> adj[32010];  // 인접 리스트
int indeg[32010]; // node의 indegree 값 저장
int n, m;

queue<int> q;
vector<int> result;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int in,out; cin>>out>>in;
        adj[out].push_back(in);
        indeg[in]++;
    }
    
    for(int i=1; i<=n; i++){
        if(indeg[i]==0) q.push(i); // indegree가 0인 node를 먼저 queue에 삽입
    }
    
    while(!q.empty()){
        
        int cur = q.front(); q.pop();
        result.push_back(cur);
        
        //cout<<cur<<" ";
        
        for(int nxt : adj[cur]){ // 해당 node를 삭제하고 result에 넣으면서 가지고 있던 outdegree 모두 제거
            indeg[nxt]--;
            if(indeg[nxt] == 0) q.push(nxt); // 새롭게 indegree가 0이 되는 것은 queue에 삽입
        }
    }
    
    /*if(result.size() != n) // graph에 cycle이 존재하는 경우에 대한 예외 설정
        cout<<"cycle exists";
    else{
        for(auto x: result)
            cout<<x<<" ";
    }*/
    
    for(auto x: result)
        cout<<x<<" ";
    
    return 0;
}
