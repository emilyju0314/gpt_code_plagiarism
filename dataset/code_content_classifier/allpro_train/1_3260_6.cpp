#include <bits/stdc++.h>
using namespace std;
const int nx[4] = {0, 0, 1, -1};
const int ny[4] = {1, -1, 0, 0};
const long long LINF = (long long)1e18;
const int INF = 1e9 + 7;
const int N = 1e6 + 1;
const double EPS = 1e-9, PI = 3.1415926;
int n, m;
int p[N];
int sz = 1;
map<int, int> cnt[N];
int get(int x) {
  if (p[x] == x) return x;
  return p[x] = get(p[x]);
}
void unite(int x, int y) {
  int X = x, Y = y;
  x = get(x);
  y = get(y);
  if (x != y)
    p[x] = y;
  else
    sz = (sz * 2ll) % (INF + 2);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    unite(x, y);
    cout << sz - 1 << "\n";
  }
  return 0;
}
