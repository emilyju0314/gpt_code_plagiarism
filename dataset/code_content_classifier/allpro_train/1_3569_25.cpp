#include <bits/stdc++.h>
#pragma GCC Optimize(2)
using namespace std;
int n, k, id;
inline int lowbit(int x) { return x & (-x); }
inline bool isfull(int x) { return (x + 1) == lowbit(x + 1); }
inline int lowerX(int x) {
  while (x != lowbit(x)) x -= lowbit(x);
  return x - 1;
}
inline int upperX(int x) {
  while (!isfull(x)) x += lowbit(~x);
  return x;
}
void writefull(int n, int f) {
  if (n < 1) return;
  int now = ++id;
  printf("%d ", f);
  if (n == 1) return;
  writefull(n / 2, now);
  writefull(n / 2, now);
}
void writeimb(int n, int k, int f) {
  if (n < 1) return;
  if (k == 0) {
    writefull(n, f);
    return;
  }
  int now = ++id;
  printf("%d ", f);
  if (k > 1) {
    if (isfull(n - (k - 1) * 2)) {
      writefull(3, now);
      writeimb(n - 4, k - 1, now);
    } else {
      writefull(1, now);
      writeimb(n - 2, k - 1, now);
    }
  } else if (k == 1) {
    int l = n / 2;
    if (!isfull(l)) {
      l = lowerX(l);
      if (l * 2 <= n - 1 - l && !isfull(n - 1 - l)) l = (l << 1) | 1;
    }
    writefull(l, now);
    writeimb(n - 1 - l,
             k - (l * 2 <= n - 1 - l || (n - 1 - l) * 2 <= l ? 1 : 0), now);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  if ((n & 1) == 0 || n > 1 && n < 2 * k + 3 || isfull(n) && k == 1 ||
      !isfull(n) && k == 0 || n == 9 && k == 2) {
    puts("NO");
    return 0;
  }
  puts("YES");
  writeimb(n, k, 0);
}
