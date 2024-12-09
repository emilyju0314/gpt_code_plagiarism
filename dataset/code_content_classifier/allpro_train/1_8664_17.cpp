#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
const long long inf = (long long)1e16;
const long double eps = 1e-12;
const long long N = (int)2e5 + 5;
const long long LOGN = 19;
const long double PI = 3.14159265358979323846;
inline long long mul(long long a, long long b, long long m = mod) {
  return (long long)(a * b) % m;
}
inline long long add(long long a, long long b, long long m = mod) {
  a += b;
  if (a >= m) a -= m;
  if (a < 0) a += m;
  return a;
}
inline long long power(long long a, long long b, long long m = mod) {
  if (b == 0) return 1;
  if (b == 1) return (a % m);
  long long x = power(a, b / 2, m);
  x = mul(x, x, m);
  if (b % 2) x = mul(x, a, m);
  return x;
}
int n, a[N], spf[N], ans, curr, curr_src;
vector<int> adj[N], pf[N], primes;
bool isPrime[N], vis[N], go[N];
set<int> fact(int k) {
  set<int> ret;
  while (k > 1) {
    ret.insert(spf[k]);
    k /= spf[k];
  }
  return ret;
}
void pre() {
  for (int i = 0; i < N; i++) spf[i] = i;
  memset(isPrime, true, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < N; i++) {
    if (isPrime[i]) {
      for (int j = 2 * i; j < N; j += i) {
        if (spf[j] == j) spf[j] = i;
        isPrime[j] = false;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (isPrime[i]) primes.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    set<int> S = fact(a[i]);
    for (int it : S) pf[it].push_back(i);
  }
}
void dfs(int src, int par, int dep) {
  if (dep > curr) {
    curr = dep;
    curr_src = src;
  }
  vis[src] = true;
  for (int u : adj[src]) {
    if (par == u) continue;
    if (!go[u]) continue;
    dfs(u, src, dep + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (0) {
    freopen("C:\\Users\\Dishant\\Desktop\\Collection-DEV c++\\input.txt", "r",
            stdin);
    freopen("C:\\Users\\Dishant\\Desktop\\Collection-DEV c++\\output.txt", "w",
            stdout);
  }
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  pre();
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int p : primes) {
    for (int src : pf[p]) go[src] = true;
    for (int src : pf[p]) {
      if (vis[src]) continue;
      curr = 0;
      curr_src = src;
      dfs(src, -1, 1);
      curr = 1;
      dfs(curr_src, -1, 1);
      ans = max(ans, curr);
    }
    for (int src : pf[p]) {
      go[src] = false;
      vis[src] = false;
    }
  }
  cout << ans;
  return 0;
}
