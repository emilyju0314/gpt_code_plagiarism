#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using namespace std;
using ll = long long;
struct Edge
{
    ll to;
    ll cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, ll>;
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), v.end()
const ll MOD = 1000000007;
const ll nmax = 8;
const ll INF = LLONG_MAX;
const int MAX = 510000;
bool graph[nmax][nmax];
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;

    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

vector<vector<ll>> dist = vector<vector<ll>>(nmax, vector<ll>(nmax, INF));
void warshall_floyd(ll n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a / g * b;
}

ll mulMod(ll a, ll b)
{
    return (((a % MOD) * (b % MOD)) % MOD);
}

ll powMod(ll a, ll p)
{
    if (p == 0)
    {
        return 1;
    }
    else if (p % 2 == 0)
    {
        ll half = powMod(a, p / 2);
        return mulMod(half, half);
    }
    else
    {
        return mulMod(powMod(a, p - 1), a);
    }
}

ll ceil(ll a, ll b)
{
    return (a + b - 1) / b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, k;
    cin >> n >> q >> k;
    vector<ll> a(n);
    vector<ll> aida(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        aida[i] = a[i + 1] - a[i - 1] - 2;
    }
    for (int i = 0; i < n - 1; i++)
    {
        aida[i + 1] += aida[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << aida[i] << " ";
    // }
    // cout << endl;

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        --l;
        --r;

        ll ans = 0;
        if (l == r)
        {
            cout << k - 1 << "\n";
            continue;
        }
        if (l - r == 1)
        {
            ans += a[l + 1] - 1 - 1;
            ans += k - a[r - 1] - 1;
        }
        else
        {
            ans += a[l + 1] - 1 - 1;
            ans += k - a[r - 1] - 1;
            ans += aida[r-1]-aida[l];
        }
        cout << ans << "\n";
    }

    return 0;
}