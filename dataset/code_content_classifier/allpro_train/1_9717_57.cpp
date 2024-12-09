#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
int ans[N], a[N], dp[N], sum[N];
int n, k, len, answer = 2100000000;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
int check(int mid, int op) {
  int x;
  for (int i = 1; i <= n; i++) {
    if (i - len < 0)
      x = sum[i] - mid;
    else
      x = dp[i - len] - sum[i - len] + sum[i] - mid;
    dp[i] = max(dp[i - 1], x);
    if (dp[i - 1] > x) ans[i] = ans[i - 1];
    if (dp[i - 1] < x) ans[i] = ans[i - len] + 1;
    if (dp[i - 1] == x) ans[i] = min(ans[i - 1], ans[i - len] + 1);
  }
  if (op) answer = min(answer, sum[n] - dp[n] - k * mid);
  return ans[n];
}
int main() {
  n = read(), k = read(), len = read();
  cin >> s;
  for (int i = 1; i <= n; i++) {
    a[i] = islower(s[i - 1]) > 0;
    sum[i] = sum[i - 1] + a[i];
  }
  int l = 0, r = len;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid, 0) <= k)
      r = mid;
    else
      l = mid + 1;
  }
  check(l, 1);
  for (int i = 1; i <= n; i++) {
    a[i] = isupper(s[i - 1]) > 0;
    sum[i] = sum[i - 1] + a[i];
  }
  l = 0, r = len;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid, 0) <= k)
      r = mid;
    else
      l = mid + 1;
  }
  check(l, 1);
  printf("%d", answer);
  return 0;
}
