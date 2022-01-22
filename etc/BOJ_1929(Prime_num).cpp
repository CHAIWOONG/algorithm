#include <iostream>
#include <vector>

//에라토스테네스의 체를 사용한 소수 판별 algorithm 구현

using namespace std;

int main(){
    
    int m,n;
    int arr[1000001];
    
    cin>>m>>n;
    
    for(int i=1; i<=n; i++)
        arr[i] = i; // 특정 범위 내부의 소수를 구할 때, 범위 내의 모든 수에 대한 배열 선언
    
    for(int i=2; i<=n; i++) //
    {
        if(arr[i]==0) continue; // 이미 값이 0인 경우, 판단을 최소화 하기위해 건너 뜀
        for(int j=i+i; j<=n; j+=i){
            arr[j] = 0; // for문을 통해 소수에서 시작하여 소수에 대한 배수들은 약수가 존재하는 것이므로 소수가 아니니 구별을 위해 0으로 변경
        }
    }
    
    for(int i=m; i<=n; i++)
    {
        if(arr[i] !=0 && i!=1) cout<<arr[i]<<"\n"; // 범위 배열에서 값이 0이 아닌 경우만 소수이므로 이를 출력
    }
    
    return 0;
}
