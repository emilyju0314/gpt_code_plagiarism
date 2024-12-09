#include <bits/stdc++.h>
using namespace std;
long long a[100], th[11];
int n;
int prime[1000055], cnt, isprime[1000055];
int num[11], temp[11][11];
int p[11];
int ans;
int cal(long long nn) {
  long long k = nn;
  int res = 0;
  for (int i = 0; (long long)prime[i] * prime[i] <= k; ++i)
    if (k % prime[i] == 0) {
      do {
        k /= prime[i];
        res++;
      } while (k % prime[i] == 0);
    }
  if (k > 1) res++;
  return res;
}
void solve(int pos, int now) {
  if (pos == n) {
    bool f = true;
    for (int i = 1; i < n; ++i)
      if (p[i] == i) {
        f = false;
        break;
      }
    if (!f) now++;
    ans = min(ans, now);
    return;
  }
  if (pos == 0) {
    p[pos] = pos;
    if (num[pos] == 1)
      now = 1;
    else
      now = num[pos] + 1;
    solve(pos + 1, now);
  } else {
    int add = 0;
    for (int i = 0; i < pos; ++i)
      if (a[i] % a[pos] == 0) {
        temp[i][++temp[i][0]] = pos;
        long long e = 1;
        bool f = true;
        for (int k = 1; k <= temp[i][0]; ++k) {
          if (e > a[i] / a[temp[i][k]]) {
            f = false;
            break;
          }
          e *= a[temp[i][k]];
        }
        if (a[i] % e) f = false;
        if (!f) {
          --temp[i][0];
          continue;
        }
        if (num[pos] > 1)
          add = 1;
        else
          add = 0;
        p[pos] = i;
        solve(pos + 1, now + add);
        --temp[i][0];
      }
    p[pos] = pos;
    add = num[pos];
    if (num[pos] > 1) add++;
    solve(pos + 1, now + add);
  }
}
int main() {
  for (int i = 2; i < 1000055; ++i)
    if (!isprime[i]) {
      prime[cnt++] = i;
      for (int j = i; j < 1000055; j += i) isprime[j] = 1;
    }
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int idx = i;
    for (int j = i + 1; j < n; ++j)
      if (a[j] > a[idx]) idx = j;
    if (idx != i) swap(a[i], a[idx]);
  }
  for (int i = 0; i < n; ++i) num[i] = cal(a[i]);
  if (n == 1) {
    if (num[0] == 1)
      cout << 1;
    else
      cout << num[0] + 1;
    return 0;
  }
  ans = 1000000000;
  solve(0, 0);
  cout << ans;
  return 0;
}
