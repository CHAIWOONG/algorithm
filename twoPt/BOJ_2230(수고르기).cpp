#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll mndiff;
ll a[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> mndiff;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    // ù��°�� i�� �����Կ� ���� a[j] - a[i]�� m �̻��� �Ǵ� ������ ���� j ���� ����
    // �ι�°�� �� i�� ���� a[j] - a[i]�� m �̻��� �Ǵ� ������ ���� j�� ã�� ���Ŀ��� a[j+1], a[j+2], ���� Ȯ���� �ʿ䰡 ����

    int en = 0;
    ll tmpdiff = 0, mn = 2000000001;

    for (int st = 0; st < n; st++) { // �ϳ��� pase���� st�� n������ ����

        // ���̰� ���� ��, en�� n�� ���� �ʴ� �������� en�� ������Ŵ
        while (en < n && a[en] - a[st] < mndiff) en++;
        if (en == n) break; // ������ en�� n�� ������ ������ ����
        mn = min(mn, a[en] - a[st]); // �ּ��� ���̸� ���ؾ� �ϹǷ� ����
    }

    cout << mn;
    return 0;
}