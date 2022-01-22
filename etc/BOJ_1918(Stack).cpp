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

// 연산자 입력에 대해서 우선 순위의 파악 + 시간 복잡도의 간소화를 위해서 배열을 통해 숫자로 판단
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
    convert(); // 연산자 우선순위 파악을 위한 배열 생성
    
    for(int i=0; i<str.length(); i++){ // string의 반복은 str.length 만큼으로만 지정하여 time dumped 오류를 예방하자
        
        if(str[i]>='A'&& str[i]<='Z') {  // 숫자는 stack에 저장하지 않고 그대로 출력
            cout<<str[i];
        }
        else if(str[i]=='('){  // 왼쪽 괄호는 무조건 stack에 포함
            stk.push(str[i]);
        }
        else if(str[i]==')'){ // 오른쪽 괄호는 왼쪽 괄호가 나타나기 전까지 안에있는 것을 모두 pop
            
            while(!stk.empty()&&stk.top()!='(') {
                
                cout<<stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{ // 괄호가 아닌 연산자에 대해서는 우선순위를 판단하여 stack에 push할지 pop 할지 판단한다
   
            while(!stk.empty()&&conv[str[i]]<=conv[stk.top()]) {
                
                cout<<stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }
    }
    
    while(!stk.empty()) { // stack에 남아있는 연산자를 전부 출력
        cout<<stk.top();
        stk.pop();
    }

    return 0;
}
