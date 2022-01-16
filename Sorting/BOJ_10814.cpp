#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp (pair<int, string> u, pair<int, string> v)
{
    return u.first < v.first;
}


int main(){
    
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    vector<pair<int, string>> v(n); //크기 지정하지 않으면 런타임 오류 발생
   
    for(int i=0; i<n; i++)
        cin>>v[i].first>>v[i].second;
    
    stable_sort(v.begin(),v.end(),cmp); // stable_sort()
    
    for (int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << "\n";
    
    return 0;
}
