#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int num;
ll mnsum;
ll a[100001];

// �������� �䱸�ϴ� ��Ȳ�� ��Ȯ�ϰ� �ľ��� �ʿ䰡 �ִ�.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> num >> mnsum;

    for (int i = 0; i < num; i++)
        cin >> a[i];

    //sort(a, a + num);

    int en = 0;
    int mnlen = num;
    ll tmpsum = 0;

    // ���� �ּ� ���� �ε����� ���ؼ� �κ����� �����ϴ� ���� �ε����� ���ϸ�, (���̸� �ϴ� �ſ� ������)
    // ���� �ε����� �����ϰ� �� ���, ���� �ε����� ���ų� �ϳ��� �����Ѵ� (���Ŀ� �ٿ����� �� ���� ��)
    for (int st = 0; st < num; st++) {

        while (en < num && tmpsum < mnsum) { // �κ��� ������ �����Ǹ� ���� ����
            en++;
            if (en != num) tmpsum += a[en];
        }
        if (en == num) break; // ������ en�� �迭 ������ num�� ������ ���� ��Ȳ�̸� ����
        mnlen = min(mnlen, en - st + 1);
        tmpsum -= a[st]; // st�� ������ ���̹Ƿ� �κ��տ��� ����
    }

    if (mnlen == num) mnlen = 0;
    cout << mnlen;

    return 0;
}