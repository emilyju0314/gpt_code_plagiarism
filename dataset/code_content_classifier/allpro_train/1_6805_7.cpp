#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010, mod = 998244353;
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 0;
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
int n;
inline void work(int x, int y) { printf("%d %d\n", x, y); }
inline void work2(int a, int b, int c, int d) {
  work(a, c);
  work(b, d);
  work(a, d);
  work(b, c);
}
int main() {
  n = read();
  if (n % 4 >= 2) return puts("NO"), 0;
  puts("YES");
  for (int i = (0); i <= (n / 4 - 1); i++) {
    work(i * 4 + 1, i * 4 + 3);
    work(i * 4 + 2, i * 4 + 4);
    work(i * 4 + 1, i * 4 + 4);
    work(i * 4 + 2, i * 4 + 3);
    if (n % 4 == 1) work(i * 4 + 1, n);
    work(i * 4 + 1, i * 4 + 2);
    if (n % 4 == 1) work(i * 4 + 2, n);
    if (n % 4 == 1) work(i * 4 + 3, n);
    work(i * 4 + 3, i * 4 + 4);
    if (n % 4 == 1) work(i * 4 + 4, n);
  }
  for (int i = (0); i <= (n / 4 - 1); i++)
    for (int j = (i + 1); j <= (n / 4 - 1); j++) {
      work2(i * 4 + 1, i * 4 + 2, j * 4 + 1, j * 4 + 2);
      work2(i * 4 + 1, i * 4 + 2, j * 4 + 3, j * 4 + 4);
      work2(i * 4 + 3, i * 4 + 4, j * 4 + 1, j * 4 + 2);
      work2(i * 4 + 3, i * 4 + 4, j * 4 + 3, j * 4 + 4);
    }
}
