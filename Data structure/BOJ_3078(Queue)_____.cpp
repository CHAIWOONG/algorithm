#include <iostream>
#include <algorithm>
#include <queue> 
#include <utility>
#include <string>

using namespace std;


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, gap;
    long long count = 0;
    cin>>num>>gap;
    
    // 이름의 길이에 대한 queue의 배열을 만든다.
    queue<int> q[21];
    
    // 등수의 순서대로 입력이 될 때, 
    // 어짜피 조합(쌍)이므로 낮은 등수가 위에 사람꺼만 세도록 하면 된다.
    // 조건을 나눠서 파악 하도록 한다.
    for(int i = 1; i<=num; i++)
    {
        string name;
        cin>>name;
        
        int len = name.length();
        
        // 이렇게 풀면 연산이 많아서 처리가 안되는 듯 하다
        // while(!q[len].empty() ) 
        // {
        //     if ( (i-q[len].front()) <= gap) 조건이 만족하는 경우 뒤에 넣고 앞을 빼며
        //     {
        //         count+=1;
        //         q[len].push( q[len].front());
        //     }
        //     q[len].pop();  조건이 만족하지 않는 경우는 넣는거 없이 빼기만 했는데 연산이 안되었다
        // }
        
        // 조건을 만족하지 않는 경우에 한해서만 pop되게 끔 처리하면 상대적으로 단순해진다
        while(!q[len].empty() && (i-q[len].front()) > gap) 
        {
            q[len].pop();
        }
        
        // 이후 남아있는 것을 한번에 size를 확인하여 count하게 된다.
        count += q[len].size();
        
        // 해당 부분의 index를 queue에 추가한다
        q[len].push(i);
    }
    
    
    cout<<count;
    
    return 0;
}
