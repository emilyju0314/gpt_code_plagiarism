///Bismillahir Rahmanir Raheem
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define PI 2 * acos(0.0)
#define NFS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fore(arr) for (auto &x : (arr))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define SORT(v) sort((v).begin(), (v).end())
#define FIND(v, x) ((v).find(x) != (v).end())
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) x *(y / gcd(x, y))
#define MAX 2000010
#define bug cout << "*_*\n"
using namespace std;
int toint(char c)
{
    return c - 48;
}
char tochar(int c)
{
    return (c + 48);
}
bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
double ciel(double a, double b)
{
    return (a + (b - 1)) / b;
}
void solve()
{
    ll A, B, n;
    cin >> A >> B >> n;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.pb({x, 0});
    }
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v[i].second = x;
    }
    sort(all(v));
    ll mx = -1;
    fore(v)
    {
        ll a = x.first;
        ll b = x.second, f;
        if (b % A == 0)
        {
            f = (b / A);
        }
        else
        {
            f = (b / A) + 1;
        }
        B = B - (f * a);
        // cout << B << endl;
        mx = max(mx, a);
    }
    B += mx;
    if (B <= 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main()
{
    // NFS;
#ifndef ONLINE_JUDGE
    freopen("D:/code/C++/OJ/in.txt", "r", stdin);
    freopen("D:/code/C++/OJ/out.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}