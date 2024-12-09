/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int NM_MAX = 2021;

const int MOD = 998244353;

int pwr (int a, int b)
{
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * a * pwr(a, (b ^ 1)) % MOD;
    int aux = pwr(a, (b >> 1));
    return 1LL * aux * aux % MOD;
}

int n, m;

int fact[NM_MAX * 2 + 2];
int ifact[NM_MAX * 2 + 2];

int comb (int a, int b)
{
    return 1LL * fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
}

int cntPart (int sum, int cnt)
{
    if(cnt == 0)
        return (sum == 0);
    return comb(sum + cnt - 1, cnt - 1);
}

int upL[NM_MAX + 2][NM_MAX + 2];
int upR[NM_MAX + 2][NM_MAX + 2];
int downL[NM_MAX + 2][NM_MAX + 2];
int downR[NM_MAX + 2][NM_MAX + 2];

int sumUL[NM_MAX + 2][NM_MAX + 2];
int sumUR[NM_MAX + 2][NM_MAX + 2];

int solve (int n, int m, bool strict)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            upL[i][j] = 1LL * cntPart(i, j) * cntPart(i - 1, (m - j + 1)) % MOD;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            upR[i][j] = upL[i][m - j + 1];
            downL[i][j] = upL[n - i + 1][j];
            downR[i][j] = upL[n - i + 1][m - j + 1];
        }
    for(int i = 1; i <= n; i++)
    {
        sumUL[i][0] = 0;
        for(int j = 1; j <= m; j++)
        {
            sumUL[i][j] = sumUL[i][j - 1] + upL[i][j];
            if(sumUL[i][j] >= MOD)
                sumUL[i][j] -= MOD;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        sumUR[i][m + 1] = 0;
        for(int j = m; j >= 1; j--)
        {
            sumUR[i][j] = sumUR[i][j + 1] + upR[i][j];
            if(sumUR[i][j] >= MOD)
                sumUR[i][j] -= MOD;
        }
    }
    int answer = 0;
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(j + 1 + strict <= m)
                answer = (answer + 1LL * downL[i][j] * sumUR[i - 1][j + 1 + strict]) % MOD;
            if(j - 1 - strict >= 1)
                answer = (answer + 1LL * downR[i][j] * sumUL[i - 1][j - 1 - strict]) % MOD;
        }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fact[0] = 1;
    ifact[0] = 1;
    for(int i = 1; i <= max(n, m) * 2; i++)
    {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
        ifact[i] = pwr(fact[i], MOD - 2);
    }
    cout << (solve(n, m, false) + solve(m, n, true)) % MOD << "\n";
    return 0;
}
