#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e6 + 9;
const int MAXN = 10100;
const long double pi = acos(-1);
const long long mod = 1e8;
long long po(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long x = po(a, b / 2);
  x *= x % mod;
  if (b % 2) {
    x *= a % mod;
  }
  return x % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else {
    gcd(b, a % b);
  }
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool cmp(int a, int b) { return (a > b); }
int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
map<string, vector<long long> > m;
map<string, bool> vis;
char aa[MX];
vector<pair<long long, long long> > mm;
vector<long long> pp;
bool pal(string x) {
  int l = x.length();
  for (int i = 0; i <= l / 2; i++) {
    if (x[i] != x[l - i - 1]) {
      return 0;
    }
  }
  return 1;
}
set<string> se;
map<string, vector<long long> >::iterator it;
map<string, multiset<long long> >::iterator tt, itt;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    int x;
    scanf("%s", aa);
    s = aa;
    scanf("%d", &x);
    m[s].push_back(x);
    se.insert(s);
  }
  for (it = m.begin(); it != m.end(); ++it)
    sort(it->second.begin(), it->second.end());
  long long ans = 0;
  long long mx = 0;
  for (it = m.begin(); it != m.end(); it++) {
    string s = it->first;
    if (pal(s)) {
      while (!m[s].empty()) {
        long long x = m[s].back(), y;
        m[s].pop_back();
        if (m[s].size())
          y = m[s].back(), m[s].pop_back();
        else
          y = -1000000;
        if (y >= 0) {
          ans += x + y;
          continue;
        }
        if (x < 0) {
          break;
        }
        if (x + y <= 0) {
          pp.push_back(x);
          break;
        } else {
          ans += x + y;
          pp.push_back(-y);
        }
      }
    } else {
      string q = s;
      reverse(q.begin(), q.end());
      while (m[q].size() > 0 && m[s].size() > 0) {
        long long x = m[s].back();
        long long y = m[q].back();
        if (x + y <= 0) {
          break;
        } else {
          ans += x + y;
          m[s].pop_back();
          m[q].pop_back();
        }
      }
    }
  }
  if (!pp.empty()) mx = *max_element(pp.begin(), pp.end());
  ans += mx;
  cout << ans;
  return 0;
}
