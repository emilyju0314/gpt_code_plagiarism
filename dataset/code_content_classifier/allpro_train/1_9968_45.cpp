#include <bits/stdc++.h>
namespace io {
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
char F[200];
inline void write(long long x) {
  if (x == 0) return (void)(putchar('0'));
  long long tmp = x > 0 ? x : -x;
  if (x < 0) putchar('-');
  int cnt = 0;
  while (tmp > 0) {
    F[cnt++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (cnt > 0) putchar(F[--cnt]);
}
}  // namespace io
using namespace io;
using namespace std;
int n = read(), k = read();
int b, g;
set<pair<int, int> > s;
int random(int n) { return (long long)rand() * rand() % n; }
int main() {
  srand((unsigned)time(0));
  if ((long long)k * (k - 1) < (long long)n) return puts("NO"), 0;
  puts("YES");
  int l = 0, r = 1;
  b = g = -1;
  for (int i = 1; i <= n; ++i) {
    while (l == r || l == b || r == g || s.count(make_pair(l, r)))
      l = random(k) % k, r = random(k) % k;
    s.insert(make_pair(l, r));
    printf("%d %d\n", l + 1, r + 1);
    b = l, g = r;
  }
}
