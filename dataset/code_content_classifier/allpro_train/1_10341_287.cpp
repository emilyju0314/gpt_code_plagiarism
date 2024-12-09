#include <bits/stdc++.h>
using namespace std;
const int ma = 300005;
int par[ma], arr[ma];
int finds(int i) {
  if (par[i] == i) return i;
  return par[i] = finds(par[i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n + 1; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    for (int j = finds(l); j <= r; j = finds(j + 1)) {
      if (j != x) {
        par[j] = j + 1;
        arr[j] = x;
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << arr[i] << " ";
  return 0;
}
