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
        
        int len = 0; // 각 i에서 매번 확인해야 하는 길이 len을 항상 reset
        for(int j=1; j<=i; j++){
            
            if(a[i]>a[j]){ // 현재의 위치 i보다 앞의 것 중에서, 더 작은것들을 확인하여 그게 있을 때,
                if(len<dp[j]) len = dp[j];
                // 그 dp[j]에는 그 자리 까지의 최대 길이의 증가 부분수열이 있을 것이므로 이를 len에 업데이트
            }
        }
        dp[i] = len+1; // 그렇다면 해당 dp[i]에서 들어갈 것은 확인해온 len에서 자기 자신의 수 1을 더한 값으로 저장
        if(mx < dp[i]) mx = dp[i];
        // 문제 조건에 따라서 최대의 값을 mx에 저장
    }
    
    cout<<mx;
    return 0;
}
