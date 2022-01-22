#include <iostream>
#include <vector>
#include <algorithm>
#include <string> // string 타입의 사용을 위함
#include <stack>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); //C++ 입력 속도 증가를 위해 입력
    
    int cut=0;       
    string str; 
    stack<char> s;    
    cin >> str;
        
    for(int j=0; j<str.size(); j++)
    {   
        if(str[j]=='(')  s.push(str[j]); // string 타입의 str 변수를 통한 문자열 배열 형식 사용 (BOJ 11721)

        else if(str[j]==')')
        {   s.pop();
            if(str[j-1]=='(') cut+=s.size();
            else cut++;
        }
        //문제 조건의 단순화를 고려
    }
        
    cout<<cut<<"\n";      
    return 0;
}
