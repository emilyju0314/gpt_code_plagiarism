#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int n;
int a[200000];
int ri[200000];
int le[200000];
int ans[200000];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      ri[i] = i;
      continue;
    }
    int j = i + 1;
    while (1) {
      if (a[i] > a[j]) {
        ri[i] = j - 1;
        break;
      }
      if (j == n - 1) {
        ri[i] = j;
        break;
      }
      if (j == ri[j])
        j++;
      else
        j = ri[j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      le[i] = i;
      continue;
    }
    int j = i - 1;
    while (1) {
      if (a[i] > a[j]) {
        le[i] = j + 1;
        break;
      }
      if (j == 0) {
        le[i] = j;
        break;
      }
      if (j == le[j])
        j--;
      else
        j = le[j];
    }
  }
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n; i++) {
    ans[ri[i] - le[i]] =
        ((ans[ri[i] - le[i]]) > (a[i]) ? (ans[ri[i] - le[i]]) : (a[i]));
  }
  for (int i = n - 1 - 1; i >= 0; i--)
    ans[i] = ((ans[i]) > (ans[i + 1]) ? (ans[i]) : (ans[i + 1]));
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
int main() {
  solve();
  return 0;
}
