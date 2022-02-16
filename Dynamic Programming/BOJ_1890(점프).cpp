#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 각 칸에 대하여, 시작점 (0,0)에서부터 올 수 있는 거리는 매 순간마다 업데이트 되므로 따로 저장될 필요가 있다.

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
        for(int j=0; j<n; j++){ // 전체의 모든 칸에 대하여 아래점프와 오른쪽 점프를 모두 판단할 때,
            
            if(i==0 && j==0) dp[i][j] = 1; // 시작점은 무조건 경로 1개
            if (bd[i][j] && i + bd[i][j] < n) dp[i + bd[i][j]][j] += dp[i][j]; // 해당 칸에서의 아래 점프 목적지가 범위를 만족한다면, 목적지에 출발지 자신의 값을 추가해줘야됨
	    if (bd[i][j] && j + bd[i][j] < n) dp[i][j + bd[i][j]] += dp[i][j]; // 오른쪽 점프도 마찬가지
        }
    }
    
    cout<<dp[n-1][n-1];
    return 0;
}
