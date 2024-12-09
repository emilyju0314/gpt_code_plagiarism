#include <bits/stdc++.h>
using namespace std;
int a[200000];
bool u[200000];
set<pair<int, int> > s;
int main() {
  int i, n, k, q, ty, id;
  cin >> n >> k >> q;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 0; i < q; i++) {
    cin >> ty >> id;
    if (ty == 1)
      if (s.size() >= k) {
        if (a[id] > s.begin()->first) {
          u[s.begin()->second] = false;
          s.erase(s.begin());
          u[id] = true;
          s.insert(make_pair(a[id], id));
        }
      } else {
        u[id] = true;
        s.insert(make_pair(a[id], id));
      }
    else if (u[id])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
