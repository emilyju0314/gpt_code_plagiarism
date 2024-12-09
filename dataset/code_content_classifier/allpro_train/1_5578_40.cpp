#include <bits/stdc++.h>
using namespace std;
int d[200005];
int main() {
  int n, m, x;
  scanf("%d", &n);
  map<int, int> cap;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
    cap[i] = d[i];
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int a, b;
      scanf("%d %d", &a, &b);
      auto it = cap.lower_bound(a);
      while (b > 0 && it != cap.end()) {
        int c = min(b, it->second);
        b -= c;
        it->second -= c;
        if (it->second == 0) {
          it = cap.erase(it);
        }
      }
    } else {
      int a;
      scanf("%d", &a);
      if (cap.find(a) == cap.end()) {
        printf("%d\n", d[a]);
      } else {
        printf("%d\n", d[a] - cap[a]);
      }
    }
  }
  return 0;
}
