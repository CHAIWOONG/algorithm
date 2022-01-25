#include <iostream>
#include <algorithm>
#include <deque> 
#include <string> 
#include <vector> 
#include <stack> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, index = 1; cin >> n;

    stack<pair<int, int>> s; // 막대기의 왼쪽 부터의 순서와 길이를 스택에 동시 저장
    s.push({ 0,0 }); // empty인 상황에 대한 runtime 에러를 막기 위해 0,0의 push

    while (n--)
    {
        int x; cin >> x; // 막대기 입력 받음


        // 스택의 top이 입력 길이보다 작은 경우 (2)
        // top이 자기보다 큰게 나오거나, 스택이 빌 때까지 pop
        while (s.top().second < x && s.top().second != 0) s.pop();
        if (s.top().second == 0) // 스택이 빈 경우 (1)
        {
            s.push({ index++,x });
            cout << "0" << " ";
        }
        else // top이 자기보다 큰 경우 그걸 출력하고 자신 push (3)
        {
            cout << s.top().first << " ";
            s.push({ index++,x });
        }

        // 원래의 알고리즘은 이렇게 짰지만 위에 처럼 간소화 하였다. 

        //if (s.top().second == 0) // 스택이 빈 경우 (1)
        //{
        //    s.push({ index++,x }); // 해당 막대를 새롭게 스택에 push 
        //    cout << "0" << " ";
        //}
        //else if (s.top().second < x) // 스택의 top이 입력 길이보다 작은 경우 (2)
        //{
        //    // top이 자기보다 큰게 나오거나, 스택이 빌 때까지 pop
        //    while (s.top().second < x && s.top().second != 0) s.pop();
        //    if (s.top().second == 0) // 스택이 빈 경우 (1)
        //    {
        //        s.push({ index++,x });
        //        cout << "0" << " ";
        //    }
        //    else // top이 자기보다 큰 경우 그걸 출력하고 자신 push (3)
        //    {
        //        cout << s.top().first << " ";
        //        s.push({ index++,x });
        //    }
        //}
        //else if (s.top().second > x) // top이 자기보다 큰경우 그걸 출력하고 자신 push (3)
        //{
        //    cout << s.top().first << " ";
        //    s.push({ index++,x });

        //}
    }

    return 0;
}