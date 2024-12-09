#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 21;
int a[N];
stack<int> S;
int main() {
  int n, m;
  while (cin >> n) {
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    reverse(a, a + n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int t;
      scanf("%d", &t);
      t = n - t;
      a[t] = -a[t];
    }
    while (!S.empty()) S.pop();
    for (int i = 0; i < n; i++) {
      if (!S.empty() && S.top() + a[i] == 0) {
        S.pop();
      } else {
        if (a[i] > 0) a[i] = -a[i];
        S.push(a[i]);
      }
    }
    if (!S.empty()) {
      puts("NO");
      continue;
    } else {
      puts("YES");
      reverse(a, a + n);
      for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
      }
      puts("");
    }
  }
  return 0;
}
