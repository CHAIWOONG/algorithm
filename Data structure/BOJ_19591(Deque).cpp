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
        
    for(int j=0; j<str.size(); j++)#include <iostream>
#include <algorithm>
#include <deque> 
#include <string> 
#include <stack> 

        typedef long long ll;

    using namespace std;

    deque<ll> operand;
    deque<char> opertr;

    void parsing(string s) {

        string num = "";
        int flag = 0;

        if (s[0] == '-') flag = 1; // 첫번째 연산자가 음수인 경우에 대한 판별

        //문자열의 숫자와 기호에 따른 덱의 삽입 과정 진행
        for (int i = 0; i < s.length(); i++) {

            if (s[i] <= '9' && s[i] >= '0')
            {
                num += s[i];
            }
            else if ((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') && i != 0)
            {
                if (flag == 1) operand.push_back(-stoll(num));
                else operand.push_back(stoll(num));

                num = ""; flag = 0;
                opertr.push_back(s[i]);
            }
        }

        if (num != "") // 마지막 남은 배열의 숫자에 대해서 덱에 추가한다.
        {
            if (flag == 1) operand.push_back(-stoll(num));
            else operand.push_back(stoll(num));
            num = ""; flag = 0;
        }
    }


    ll Operate(ll num1, ll num2, char optr1)
    {
        switch (optr1) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        default:  //case '/'
            return num1 / num2;
        }
    }

    int conv[128];

    // 연산자 입력에 대해서 우선 순위의 파악 
    // 시간 복잡도의 간소화를 위해서 배열을 통해 숫자로 판단
    void convert() {
        conv['+'] = conv['-'] = 1;
        conv['*'] = conv['/'] = 2;
    }


    int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string text;
        cin >> text;

        parsing(text); convert();

        while (operand.size() != 1)
        {
            ll num1, num2, num3, num4;
            char optr1, optr2;

            if (conv[opertr.front()] > conv[opertr.back()])
            {
                num1 = operand.front(); operand.pop_front();
                num2 = operand.front(); operand.pop_front();
                optr1 = opertr.front(); opertr.pop_front();

                operand.push_front(Operate(num1, num2, optr1));
            }
            else if (conv[opertr.front()] == conv[opertr.back()])
            {

                num1 = operand[0]; num2 = operand[1];
                optr1 = opertr.front();

                num3 = operand[operand.size() - 2]; num4 = operand[operand.size() - 1];
                optr2 = opertr.back();

                int result1, result2;

                result1 = Operate(num1, num2, optr1);
                result2 = Operate(num3, num4, optr2);

                if (result1 >= result2)
                {
                    operand.pop_front();
                    operand.pop_front();
                    opertr.pop_front();

                    operand.push_front(result1);

                }
                else if (result1 < result2)
                {
                    operand.pop_back();
                    operand.pop_back();
                    opertr.pop_back();

                    operand.push_back(result2);
                }
            }
            else if (conv[opertr.front()] < conv[opertr.back()])
            {
                num1 = operand.back(); operand.pop_back();
                num2 = operand.back(); operand.pop_back();
                optr1 = opertr.back(); opertr.pop_back();

                operand.push_back(Operate(num1, num2, optr1));
            }

        }


        cout << operand.front() << "\n";

        return 0;
    }

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
