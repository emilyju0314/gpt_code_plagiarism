#include <bits/stdc++.h>
using namespace std;

vector<int> factorize(int x)
{
    vector<int> v;
    for (int i = 2; i * i <= x; ++i)
    {
        while (x % i == 0) {
            v.push_back(i);
            x /= i;
        }
    }
    if (x != 1) {
        v.push_back(x);
    }
    return v;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T, a, b, k;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> k;
        if(k == 1)
        {
            int mx = max(a, b);
            int mn = min(a, b);
            if(a == b || mx % mn > 0)
                cout << "NO" << "\n";
            else
                cout << "YES" << "\n";
        }
        else
        {
            vector<int> V1 = factorize(a);
            vector<int> V2 = factorize(b);
            cout << (V1.size() + V2.size() >= k ? "YES\n" : "NO\n");
        }
    }

    return 0;
}