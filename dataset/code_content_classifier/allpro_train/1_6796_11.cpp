#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int M1 = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> v(3 * n);
  for (int i = 0; i < 3 * n; i++) cin >> v[i];
  vector<int> vis(3 * n + 2, 0);
  vector<vector<int>> St(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) cin >> St[i][j];
  }
  int k;
  cin >> k;
  vector<int> p;
  map<int, int> came;
  for (int i = 0; i < n; i++) {
    int visp = 0;
    int a = St[i][0], b = St[i][1], c = St[i][2];
    if (a == k || b == k || c == k) {
      vis[a] = 1;
      vis[b] = 1;
      vis[c] = 1;
      int pos = 0;
      while (pos < 3 * n) {
        if (v[pos] == a || v[pos] == b || v[pos] == c) {
          if (v[pos] != k) {
            for (int j = 1; j < 3 * n + 1; j++)
              if (j != k) cout << j << ' ';
            return 0;
          }
          break;
        }
        pos++;
      }
      map<int, int> pr;
      pr[k] = 1;
      for (pos = 1; pos <= 3 * n; pos++) {
        int mx = 0;
        if (a == k) mx = max(b, c);
        if (b == k) mx = max(a, c);
        if (c == k) mx = max(b, a);
        if (vis[pos] && pos != k && pos <= mx) p.push_back(pos), pr[pos] = 1;
      }
      sort(p.begin(), p.end());
      int st = 1;
      while (st <= 3 * n) {
        if (!pr[st]) p.push_back(st);
        st++;
      }
      for (int i = 0; i < 3 * n - 1; i++) cout << p[i] << ' ';
      cout << '\n';
      return 0;
      break;
    } else {
      vis[a] = 1;
      vis[b] = 1;
      vis[c] = 1;
      came[a] = 1;
      came[b] = 1;
      came[c] = 1;
    }
  }
  for (int i = 0; i < 3 * n - 1; i++) cout << p[i] << ' ';
  cout << '\n';
  return 0;
}
