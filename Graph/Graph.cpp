
        // ---------------------------------adjacency matrix
        // directed Graph

        int adj_matrix[10][10] = {};
        int v,e;
        cin>>v>>e;

        for(int i=0; i<e; i++){
            int u,v;
            cin>>u>>v;
            adj_matrix[u][v] = 1;
        }

        // undirected Graph

        int adj_matrix[10][10] = {};
        int v,e;
        cin>>v>>e;

        for(int i=0; i<e; i++){
            int u,v;
            cin>>u>>v;
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        }


        // ----------------------------------adjacency list
        // directed Graph

        vector<int> adj[10];
        int v,e;
        cin>>v>>e;

        for(int i=0; i<e; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        // undirected Graph

        vector<int> adj[10];
        int v,e;
        cin>>v>>e;

        for(int i=0; i<e; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // ----------------------------------------graph BFS

        vector<int> adj[10];
        bool vis[10];

        void bfs(){
            queue<int> q; 
            q.push(1);
            vis[1] = true;

            while(!q.empty()){
                int cur = q.front(); q.pop();
                cout<<cur<<" ";

                for(auto nxt : adj[cur]){
                    if(vis[nxt]) continue;
                    q.push(nxt);
                    vis[nxt] = true;
                }
            }
        }

        // ----------------------------------------graph DFS
        // 비재귀 dfs
        vector<int> adj[10];
        bool vis[10];

        void dfs(){
            stack<int> s;
            s.push(1);
            vis[1] = true;

            while(!s.empty()){
                int cur = s.top(); s.pop();
                cout<<cur<<" ";

                for(auto nxt : adj[cur]){
                    if(vis[nxt]) continue;
                    s.push(nxt);
                    vis[nxt] = true;
                }
            }
        }

        // 재귀 dfs
        vector<int> adj[10];
        bool vis[10];

        void dfs(int cur){
            vis[cur] = true;
            cout<<cur<<" ";

            for(auto nxt: adj[cur]){
                if(vis[nxt]) continue;
                else dfs(nxt);
            }
        }

