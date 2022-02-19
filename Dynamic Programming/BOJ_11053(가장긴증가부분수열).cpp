#include <bits/stdc++.h>

using namespace std;

int n,mx=0;
int a[1001];
int dp[1001]; // [i] = i에서까지의 최대 길이

// 어짜피 증가, 감소 수열의 경우 제일 마지막 것과, 현재의 위치만 비교하면 추가해도 이를 유지할 지가 명확하다.
// a<b<c<d일 때, d<e이면 a<b<c<d<e다.
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    
    for(int i=1; i<=n; i++){
        
        int idx = 0;
        for(int j=1; j<=i; j++){
            
            if(a[i]>a[j]){ // 현재의 위치 i보다 앞의 것 중에서, 더 큰게 있을 때,
                if(idx<dp[j]) idx = dp[j];
            }
        }
        dp[i] = idx+1;
        if(mx < dp[i]) mx = dp[i];
    }
    
    cout<<mx;
    return 0;
}
