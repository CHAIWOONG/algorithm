#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m;

vector<char> str; // �Է� character ������ ���� vector
vector<char> arr; // ��й�ȣ �ϼ� character ������ ���� vector

int used[200]; // �ƽ�Ű �ڵ忡 ���� �ҹ��� ���ĺ� used �迭 ����

int check() { // ���ǿ� �˸��� ��Ȳ�� ����ϱ� ���� check �Լ�

    int m_flag = 0; // ���� Ȯ�� flag
    // ���� ���� �ľ�
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') m_flag++;
    }
    // ���� 2���̻�, ���� 1�� �̻��� ��츸 true
    if (m_flag >= 1 && n - m_flag >= 2) return 1;
    return 0;
}

void func(int k) {

    if (k == n) { // base condition
        if (check()) // ��,���� ���� ���ǿ� �´°Ÿ� ���
        {
            for (int i = 0; i < n; i++)
                cout << arr[i];
            cout << "\n";
        }
        return;
    }
    else {
        for (int i = 0; i < m; i++) {

            if (!used[str[i]]) { // �ߺ� ���Ÿ� ���� ����� �� Ȯ��

                if (k != 0 && arr[k - 1] > str[i]) continue; // ���ڸ����� ������ ����
                else arr.push_back(str[i]);

                used[str[i]] = 1;
                func(k + 1); // ������ ��� ������ ���� �ڸ��� ��ͷ� �߰�
                used[str[i]] = 0; // ���� ���̽������� ����� ���� �� ����� �ٽ� used 0
                arr.pop_back(); // �ش� �ڸ������� Ȯ�εȰŴ� pop
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        char temp; cin >> temp;
        str.push_back(temp); // vector�� �ǵ����̸� push_back���� �߰�
    }

    sort(str.begin(), str.end());
    func(0);

    return 0;
}