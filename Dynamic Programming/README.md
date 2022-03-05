# Dynamic Programming
___
## Knapsack
- zero-one knapsack: Dynamic programming
- non zero-one knapsack: Greedy Algorithm

### BOJ_12865 평범한 배낭

```c++
  #include <bits/stdc++.h> 
  using namespace std;
  int n, mxW;
  int weight[101];
  int value[101];
  int dp[101][100001]; // dp[i][j] = i개(n)를 확인했을 때, 무게(weight)가 j인 경우의 가치합(value)
  int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin >> n >> mxW; for (int i = 1; i <= n; i++) cin >> weight[i] >> value[i];
      
      // 가방에 현재의 물건을 담을 수 있나 없나를 판단해야됨
      // 해당 물건을 담을 수 있어도 담는게 이득인지 아닌지 판단해야됨
      for (int i = 1; i <= n; i++) {
          for (int k = 1; k <= mxW; k++) { // k가 max weight까지 커질 때, 
              // k가 현재 i번째의 무게( weight[i] )를 감당할 수 있게 된다면,
              // i-1번쨰에서 k 무게였던 것과, i-1번째에서 [k-현재 짐 무게]의 자리에서 가치합중 최대 값을 선택한다 
              if (k >= weight[i]) dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - weight[i]] + value[i]);
              else dp[i][k] = dp[i - 1][k];
          }
      }
      cout << dp[n][mxW];
      return 0;
  }
```

### BOJ_9084 동전

```c++
  #include <bits/stdc++.h>
  using namespace std;
  using ll = long long;
  int n,target;
  int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int T; cin>>T;
      while(T--){
          int c[21] = {0,};
          cin>>n; for(int i=1; i<=n; i++) cin>>c[i];
          cin>>target;

          int dp[10001] = {0,}; dp[0] = 1;

          for(int i=1; i<=n; i++){
              for(int j=c[i]; j<=10000; j++)
                  dp[j] += dp[j-c[i]];
          }
          cout<<dp[target]<<"\n";
      }
      return 0;
  }
```

### BOJ_2293 동전2

```c++
  #include <bits/stdc++.h>
  using namespace std;
  using ll = long long;
  int n, k;
  int dp[10001]; // dp[i] = i원을 만들 수 있는 가짓수
  int c[101]; // 동전의 집합
  int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin >> n >> k; for (int i = 1; i <= n; i++) cin >> c[i];
      
      // ***각 배열을 불가능한 최댓값으로 일단 채워 넣음
      for (int i = 1; i <= k; i++) dp[i] = 10001;

      // ****배낭 챙기기와 비슷하게 구현
      for (int i = 1; i <= n; i++) {
          for (int j = c[i]; j <= k; j++) {   // j=c[i],.....c[i+1].....k까지 돌게 돌게 되며 i역시 증가
              dp[j] = min(dp[j], dp[j - c[i]] + 1);
          }
      }
      if (dp[k] == 10001)cout << -1;
      else cout << dp[k];
      return 0;
  }
```

### BOJ_2225 합분해
```c++
  #include <bits/stdc++.h>
  using namespace std;
  using ll = long long;
  ll dp[201][201]; // dp[i][j] = i개의 수를 더해서 j를 만들 수 있는 경우의 수
  ll mod = 1000000000;
  int n,k;
  int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>n>>k;
      //dp[1][1] = 1;
      // 1개의 수로 num을 만들수 있는 방법은 1개
      for(int num=0; num<=n; num++) dp[1][num] = 1;
      
      for(int cnt = 2; cnt<=k; cnt++){ // 2개의 수 조합부터 시작
          for(int num = 0; num<=n; num++){ // num은 0부터 셈
              for(int m = 0; m<=num; m++){ 
                  dp[cnt][num] += dp[cnt-1][m]; // 이전 개수의 조합에서의 결과를 더해줌
              }
              dp[cnt][num]%=mod;
          }
      }
      cout<<dp[k][n]%mod;
      return 0;
  }
```

___

## 최장증가부분수열(LIS) 

### BOJ_11053 가장긴증가부분수열
```c++
  #include <bits/stdc++.h>
  using namespace std;
  int n,mx=0;
  int a[1001];
  int dp[1001]; // [i] = index를 i번째 까지 확인했을 때, 가능한 증가 부분수열 중에서 최대 길이
  // 어짜피 증가, 감소 수열의 경우 제일 마지막 것과, 현재의 위치만 비교하면 추가해도 이를 유지할 지가 명확하다.
  // a<b<c<d일 때, d<e이면 a<b<c<d<e다.
  int main(){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>n; for(int i=1; i<=n; i++) cin>>a[i];
      
      for(int i=1; i<=n; i++){
          int len = 0; // 각 i에서 매번 확인해야 하는 길이 len을 항상 reset
          for(int j=1; j<=i; j++){
              if(a[i]>a[j]){ // 현재의 위치 i보다 앞의 것 중에서, 더 작은것들을 확인하여 그게 있을 때,
                  if(len<dp[j]) len = dp[j];
                  // 그 dp[j]에는 그 자리 까지의 최대 길이의 증가 부분수열이 있을 것이므로 이를 len에 업데이트
              }
          }
          dp[i] = len+1; // 그렇다면 해당 dp[i]에서 들어갈 것은 확인해온 len에서 자기 자신의 수 1을 더한 값으로 저장
          if(mx < dp[i]) mx = dp[i]; // 문제 조건에 따라서 최대의 값을 mx에 저장
      }
      cout<<mx;
      return 0;
  }
```
___
