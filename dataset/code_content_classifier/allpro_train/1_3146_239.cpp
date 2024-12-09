#include <bits/stdc++.h>
using namespace std;
int n, m, f[1000001], a[1000001], s[1000001], x, y, z, k, l;
int find(int x) { return f[x] = f[x] == x ? x : find(f[x]); }
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> s[i], f[i] = i;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] + i <= n) f[find(i)] = find(a[i] + i);
    if (i > a[i]) f[find(i)] = find(i - a[i]);
  }
  for (int i = 1; i <= n; i++)
    if (find(s[i]) != find(i)) {
      cout << "NO";
      return 0;
    }
  cout << "YES";
  return 0;
}
