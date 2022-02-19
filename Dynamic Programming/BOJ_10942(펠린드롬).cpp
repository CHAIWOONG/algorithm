#include <bits/stdc++.h>

using namespace std;
int n,m,strt,en;
int a[2001];
int dp[2001][2001]; // dp[i][j] = i~j 까지 수의 펠린드롬 여부

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    
    for(int i=1; i<=n-1; i++){ 
        if(a[i] == a[i+1]) dp[i][i+1] =1; // 1차이가 나는데 서로 값이 같으면 펠린드롬
        dp[i][i] = 1;
        if(i==n-1) dp[i+1][i+1] = 1; // 같은 idx끼리는 펠린드롬
    }
    
    for(int i=n-1; i>=1; i--){ // s~e가 펠린드롬이면, (s+1 ~ e-1)도 펠린드롬
        for(int j=i+2; j<=n; j++){
            if(a[i]==a[j] && dp[i+1][j-1])
                dp[i][j] = 1;
        }
    }

    cin>>m;
    while(m--){
        cin>>strt>>en;
        cout<<dp[strt][en]<<"\n";
        
    }

    return 0;
}
