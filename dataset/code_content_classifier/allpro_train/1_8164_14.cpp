#include <bits/stdc++.h>
using namespace std;
//----------MACROS----------
#define int long long
#define pb push_back
#define mint map<int, int>
#define sint set<int>
#define mp make_pair
#define F first
#define S second
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>
#define me max_element
#define ne min_element
#define v vector
#define nl cout << '\n'
#define B(a) a.begin()
#define E(a) a.end()
#define debug(x) cout << "------> " << x << endl
#define pair_debug(x, y) cout << "------> " << x << " ------> " << y << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fre(x, a) for (auto x : a)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repe(i, a, b) for (int i = a; i <= b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define IOS ios_base::sync_with_stdio(false)
#define setpr(x) cout << setprecision(x) << fixed
#define sz size()
//----------CONSTANTS----------
const int inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const int mod = 1000000007;
//----------GLOBALS----------
map<int, bool> m;
vector<int> graph[10001];
bool vis[10001];
//----------SNIPPETS---------

/*-----Greatest Common Divisor-----*/
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

/*-----Sieve of Eratosthenes-----*/
vector<bool> SieveofEratosthenes(int n)
{
  vector<bool> primes(n + 1, true);
  primes[0] = 0;
  primes[1] = 0;
  for (int i = 2; i * i <= n; i++)
  {
    if (primes[i])
    {
      for (int j = i * i; j <= n; j += i)
      {
        primes[j] = false;
      }
    }
  }

  return primes;
}

/*-----LCM-----*/
int lcm(int a, int b)
{
  return (a / gcd(a, b)) * b;
}

/*-----Bipartite Graph Test-----*/
int col[10001];
bool checkBipartite(int n, int c)
{
  vis[n] = true;
  col[n] = c;
  for (auto x : graph[n])
  {
    if (!vis[x])
    {
      if (checkBipartite(x, c ^ 1) == false)
        return false;
    }
    else if (col[n] == col[x])
      return false;
  }
  return true;
}

/*-----Checking for Palindrome-----*/
bool isPalindrome(string s, int n)
{
  int i;
  rep(i, 0, n / 2)
  {
    if (s[i] != s[n - i - 1])
      return false;
  }
  return true;
}
//----------SOLUTION----------
void solve()
{
  int n;
  cin >> n;
  if(n%2050==0 && n/2050>0)
  {
    int x = n / 2050;
    int cnt = 0;
    while(x>0){
      cnt += x % 10;
      x /= 10;
    }
    cout << cnt;
  }
  else
    cout << -1;
  nl;
}

bool google = false;
//----------MAIN----------
int32_t main()
{
  IOS;
  cin.tie(0);
  cout.tie(0);
  int t = 1, mn = 1;
  bool tc = true;
  if (tc)
    cin >> t;
  //google = true;
  while (t--)
  {
    if (google)
      cout << "Case #" << mn++ << ": ";
    solve();
  }
  return 0;
}