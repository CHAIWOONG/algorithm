
// ----------------------------------------tree BFS
// ex) 부모 배열 채우기

vector<int> adj[10];
int p[10]; // 각 정점의 부모를 저장할 배열의 생성

void bfs(int root){
    queue<int> q;  q.push(root);
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout<<cur<<" ";
        
        for(auto nxt : adj[cur]){
            if(p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
}

// ex) 부모와 depth 배열 채우기

vector<int> adj[10];
int p[10]; // 각 정점의 부모를 저장할 배열의 생성

void bfs(int root){
    queue<int> q;  q.push(root);
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout<<cur<<" ";
        
        for(auto nxt : adj[cur]){
            if(p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}

// ----------------------------------------tree DFS
// 비재귀 dfs
vector<int> adj[10];
int p[10]; // 각 정점의 부모를 저장할 배열의 생성\
int depth[10];

void dfs(int root){
    stack<int> s;  s.push(root);
    
    while(!s.empty()){
        int cur = s.top(); s.pop();
        cout<<cur<<" ";
        
        for(auto nxt : adj[cur]){
            if(p[cur] == nxt) continue;
            s.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
          dfs(nxt);
        }
    }
}

// 재귀 dfs
vector<int> adj[10];
int p[10]; // 각 정점의 부모를 저장할 배열의 생성
int depth[10];

void dfs(int cur){
    cout<<cur<<" ";
    
    for(auto nxt: adj[cur]){
        if(p[cur] == nxt) continue;
        else {
          p[nxt] == cur;
          depth[nxt] = depth[cur] + 1;
          dfs(nxt);
        }
    }
}

// 재귀 dfs
vector<int> adj[10];

void dfs(int cur, int par){
    cout<<cur<<" ";
    
    for(auto nxt: adj[cur]){
        if(par == nxt) continue;
        else {
          dfs(nxt,cur);
        }
    }
}
// call dfs(1,0);
