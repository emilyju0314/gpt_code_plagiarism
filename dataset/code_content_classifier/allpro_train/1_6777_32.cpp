#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define test(x) \
    int x;      \
    cin >> x;   \
    while (x--)
#define lp(i, a, b) for (int i = a; i <= b; i++)
#define fo(i, n) lp(i, 0, n - 1)
#define arrin(a, n) \
    fo(i, n) { cin >> a[i]; }
#define arr2in(a, n, m) \
    fo(i, n) { fo(j, m) cin >> a[i][j]; }
#define arrout(arr, n) \
    fo(i, n) { cout << arr[i] << " "; }
#define endl "\n"
#define sq(x) (x) * (x)
#define pb push_back
#define ppb pop_back
#define debug(x) cout << #x << " : " << x << endl;
#define debugarr(a, x) cout << #a << "[" << x << "]" \
                            << " : " << a[x] << endl;
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define clock cerr << "Time elapsed: " << 1000 * 1.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
#define mod 1000000007
int SOD(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum = sum + n % 10;
        n /= 10;
    }
    return sum;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int pow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}
int powmod(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y % 2 == 1)
            res = (res * x) % p;
        y /= 2;
        x = (x * x) % p;
    }
    return res;
}
// ----------------------------
signed main()
{
    fastio;
    test(t)
    {
        int ax,ay;
        int bx,by;
        int fx,fy;
        cin>>ax>>ay>>bx>>by>>fx>>fy;
        if((ay==by || ax==bx) && ((fx==ax && fx==bx && fy>min(ay,by) && fy<max(ay,by)) || (fy==ay && fy==by && fx>min(ax,bx) && fx<max(ax,bx))))
        {
            cout<<abs(bx-ax)+abs(by-ay)+2<<endl;
        }
        else{
            cout<<abs(bx-ax)+abs(by-ay)<<endl;
        }
    }
}