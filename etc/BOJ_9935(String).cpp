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
        
        if(s.size()>=B.size() && s.substr(s.size()-len,len) == B) {
            
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