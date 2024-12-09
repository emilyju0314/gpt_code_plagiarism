#include <bits/stdc++.h>
using namespace std;
int n, x[2010];
double dp[2010][2010][2][2];
bool ok[2010][2010][2][2];
int pre[2010];
int h;
double p;
int nxt[2010];
double work(int l, int r, int fl, int fr) {
  if (l > r) return 0;
  if (ok[l][r][fl][fr]) return dp[l][r][fl][fr];
  ok[l][r][fl][fr] = 1;
  double ans = 0;
  int rp = min(r, nxt[l]);
  if (rp == r) {
    if (fr == 0) {
      ans += (1 - p) * (min(h, x[r + 1] - x[r] - h) + x[r] - x[l]);
    } else {
      ans += (1 - p) * (min(h, x[r + 1] - x[r]) + x[r] - x[l]);
    }
  } else {
    ans += (1 - p) * ((x[rp] - x[l] + h) + work(rp + 1, r, 1, fr));
  }
  if (fl == 1) {
    ans += p * min(h, x[l] - x[l - 1] - h);
  } else {
    ans += p * min(h, x[l] - x[l - 1]);
  }
  ans += p * work(l + 1, r, 0, fr);
  int lp = max(l, pre[r]);
  if (lp == l) {
    if (fl == 1) {
      ans += p * (min(h, x[l] - x[l - 1] - h) + x[r] - x[l]);
    } else {
      ans += p * (min(h, x[l] - x[l - 1]) + x[r] - x[l]);
    }
  } else {
    ans += p * ((x[r] - x[lp] + h) + work(l, lp - 1, fl, 0));
  }
  if (fr == 1) {
    ans += (1 - p) * min(h, x[r + 1] - x[r]);
  } else {
    ans += (1 - p) * min(h, x[r + 1] - x[r] - h);
  }
  ans += (1 - p) * work(l, r - 1, fl, 1);
  ans /= 2.0;
  return dp[l][r][fl][fr] = ans;
}
int main() {
  scanf("%d %d %lf", &n, &h, &p);
  x[0] = -1e9 - 7;
  x[n + 1] = 1e9 + 7;
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  sort(x + 1, x + n + 1);
  for (int i = 1; i <= n; i++) {
    if (x[i] - x[i - 1] >= h)
      pre[i] = i;
    else
      pre[i] = pre[i - 1];
  }
  for (int i = n; i >= 1; i--) {
    if (x[i + 1] - x[i] >= h)
      nxt[i] = i;
    else
      nxt[i] = nxt[i + 1];
  }
  cout << fixed << setprecision(9) << work(1, n, 0, 1);
}
