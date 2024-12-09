#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        long long sOdd = 0, sEven = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i % 2 == 0)
                sEven += a[i];
            else
            {
                sOdd += a[i];
            }
        }
        if (sOdd > sEven)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i % 2 == 0)
                {
                    cout << 1 << " ";
                    continue;
                }
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (i % 2 == 0)
                {
                    cout << a[i] << " ";
                    continue;
                }
                cout << 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}