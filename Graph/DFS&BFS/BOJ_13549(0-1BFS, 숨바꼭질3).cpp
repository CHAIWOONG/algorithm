#include <bits/stdc++.h>
#define MAX 100001

// 0-1 BFS O(V)+O(E)=O(V+E)의 시간 복잡도

using namespace std;

int vis[MAX]; 
int dis[MAX]; // MAX는 여유있게 해야한다. -1이 있으므로 범위를 넘었다가 돌아올 수 있음
int dx[3] = {2, 1,-1}; // [0]은 그냥 더미로 둔것임 
int st,en;
queue<int> q;

void bfs(){
    
    while(!q.empty()){
       
        int tmp = q.front(); q.pop();
        if(tmp == en){ 
            cout<<dis[en]<<"\n";
            return;
        }
        
        for(int i=0; i<3; i++){
            
            int nx;
            if(i==0) { // 순간이동을 하는 경우 시간이 0초
                nx=tmp*2;
                if(nx<0 || nx>=MAX) continue;
                if((!vis[nx] || dis[nx] > dis[tmp])){ 
                    // 0의 가중치가 있으므로 원래 있던것 보다 더 작을 수 있으니 확인해야된다.
                    vis[nx] = 1;
                    dis[nx] = dis[tmp];
                    q.push(nx);
                }
            }
            else{ // +1, -1의 이동을 하는 경우 시간이 1초 
                nx=tmp+dx[i];
                if(nx<0 || nx>=MAX) continue;
                if(!vis[nx] || dis[nx] > dis[tmp] + 1){
                    vis[nx] = 1;
                    dis[nx] = dis[tmp]+1;
                    q.push(nx);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>st>>en;
    q.push(st); vis[st]=1;
    bfs();
    return 0;
}
