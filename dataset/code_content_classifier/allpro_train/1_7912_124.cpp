#include <bits/stdc++.h>
using namespace std;
namespace {
template <class T>
ostream& operator<<(ostream& os, const vector<T>& vs) {
  if (vs.empty()) return os << "[]";
  os << "[" << vs[0];
  for (int i = 1; i < vs.size(); i++) os << " " << vs[i];
  return os << "]";
}
int a, b, N;
void input() { cin >> a >> b >> N; }
int pow10(int n) {
  int r = 1;
  for (int i = 0; i < n; i++) r *= 10;
  return r;
}
vector<int> xs;
void dfs(int i, int n) {
  xs.push_back(n);
  if (i == 7) {
    return;
  }
  dfs(i + 1, n * 10 + a);
  dfs(i + 1, n * 10 + b);
}
const long long MOD = 1000000007;
long long extgcd(long long a, long long b, long long& x, long long& y) {
  long long g = a;
  x = 1LL;
  y = 0LL;
  if (b != 0LL) {
    g = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  return g;
}
long long inverse(long long v) {
  long long x, y;
  if (extgcd(v, MOD, x, y) == 1LL) return (x + MOD) % MOD;
  return 0;
}
const int L = int(1e6 + 1);
long long memo[L];
void solve() {
  memo[0] = 1;
  for (int k = 1; k <= N; k++) {
    memo[k] = (((memo[k - 1] * (N - k + 1)) % MOD) * inverse(k)) % MOD;
  }
  dfs(0, 0);
  long long ans = 0;
  for (int i = 0; i < xs.size(); i++) {
    int x = xs[i];
    int p = b * N - x;
    if (p < 0) continue;
    if (p % (b - a) != 0) continue;
    int k = p / (b - a);
    if (k < 0 || k > N) continue;
    ans = (ans + memo[k]) % MOD;
  }
  cout << ans << endl;
}
}  // namespace
int main() {
  input();
  solve();
  return 0;
}
