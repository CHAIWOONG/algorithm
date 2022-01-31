#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, cnt = 0;
//int arr[16]; //����� ���� �����Ƿ� �ʿ� ����

// ---------------�� k�� ���Ͽ� ���� �࿡���� �Ǵ� �迭 ------------------------
int checked1[50]; // ���� ���� �Ϳ� ���� true/false (i(��) Ȯ��)
int checked2[50]; // ������ �밢�� Ȯ���Ͽ� true/false ( [i(��)+ k(��)] Ȯ��)
int checked3[50]; // ���� �밢�� Ȯ���Ͽ� true/false 
                  // (index ���� ����Ͽ� [n-i(��)-k(��) -1] Ȯ��)

void func(int k)
{
    if (k == n) {
        cnt++;
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            // �̹� true�� üũ�� �ڸ��� �Ѽ� �����Ƿ� ����
            if (checked1[i] || checked2[k + i] || checked3[n - i + k - 1]) continue;

            checked1[i] = 1;
            checked2[k + i] = 1;
            checked3[n - i + k - 1] = 1;
            func(k + 1);
            checked1[i] = 0;
            checked2[k + i] = 0;
            checked3[n - i + k - 1] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    func(0);
    cout << cnt;

    return 0;
}