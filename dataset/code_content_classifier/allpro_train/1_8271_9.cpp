#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
string s;
long long b[100100], a[100100], n, m, ans;
int main() {
  cin >> n >> m;
  cin >> s;
  m--;
  for (int i = 1; i < n; i++)
    if (s[i] != s[i - 1]) b[i] = 1;
  b[n] = 0;
  for (int i = n - 1; i >= 0; i--) b[i] += b[i + 1];
  ans = 0;
  for (int i = 0; i < n; i++) ans += m * (b[i + 1] + 1);
  for (int i = 0; i < n; i++) b[i] = 0;
  for (int i = 0; i < n - 1; i++)
    if (s[i] != s[i + 1]) b[i + 1] = 1;
  for (int i = 1; i <= n; i++) b[i] += b[i - 1];
  for (int i = 1; i < n; i++) ans += m * b[i];
  int r = 0;
  for (int l = 0; l < n - 1; l++) {
    if (s[l] == s[l + 1]) continue;
    r = max(r, l + 2);
    while (r < n && s[r] == s[r - 2]) r++;
    ans -= r - l - 1;
  }
  cout << ans << endl;
  return 0;
}
