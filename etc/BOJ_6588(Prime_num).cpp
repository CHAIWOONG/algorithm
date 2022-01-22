#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;

//에라토스테네스의 체를 함수화 하여 사용한 소수 판별 

int arr[MAX];

void primeArr(){
    
    for(int i=1; i<=MAX; i++)
        arr[i] = i;
    
    for(int i=2; i<=MAX; i++)
    {
        if(arr[i]==0) continue;
        for(int j=i+i; j<=MAX; j+=i){
            arr[j] = 0;
        }
    }
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    primeArr(); // 각각의 testcase에 대한 소수 판별은 시간 초과를 발생시키므로 이미 소수를 판별해 놓도록 설정
    
    while(1){
        
        cin>>n;
        if(n==0) break;

        int a=0,b=0;
        
        for(int i=3; i<=n; i++){
            
            if(arr[i] !=0 && arr[n-arr[i]]!=0 ) // 조건을 만족하는 소수의 집합 중에서 최대의 차이를 발생하는 소수에 대한 출력을 for조건문을 통해 index안에서 확인
            {
                a = arr[i];
                b = arr[n-arr[i]];
                break;
            } 
        }
        
        if(a!=0 && b!=0) cout<<n<<" = "<<a<<" + "<<b;
        else cout<<"Goldbach's conjecture is wrong.";
        cout<<"\n";
  
    }
    return 0;
}
