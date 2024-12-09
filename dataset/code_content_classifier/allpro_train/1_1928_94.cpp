
///Bismillahir Rahmanir Raheem
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vii;
typedef vector<pair<ll, ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vbl;
#define NFS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define PQ priority_queue
#define ff first
#define ss second
#define MP make_pair
#define fore(arr) for (auto &x : (arr))
#define findc(v, x) ((v).find(x) != (v).end())
#define MAX 2000010
#define PI 2 * acos(0.0)
#define torad ((2 * acos(0)) / 180.0)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define SORT(v) sort((v).begin(), (v).end())
#define fill(x, y) memset(x, y, sizeof(x))
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) x *(y / gcd(x, y))
#define bug cout << "*_*\n"
bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int NOD(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                cnt++;
            else
                cnt = cnt + 2;
        }
    }
    return cnt;
}
void dsbl(vector<long long> &v, long long n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.pb(i);
            if (i != (n / i))
                v.pb(n / i);
        }
    }
}
int prime[MAX];
void seivePrime(int n)
{
    for (int i = 1; i <= n; i++)
        prime[i] = 1;

    prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    string a,b;
    cin>>a>>b;
    int red = 0, blue = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i]>b[i])
            red++;
        if(a[i]<b[i])
            blue++;
    }
    if (red > blue)
    {
        cout << "RED\n";
    }
    if (blue > red)
    {
        cout << "BLUE\n";
    }
    if(red==blue)
    {
        cout<<"EQUAL\n";
    }
}
int main()
{
    NFS;

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
