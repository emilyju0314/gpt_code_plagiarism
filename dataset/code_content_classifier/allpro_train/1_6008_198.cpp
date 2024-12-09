#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const long long mod = 1e9 + 7;
vector<int> e[N];
int vis[N];
void dfs(int i, int p, int count) {}
bool comp(pair<long double, int> &a, pair<long double, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  if (a == 0) return 0;
  if (b == 1) return a % mod;
  long long g = (binpow(a, b / 2) % mod) * (binpow(a, b / 2) % mod);
  g %= mod;
  if (b & 1)
    return a * g;
  else
    return g;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    int x, k, g = 0;
    cin >> x >> k;
    map<int, int> m;
    for (int i = 0; i < k; i++) {
      int a, b, c;
      cin >> a;
      if (a == 1) {
        cin >> b >> c;
        m[b]++;
        m[c]++;
        g++;
      } else {
        cin >> b;
        m[b]++;
      }
      g++;
    }
    int mx = x - g - 1, mn;
    mn = mx;
    for (int i = 1; i < x; i++) {
      int cnt = 0;
      while (i + cnt < x && m[i + cnt] == 0) cnt++;
      mx -= cnt / 2;
      if (cnt) i += cnt - 1;
    }
    cout << mx << " " << mn << endl;
  }
}
