#include <bits/stdc++.h>
using namespace std;
const int maxh = 100000 + 10;
int a[maxh];
int h;
const int maxn = 200000 + 10;
int fa1[maxn], fa2[maxn];
void solve(int s) {
  cout << "ambiguous\n";
  int i = 1;
  fa1[1] = fa2[1] = 0;
  int now = 2, l = 1, r = 1;
  while (i <= s) {
    while (now <= r + a[i]) {
      fa1[now] = fa2[now] = r;
      ++now;
    }
    l = r + 1, r = r + a[i];
    ++i;
  }
  while (now <= r + a[i]) {
    fa1[now] = l;
    fa2[now] = fa2[now - 1] == l ? l + 1 : l;
    ++now;
  }
  l = r + 1, r = r + a[i];
  ++i;
  while (i <= h) {
    while (now <= r + a[i]) {
      fa1[now] = fa2[now] = l;
      ++now;
    }
    l = r + 1, r += a[i];
    ++i;
  }
  for (i = 1; i < now; ++i) cout << fa1[i] << " ";
  cout << endl;
  for (i = 1; i < now; ++i) cout << fa2[i] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> h;
  int s = -1;
  for (int i = 0; i <= h; ++i) {
    cin >> a[i];
    if (i && a[i] != 1 && a[i - 1] != 1 && s == -1) {
      s = i - 1;
    }
  }
  if (s == -1)
    cout << "perfect\n";
  else
    solve(s);
  return 0;
}
