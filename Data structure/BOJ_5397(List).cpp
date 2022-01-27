#include <iostream>
#include <algorithm>
#include <deque> 
#include <string> 
#include <vector> 
#include <list> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    while (n--)
    {
        string input; cin >> input;
        list<char> password;
        auto it = password.end(); // 커서를 반복자로하여 .end()로 받았다

        for (int i = 0; i < input.length(); i++)
        {
            if (isalpha(input[i]) || isdigit(input[i]))
            {
                password.insert(it, input[i]);
            }
            else if (input[i] == '<')
            {
                if (it != password.begin()) it = prev(it);
            }
            else if (input[i] == '>')
            {
                if (it != password.end()) it = next(it);
            }
            else if (input[i] == '-')
            {
                if (it != password.begin()) it = password.erase(prev(it));
            }
        }

        for (auto& element : password)
            cout << element;
        cout << "\n";
    }

    return 0;
}