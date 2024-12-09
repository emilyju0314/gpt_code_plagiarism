#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int> > v[200009];
long long int c[200009][2];
long long int e[200009] = {0};
long long int dfs(long long int q, long long int col) {
  e[q] = 1;
  long long int x = 1;
  for (auto i : v[q]) {
    if (e[i.first] == 0 && i.second == col) x += dfs(i.first, col);
  }
  e[q] = 0;
  return x;
}
void fill(long long int q, long long int col, long long int val) {
  e[q] = 1;
  long long int x = 1;
  c[q][col] = val;
  for (auto i : v[q]) {
    if (e[i.first] == 0 && i.second == col) fill(i.first, col, val);
  }
  e[q] = 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int x, y, z;
  for (long long int i = 1; i < n; i++) {
    cin >> x >> y >> z;
    v[x].push_back(make_pair(y, z));
    v[y].push_back(make_pair(x, z));
  }
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    if (c[i][0] == 0) {
      x = dfs(i, 0);
      if (x > 1) {
        fill(i, 0, x);
        ans += (x * (x - 1));
      }
    }
  }
  for (long long int i = 1; i <= n; i++) {
    if (c[i][1] == 0) {
      x = dfs(i, 1);
      if (x > 1) {
        fill(i, 1, x);
        ans += x * (x - 1);
      }
    }
  }
  for (long long int i = 1; i <= n; i++) {
    if (c[i][0] != 0 & c[i][1] != 0) ans += ((c[i][0] - 1) * (c[i][1] - 1));
  }
  cout << ans;
}
