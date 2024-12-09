#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }
} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int d;
int a[maxn];
long double dp[maxn][10];
vector<int> ans;
// 迷惑，改成long double就过了，改成 double 第一个样例都过不去
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, d);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[1][a[1] % 10] = log(a[1]);
    for (int i = 1; i <= n; i++)
    {
        dp[i][a[i] % 10] = log(a[i]);
        for (int j = 0; j < 10; j++)
        {
            if (dp[i - 1][j] == 0)
                continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j * a[i] % 10] = max(dp[i - 1][j] + log(a[i]), dp[i][j * a[i] % 10]);
        }
    }
    if (dp[n][d] == 0)
    {
        printf("-1\n");
    }
    else
    {
        bool flag;
        for (int i = n; i >= 1; i--)
        {
            if (dp[i][d] == dp[i - 1][d])
                continue;
            ans.push_back(a[i]);
            flag = false;
            for (int j = 0; j < 10; j++)
            {
                if (j * a[i] % 10 == d && dp[i - 1][j] + log(a[i]) == dp[i][j * a[i] % 10])
                {
                    d = j;
                    flag = true;
                    break;
                }
            }
            if (!flag)
                break;
        }
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}