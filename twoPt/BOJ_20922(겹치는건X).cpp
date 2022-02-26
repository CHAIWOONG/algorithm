#include <bits/stdc++.h>

using namespace std;

int n,k,mx=0;
int arr[200001];
int vis[200001]; // 나온것의 체크 배열


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>k;
    /*for(int i=0; i<n; i++) {
        cin>>arr[i];
        vis[arr[i]]++;
    }*/
    
    // 이렇게 하면 시간초과, st를 옮기고 그에 따라서 en을 다시 초기화하여 끝까지 움직이므로
    /*for(int st=0; st<n; st++){
        
        int flag=0;
        int flag2=0;
        int tmplen;
        
        for(int en=st; en<n; en++){
            
            if(vis[arr[en]]){
                
                vis[arr[en]]++;
                flag = max(flag,vis[arr[en]]);
            }
            else vis[arr[en]] = 1;
            
            if(flag==k+1){
                tmplen = en-1-st+1;
                break;
            }
            tmplen = en-st+1;
        }
        
        memset(vis,0,sizeof(vis));
        mx = max(mx, tmplen);
    }*/
    
    // 수열의 입력도 한번에 받도록 처리
    // en이 먼저 증가하고 그 후에 조건에 따라서 st가 증가하니 en에 대한 for문 생성
  
    int st=0;
    for(int en=0; en<n; en++){
        
        cin>>arr[en];
        vis[arr[en]]++;
        
        while(vis[arr[en]]>k){ // en이 k를 넘는 경우가 발생하면,
            vis[arr[st++]]--; // st를 증가시키며 그에 따라서 중복에서 1개씩 제거하여 해당 en의 중복개수가 k미만되면 
        }
        mx=max(mx,en-st+1);
    }
    
    cout<<mx;
    return 0;
}
