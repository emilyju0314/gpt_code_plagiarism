#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool op = 0;
  char c = getchar();
  while (!isdigit(c)) op |= (c == '-'), c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return op ? -x : x;
}
const int N = 200010;
int n;
int a[N], ans[N];
queue<int> q[2];
int main() {
  int t = read();
  while (t--) {
    n = read();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
      if (q[a[i] ^ 1].empty() == false) {
        ans[i] = ans[q[a[i] ^ 1].front()];
        q[a[i] ^ 1].pop();
        q[a[i]].push(i);
      } else {
        ans[i] = ++cnt;
        q[a[i]].push(i);
      }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
    while (q[1].empty() == false) q[1].pop();
    while (q[0].empty() == false) q[0].pop();
  }
  return 0;
}
