#include <bits/stdc++.h>
using namespace std;
int t, m, n, k, x, y, u, v, minm[1000008], minn[1000008], mam[1000008],
    man[1000008];
string s;
char c;
bool check(int k) {
  x = minn[k];
  y = minm[k];
  u = man[k];
  v = mam[k];
  if (u - x >= n || v - y >= m) return false;
  cout << 1 - x << ' ' << 1 - y << '\n';
  return true;
}
void does(char c) {
  if (c == 'U')
    x--;
  else {
    if (c == 'D')
      x++;
    else {
      if (c == 'L')
        y--;
      else
        y++;
    }
  }
}
void solve() {
  cin >> n >> m;
  cin >> s;
  k = s.size();
  x = y = 0;
  for (int i = 1; i <= k; i++) {
    does(s[i - 1]);
    man[i] = max(man[i - 1], x);
    minn[i] = min(minn[i - 1], x);
    mam[i] = max(mam[i - 1], y);
    minm[i] = min(minm[i - 1], y);
  }
  for (int i = k; i >= 0; i--)
    if (check(i)) return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  man[0] = mam[0] = minn[0] = minm[0] = 0;
  cin >> t;
  while (t--) solve();
  return 0;
}
