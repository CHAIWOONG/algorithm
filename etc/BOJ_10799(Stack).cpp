#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    
    int cut=0;       
    string str;
    stack<char> s;    
    cin >> str;
        
    for(int j=0; j<str.size(); j++)
    {   
        if(str[j]=='(')  s.push(str[j]);

        else if(str[j]==')')
        {   s.pop();
            if(str[j-1]=='(') cut+=s.size();
            else cut++;
        }
    }
        
    cout<<cut<<"\n";      
    return 0;
}