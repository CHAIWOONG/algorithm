#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a[1001];
vector<ll> two;
int num;

//2개의 값을 묶은 후 어느 한쪽의 값을 이분탐색으로 찾아서 시간복잡도를 낮추는 아이디어

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>num;
    for(int i=0; i<num; i++) cin>>a[i];
    sort(a, a+num);
    
    // 오름차순 정렬된 a배열에서 두개의 수를 꺼내서 그 합을 차근차근 two 배열에 저장
    for(int i=0; i<num; i++){
        for(int j=i; j<num; j++)
            two.push_back(a[i] + a[j]);
    }
    
    // two 배열을 크기순으로 정렬
    sort(two.begin(), two.end());
    
    // a배열의 최대 값부터 확인하여, 그에 대해서 가장 멀리 떨어진 값과 확인하여, 
    // 크기순으로 정렬된 two 배열에 대해서 뒤에서 부터 이분 탐색으로 확인하여 존재한다면 바로 출력 후 종료한다
    for(int i=num-1; i>=0; i--){
        for(int j=0; j<num; j++){
            if(binary_search(two.begin(),two.end(), a[i] - a[j])){
                cout<<a[i];
                return 0;
            }
        }
    }
    return 0;
}
