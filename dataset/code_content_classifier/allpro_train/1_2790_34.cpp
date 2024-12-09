#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;

int a[400], ans[400];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i <= n / 2 + n % 2)
                ans[2 * (i - 1) + 1] = a[i];
            else
                ans[(n - i + 1) * 2] = a[i];
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
