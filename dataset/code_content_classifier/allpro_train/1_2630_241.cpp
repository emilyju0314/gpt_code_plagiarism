#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1000 + 100;
int n;
vector<int> vec[maxn];
bool mark[maxn];
long long v[maxn];
long long a[maxn];
long long b[maxn];
void dfs(int x) {
  mark[x] = true;
  long long mx1 = 0, mx2 = 0;
  long long h = v[x];
  if (vec[x].size() == 1 && mark[vec[x][0]]) {
    if (v[x] < 0)
      a[x] = abs(v[x]);
    else
      b[x] = v[x];
  } else {
    for (int(i) = int(0); i < int(vec[x].size()); i++)
      if (!mark[vec[x][i]]) {
        dfs(vec[x][i]);
        mx1 = max(mx1, a[vec[x][i]]);
        mx2 = max(mx2, b[vec[x][i]]);
      }
    a[x] = mx1;
    b[x] = mx2;
    h = v[x] - mx2 + mx1;
    if (h < 0)
      a[x] += abs(h);
    else
      b[x] += h;
  }
}
int main() {
  cin >> n;
  for (int(i) = int(0); i < int(n - 1); i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  for (int(i) = int(0); i < int(n); i++) {
    int x;
    cin >> x;
    v[i] = x;
  }
  if (n == 1) {
    cout << abs(v[0]) << '\n';
    return 0;
  }
  dfs(0);
  cout << a[0] + b[0] << '\n';
  return 0;
}
