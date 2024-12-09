#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000000000
int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    else if (a % b)
        return gcd(b, a % b);
    else
        return b;
}
int main()
{
    int p, q;
    cin >> p >> q;
    q /= gcd(p, q);
    map<int, int> res;
    for (int i = 2; i * i <= MAX_N; i++)
    {
        while (q % i == 0)
        {
            q /= i;
            res[i]++;
        }
    }
    if (q != 1)
        res[q]++;
    int ans = 1;
    for (auto p : res)
    {
        ans *= p.first;
    }
    cout << ans << endl;
}

