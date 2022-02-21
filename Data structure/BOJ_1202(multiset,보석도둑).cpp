#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n,k; // 보석 n개, 가방 k개
ll ans =0;
pii dia[300005]; //보석 = (가격, 무게)
//int bag[300005];
multiset<int> bag; // 가방의 무게는 중복이 일단 가능하며, 정렬되어있는게 편하므로 multiset을 사용한다

// ***가장 가격이 높은 보석을 해당 보석을 견디는 가장 최대 무게가 작은 가방에 넣는다 (그리디)

int main(void){
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>k;
    for(int i=0; i<n; i++) // 가격순으로 정렬하기 위해서 second를 무게로 받음
        cin>>dia[i].second>>dia[i].first;
    
    sort(dia, dia+n); // 가격순으로 보석을 정렬,
    
    for(int i=0; i<k; i++){ // 가방의 무게를 multiset에 정렬
        int b; cin>>b;
        bag.insert(b);
    }
        
    for(int i=n-1; i>=0; i--){ // 최대 가격의 보석에 대하여 먼저 결정
        
        auto it = bag.lower_bound(dia[i].second); // 보석 무게에서 lower bound로 넣을 수 있는 최소 가방 찾는다.
        if(it == bag.end()) continue; //**** 런타임 오류 발생에 대한 예외 처리 
        ans += dia[i].first; //  보석의 가격 저장
        bag.erase(it); // 사용된 가방은 제거
    }
    
    cout<<ans;
    return 0;
}
