#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[101][101]; // dp[i][j]를 (0, 0)에서 (i, j)까지 오는 경로의 개수로 저장
ll bd[101][101];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin>>bd[i][j];
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            if(i==0 && j==0) dp[i][j] = 1;
            if (bd[i][j] && i + bd[i][j] < n) dp[i + bd[i][j]][j] += dp[i][j]; // 아래 점프
		        if (bd[i][j] && j + bd[i][j] < n) dp[i][j + bd[i][j]] += dp[i][j]; // 오른쪽 점프
        }
    }
    
    cout<<dp[n-1][n-1];
    return 0;
}
