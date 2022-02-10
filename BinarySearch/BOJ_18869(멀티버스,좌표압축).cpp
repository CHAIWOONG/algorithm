#include <bits/stdc++.h>

using namespace std;

int num, planet, cnt = 0;

// ��ǥ ����, �ߺ� ����, 2���� vector
// �༺�� ũ�Ⱑ 1,000,000 ���� �����ϹǷ� �����Ͽ� ũ��� idx�� �޾� �Ǻ��� �� �ִ�

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> num >> planet;

    // *** 2���� vector
    vector<vector<int>> uni(num, vector<int>(planet));

    for (int i = 0; i < num; i++) { // �� ���ֿ� ���ؼ� ����

        for (int j = 0; j < planet; j++) cin >> uni[i][j]; // �� ������ �༺�� ũ�� ����

        auto I = uni[i]; // ����[i] ���纻
        sort(I.begin(), I.end()); // ���纻 ����
        I.erase(unique(I.begin(), I.end()), I.end());//���纻 �ߺ�����

        for (int j = 0; j < planet; j++)
            uni[i][j] = lower_bound(I.begin(), I.end(), uni[i][j]) - I.begin();
        // ����[i]���� Ư�� �༺ j�� ���ؼ�, ����[i]�� �ߺ� ���� ���纻 I�� ���� lower_bound������ ���� �޾� I.begin()�� ���� index ���·� ��ȯ�Ͽ� ����
        // ���纻 �ߺ� ���Ÿ� ���� ����[i]�� ��ǥ ���� idx �Ҵ�
    }

    // ***** vector�� ��°�� �޾Ƽ� == operator�� ���� ������ �Ǵ�
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (uni[i] == uni[j]) cnt++; // �� ���� ���� ���Ͽ� ������ count;
        }
    }

    cout << cnt;
    return 0;
}