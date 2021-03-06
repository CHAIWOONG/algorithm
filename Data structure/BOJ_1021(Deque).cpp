#include <iostream>
#include <algorithm>
#include <list>
#include <deque> 
#include <vector> 

using namespace std;

int main()
{
    
    int n, m, ans=0;
    //queue<int> q;
    
    deque<int> dq;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++) dq.push_back(i);
    
    while(m--){
        int idx = 0, t;
        cin>>t;
        
        for(int i =0; i<dq.size(); i++)
        {
            if(dq.front()==t) {
                
                idx = i;
                break;
            }
            dq.push_front(dq.back());
            dq.pop_back();

        }
        
        ans +=min<int>(idx, dq.size()-idx);
        dq.pop_front();
    }
    
    cout<<ans;
    
   
   	return 0;
	
}
