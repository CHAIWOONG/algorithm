#include <iostream>
#include <algorithm>
#include <list>
#include <deque> 
#include <vector> 
#include <string> 
#include <stack> 
#define MAX 1000001

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str, B;
    //stack<char> s;
    string s;
    
    cin>>str>>B;
    int len = B.length();
    
    for(int i=0; i<str.size(); i++){
        
        s.push_back(str[i]);
        
        if(s.size()>=B.size() && s.substr(s.size()-len,len) == B) {  // string을 stack처럼 사용이 가능하다. 이 때, string의 멤버함수 substr을 유용하게 사용 가능
             
            for(int j=0; j<len; j++) 
                s.pop_back();
        }
    }
    
    if(s.empty()) cout<<"FRULA\n";
    else {
        for(auto element:s)
            cout<<element; }

    return 0;
}
