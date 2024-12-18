#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, mod = 1e9 + 7;
inline int ad(int x, int y) {
  int ans = x + y;
  if (ans > mod) ans -= mod;
  return ans;
}
inline int mu(int x, int y) { return 1LL * x * y % mod; }
inline int wop(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = mu(ret, x);
    y >>= 1;
    x = mu(x, x);
  }
  return ret;
}
int fact[maxn], inv[maxn], lst[maxn], pr[maxn], cnt[maxn];
int num[maxn][20];
int pw[maxn], pww[maxn];
inline void prep() {
  int n = maxn - 5;
  fact[0] = 1;
  for (int i = 1; i < n; i++) fact[i] = mu(fact[i - 1], i);
  for (int i = 0; i < n; i++) inv[i] = wop(fact[i], mod - 2);
  pr[0] = pr[1] = 1;
  for (int i = 2; i < 300005; i++) {
    if (pr[i] == 0) {
      lst[i] = i;
      for (int j = i * 2; j < 300005; j += i) lst[j] = i, pr[j] = 1;
    }
  }
  for (int i = 1; i < n; i++) pw[i] = ad(mu(pw[i - 1], 2), 1);
  pww[0] = 1;
  for (int i = 1; i < n; i++) pww[i] = ad(pww[i - 1], pww[i - 1]);
}
inline int C(int r, int n) {
  if (r < 0 || r > n) return 0;
  return mu(mu(fact[n], inv[n - r]), inv[r]);
}
inline int cal(int x, int y) {
  if (x < 0 || y < 1) return 0;
  if (x == 0) return pw[y];
  int ans = 0;
  for (int i = 1; i <= y; i++)
    ans = ad(ans, mu(pw[i], C(x - 1, x - 1 + y - i)));
  return ans;
}
inline int f(int x, int y) {
  if (y <= x) return cal(x, y);
  int oth = cal(y, x);
  int eq = 0;
  for (int i = 0; i <= min(x, y); i++) eq = ad(eq, mu(C(i, x), C(i, y)));
  oth = ad(oth, eq);
  return ad(pww[x + y], mod - oth);
}
inline int ff(int x, int y) { return f(x + 1, y - 1); }
int ps[20], answer[20];
int solve(vector<int> a, bool rev) {
  int n = a.size();
  for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i - 1];
  int ans = 0;
  for (int j = 1; j < n; j++) {
    int tmp;
    if (rev) tmp = f(ps[j] - 1, ps[n] - ps[j]);
    if (!rev) tmp = ff(ps[j] - 1, ps[n] - ps[j]);
    answer[j] = tmp;
  }
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i + 1; j < n; j++) sum = ad(sum, answer[j]);
    ans = ad(ans, mu(sum, a[i]));
  }
  return ans;
}
int main() {
  prep();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }
  for (int i = 1; i <= 1e6; i++) {
    if (cnt[i] == 0) continue;
    int cur = i;
    while (cur != 1) {
      int p = lst[cur], tav = 0;
      while (cur % p == 0) cur /= p, tav++;
      num[p][tav] += cnt[i];
    }
  }
  int ans = 0;
  for (int i = 2; i <= 300000; i++) {
    if (pr[i]) continue;
    vector<int> a;
    int sum = 0;
    for (int j = 1; j < 20; j++) sum += num[i][j];
    if (sum == 0) continue;
    a.push_back(n - sum);
    for (int j = 1; j < 20; j++) a.push_back(num[i][j]);
    ans = ad(ans, solve(a, 0));
    reverse(a.begin(), a.end());
    ans = ad(ans, solve(a, 1));
  }
  cout << ans << endl;
}
