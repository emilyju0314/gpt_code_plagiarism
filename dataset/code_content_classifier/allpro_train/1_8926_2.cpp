#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "URDL";
const long long MOD2 = (long long)998244353 * (long long)998244353;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 998244353) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
const int M = 1035;
int c[M], L[M], R[M], pre[M], pos[1035];
int rc[M], cnt;
int dp[1035][1035], dpm[1035][1035];
inline int dfs(int l, int r) {
  if (r <= l) return 1;
  if (l + 1 == r && c[l] == c[r]) return 1;
  int& tmp = dp[l][r];
  if (tmp != -1) return tmp;
  int minColor = dpm[l][r];
  int lt = L[minColor], rt = R[minColor];
  int wayL = dfs(l, lt - 1), wayR = dfs(rt + 1, r);
  if (lt > l)
    for (int z = lt - 1; z >= l; z--) {
      assert(L[c[z]] <= z);
      z = L[c[z]];
      addmod(wayL, (long long)dfs(l, z - 1) * dfs(z, lt - 1) % 998244353);
    }
  if (rt < r) {
    for (int z = rt + 1; z <= r; z++) {
      assert(R[c[z]] >= z);
      z = R[c[z]];
      addmod(wayR, (long long)dfs(rt + 1, z) * dfs(z + 1, r) % 998244353);
    }
  }
  tmp = 1;
  for (int z = rt; z != lt; z = pre[z]) {
    tmp = (long long)tmp * dfs(pre[z] + 1, z - 1) % 998244353;
  }
  tmp = (long long)tmp * wayL % 998244353 * wayR % 998244353;
  return tmp;
}
void init() {
  memset(dp, -1, sizeof dp);
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    dpm[i][i] = c[i];
    for (int j = i + 1; j <= m; j++) {
      dpm[i][j] = min(dpm[i][j - 1], c[j]);
    }
  }
}
void fmain(int tid) {
  scanf("%d%d", &n, &m);
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    scanf("%d", c + i);
    if (cnt == 0 || rc[cnt] != c[i]) rc[++cnt] = c[i];
  }
  m = cnt;
  for (int(i) = 1; (i) <= (int)(m); (i)++) c[i] = rc[i];
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    if (L[c[i]] == 0) L[c[i]] = i;
    maxtt(R[c[i]], i);
  }
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    pre[i] = pos[c[i]];
    pos[c[i]] = i;
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    for (int(j) = 1; (j) <= (int)(n); (j)++)
      if (i != j) {
        if (L[i] < L[j] && R[i] < R[j] && L[j] < R[i]) {
          puts("0");
          return;
        }
        if (L[i] < L[j] && R[i] > R[j] && j < i) {
          puts("0");
          return;
        }
      }
  if (m > n + n) {
    puts("0");
    return;
  }
  init();
  printf("%d\n", dfs(1, m));
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
