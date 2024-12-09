#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
char s[maxn];
int n;
int mn[maxn];
int v[maxn];
int solve() {
  int l = 0, r = 0, ans = 0;
  mn[n + 1] = inf;
  for (int i = n; i >= 1; i--) {
    if (s[i] == ')')
      r++;
    else
      r--;
    v[i] = r;
    mn[i] = min(mn[i + 1], r);
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(')
      l++;
    else
      l--;
    if (l < 0) return 0;
    if (s[i] == '(' && l >= 2 && mn[i + 1] >= 0 && v[i + 1] == l - 2) ans++;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> (s + 1);
  int l = 0, r = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == ')')
      r++;
    else
      l++;
  if (l - r == 2) {
    cout << solve() << "\n";
  } else if (r - l == 2) {
    reverse(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++) s[i] = (s[i] == '(') ? ')' : '(';
    cout << solve() << "\n";
  } else {
    cout << "0\n";
  }
  return 0;
}
