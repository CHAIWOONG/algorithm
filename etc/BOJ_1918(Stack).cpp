#include <iostream>
#include <algorithm>
#include <list>
#include <deque> 
#include <vector> 
#include <string> 
#include <stack> 
#define MAX 1000001

using namespace std;

int conv[128];

void convert() {
	conv['('] = conv[')'] = 1;
	conv['+'] = conv['-'] = 2;
	conv['*'] = conv['/'] = 3;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    stack<char> stk;
    
    cin>>str;
    convert();
    
    for(int i=0; i<str.length(); i++){
        
        if(str[i]>='A'&& str[i]<='Z') {
            cout<<str[i];
        }
        else if(str[i]=='('){
            stk.push(str[i]);
        }
        else if(str[i]==')'){
            
            while(!stk.empty()&&stk.top()!='(') {
                
                cout<<stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{
   
            while(!stk.empty()&&conv[str[i]]<=conv[stk.top()]) {
                
                cout<<stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }
    }
    
    while(!stk.empty()) {
        cout<<stk.top();
        stk.pop();
    }

    return 0;
}
