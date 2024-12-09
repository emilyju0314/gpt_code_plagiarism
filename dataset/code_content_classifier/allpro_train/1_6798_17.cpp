#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod) {
  x += y;
  if (x >= mod) x -= mod;
}
void et() {
  puts("-1");
  exit(0);
}
long long fastPow(long long x, long long y, int mod) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
map<int, int> f[10005];
vector<int> mp[10005];
void add(int i, int j) {
  f[i][i]++;
  f[j][j]++;
  f[i][j] = 1000000007 - 1;
  f[j][i] = 1000000007 - 1;
  mp[j].push_back(i);
}
void fmain() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < k; i++) {
    for (int j = i + 1; j <= k; j++) {
      add(i, j);
    }
  }
  for (int i = k + 1; i <= n; i++) {
    for (int(j) = 0; (j) < (int)(k); (j)++) {
      scanf("%d", &m);
      add(m, i);
    }
  }
  long long ans = 1;
  for (int i = n; i > 1; i--) {
    (ans *= f[i][i]) %= 1000000007;
    long long tmp = fastPow(f[i][i], 1000000007 - 2, 1000000007);
    for (int j : mp[i]) {
      for (int c : mp[i]) {
        f[j][c] += 1000000007 -
                   (long long)f[i][c] * tmp % 1000000007 * f[j][i] % 1000000007;
        f[j][c] %= 1000000007;
      }
    }
  }
  printf("%lld\n", ans);
}
int main() {
  fmain();
  return 0;
}
