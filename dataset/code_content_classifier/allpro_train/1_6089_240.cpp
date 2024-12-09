#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& a) {
  out << "[";
  for (auto it = a.begin(); it != a.end(); ++it) {
    if (it != a.begin()) out << ", ";
    out << *it;
  }
  return out << "]";
}
mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));
const int INF = 1e9;
const long long INF64 = 1e18;
const int MOD = 1e9 + 7;
const long double PI = acosl(-1.0);
const long double EPS = 1e-9;
const int N = 100 * 1000 + 13;
const int LOG = 40;
const int M = N * LOG;
int n;
long long a[N];
long long suf[N];
int k;
int to[M][2];
int cnt[M];
bool read() {
  if (scanf("%d", &n) != 1) return false;
  for (int i = 0; i < int(n); ++i) scanf("%lld", &a[i]);
  return true;
}
void add(long long first) {
  int v = 0;
  for (int i = LOG - 1; i >= 0; i--) {
    int dir = (first >> i) & 1;
    if (to[v][dir] == -1) to[v][dir] = k++;
    v = to[v][dir];
    cnt[v]++;
  }
}
void del(long long first) {
  int v = 0;
  for (int i = LOG - 1; i >= 0; i--) {
    int dir = (first >> i) & 1;
    v = to[v][dir];
    cnt[v]--;
  }
}
long long get(long long first) {
  int v = 0;
  long long ans = 0;
  for (int i = LOG - 1; i >= 0; i--) {
    int dir = (first >> i) & 1;
    if (to[v][dir ^ 1] != -1 && cnt[to[v][dir ^ 1]] > 0) {
      ans |= (1ll << i);
      v = to[v][dir ^ 1];
    } else if (to[v][dir] != -1 && cnt[to[v][dir]] > 0) {
      v = to[v][dir];
    } else {
      return 0;
    }
  }
  return ans;
}
void solve() {
  k = 1;
  memset(to, -1, sizeof(to));
  suf[n] = 0;
  for (int i = n; i; i--) suf[i - 1] = suf[i] ^ a[i - 1];
  for (int i = 0; i < int(n + 1); ++i) add(suf[i]);
  long long ans = suf[0];
  long long cur = 0;
  for (int i = 0; i < int(n); ++i) {
    ans = max(ans, get(cur));
    cur ^= a[i];
    del(suf[i]);
  }
  printf("%lld\n", ans);
}
int main() {
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  if (read()) {
    solve();
  }
}
