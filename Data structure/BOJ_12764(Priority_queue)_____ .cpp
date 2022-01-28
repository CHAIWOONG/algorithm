#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

//------------------------------------ 제일 빠른 종료 시간을 확인하며, 사용 가능 컴퓨터 중에서 제일 최소 index를 확인해야 하므로 heap을 2개 만든다.

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp; // ***진행의 과정에서 사용 종료 시간, 사용 컴퓨터를 저장하는 min Heap
priority_queue<int, vector<int>, greater<int>> comHeap; // ***사용 컴퓨터의 경우 항상 최소 index의 컴퓨터가 나와야 한다

int com[MAX];  // 컴퓨터 사용 횟수 체크를 위한 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> v; // 시작 시간과 종료 시간을 저장할 pair 타입의 배열

    int n, count = 0; cin >> n;
    int computer = 1; // 컴퓨터의 index는 1부터 시작

    while (n--)
    {
        int start, end; cin >> start >> end;
        v.push_back(make_pair(start, end));
    }
    
    sort(v.begin(), v.end()); // 시작 시간을 기준으로 정렬함

    for (int i = 0; i < v.size(); i++) // 입력된 시간의 개수 동안
    {
        if (temp.empty()) // 시작에서는 temp가 비어있음
        {
            temp.push(make_pair(v[i].second, computer)); // temp heap에는 종료시간, 사용 컴퓨터 순으로 저장
            com[computer] ++; 
            computer++; // 사용하는 컴퓨터는 다음 인덱스를 가리킴
        }
        else // 시작이 아니면 temp에 저장된 게 있음
        {
            if (temp.top().first < v[i].first || !comHeap.empty()) // 끝나는게 있어서 새로운 시작 시간을 넣을 수 있을 때  
            {
                while (!temp.empty() && temp.top().first < v[i].first) 
                {
                    comHeap.push(temp.top().second);
                    temp.pop();
                } // ***temp의 top은 종료 시간에 최소힙을 만든다. 사용 컴퓨터의 최소 인덱스 기반으로 차지되어야 하므로
                  // while 문을 통해서 vector의 시작시간보다 작은 temp의 top에 대해서 전부 빼서 사용 컴퓨터 인덱스인 (temp.top.second)는 컴퓨터 minHeap에 넣는다.

                /*int comtemp = temp.top().second;
                int endtemp = temp.top().first;
                temp.pop();*/                    // -----------------pop을 이렇게 한번만 하면, 종료시간에 따라 점유되지 최소 인덱스 컴퓨터에 따라서 점유되지 못한다.

                temp.push(make_pair(v[i].second, comHeap.top())); // 해당 원소의 종료시간과 사용 컴퓨터 index (computer minHeap의 top)를 pair로 temp에 넣는다. 
                com[comHeap.top()]++; // 
                comHeap.pop(); // 사용 컴퓨터는 heap에서 pop
            }
            else // 제일 빠른 종료 시간과 새로운 시작 시간이 맞지 않아서 아예 새로운 컴퓨터를 사용해야 하는 경우,
            {
                temp.push(make_pair(v[i].second, computer));
                com[computer] ++;
                computer++;
            }
        }
    }

    cout << computer - 1 << "\n";
    for (int i = 1; i <= computer - 1; i++)
        cout << com[i] << " ";

    return 0;
}