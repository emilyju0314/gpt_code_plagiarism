#include <bits/stdc++.h>
using namespace std;
set<int> s;
int p[323456];
int find(int u) { return p[u] == u ? p[u] : p[u] = find(p[u]); }
void init(int u) {}
void _union(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    p[a] = b;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  for (int i = 0; i < n - 1; i++) {
    s.insert(i);
  }
  init(n);
  while (m--) {
    int ty, x, y;
    cin >> ty >> x >> y;
    x--;
    y--;
    if (ty == 1) {
      _union(x, y);
    } else if (ty == 2) {
      if (x > y) swap(x, y);
      set<int>::iterator it = s.lower_bound(x);
      for (; it != s.end() && *it < y; s.erase(it++)) {
        _union(*it, (*it) + 1);
      }
    } else {
      if (find(x) == find(y))
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
