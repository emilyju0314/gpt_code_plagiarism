#include <bits/stdc++.h>

#define taskname ""
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;

template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 5e2 + 10;
const int maxM = 5e2 + 10;

int n, m, a[maxN][maxM], c[17];

ll GCD(ll a, ll b)
{
    return b == 0 ? a : GCD(b, a % b);
}

ll LCM(ll a, ll b)
{
    return a / GCD(a, b) * b;
}

void solve()
{
    int g = 1;
    for1(i, 16)
    {
        g = LCM(g, i);
    }
    vi vec;
    for1(i, 32)
    {
        if (i * i * i * i <= 1e6)
        {
            vec.eb(i * i * i * i);
        }
    }
    for1(i, 16)
    {
        for (int j = i; j <= 1e6; j += i)
        {
            if (binary_search(all(vec), abs(j - g)))
            {
                c[i] = j;
                break;
            }
        }
    }
    cin >> n >> m;
    for1(i, n)
    {
        for1(j, m)
        {
            cin >> a[i][j];
        }
    }
    for1(i, n)
    {
        for1(j, m)
        {
            if ((i + j) & 1)
            {
                cout << g << " ";
            }
            else
            {
                cout << c[a[i][j]] << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
