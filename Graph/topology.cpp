    vector<int> adj[10]; // 인접 리스트
    int indeg[10];  // node의 indegree 값 저장
    int n;

    queue<int> q;
    vector<int> result;

    for(int i=1; i<=n; i++)
        if(indeg[i]==0) q.push(i); // indegree가 0인 node를 먼저 queue에 삽입

    while(!q.empty()){

        int cur = q.front(); q.pop();
        result.push_back(cur);

        for(int nxt : adj[cur]){ // 해당 node를 삭제하고 result에 넣으면서 가지고 있던 outdegree 모두 제거
            indeg[nxt]--;
            if(indeg[nxt] == 0) q.push(nxt); // 새롭게 indegree가 0이 되는 것은 queue에 삽입
        }
    }

    if(result.size() != n)
        cout<<"cycle exists";
    else{
        for(auto x: result)
            cout<<x<<" ";
    }
