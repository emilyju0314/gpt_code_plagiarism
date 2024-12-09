#include <bits/stdc++.h>
using namespace std;
inline int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  int a = 100000000, a1 = 0, b1 = 100000000, b2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      if (x == 'B') {
        a = min(i, a);
        b1 = min(j, b1);
        a1 = max(i, a);
        b2 = max(j, b2);
      }
    }
  }
  cout << a + (a1 - a) / 2 + 1 << " " << b1 + (b2 - b1) / 2 + 1;
  return 0;
}
