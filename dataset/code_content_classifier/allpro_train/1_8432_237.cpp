#include <bits/stdc++.h>
using namespace std;
long long cache[200002];
int e[200002];
int a[200002];
int n;
long long dp(int x) {
  int curr_x = x;
  long long &ret = cache[x];
  if (e[x] == 2) return ret;
  if (e[x] == 1) return -1e18;
  e[x] = 1;
  ret = a[x];
  x += a[x];
  if (x < 1 || x > n) {
    e[curr_x] = 2;
    return ret;
  }
  ret += a[x];
  x -= a[x];
  if (x == 1) return -1e18;
  if (x < 1 || x > n) {
    e[curr_x] = 2;
    return ret;
  }
  ret += dp(x);
  if (e[x] == 1)
    ret = -1e18;
  else
    e[curr_x] = 2;
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
    cache[i] = -1e17;
  }
  for (int i = 1; i < n; i++) {
    int x = i + 1;
    long long y = i;
    if (x < 1 || x > n) {
      cout << y << endl;
      continue;
    }
    y += a[x];
    x -= a[x];
    if (x < 1 || x > n) {
      cout << y << endl;
      continue;
    }
    y += dp(x);
    y = max(y, -1LL);
    cout << y << endl;
  }
}
