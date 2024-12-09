#include <bits/stdc++.h>
using namespace std;
namespace IO {
char buf[1000000], *p1 = buf, *p2 = buf;
inline char gc() {
  if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin);
  return p1 == p2 ? EOF : *(p1++);
}
template <class T>
inline void read(T &n) {
  n = 0;
  register long long ch = gc(), f;
  while ((ch < '0' || ch > '9') && ch != '-') ch = gc();
  f = (ch == '-' ? ch = gc(), -1 : 1);
  while (ch >= '0' && ch <= '9') n = n * 10 + (ch ^ 48), ch = gc();
  n *= f;
}
char Of[105], *O1 = Of, *O2 = Of;
template <class T>
inline void print(T n, char ch = '\n') {
  if (n < 0) putchar('-'), n = -n;
  if (n == 0) putchar('0');
  while (n) *(O1++) = (n % 10) ^ 48, n /= 10;
  while (O1 != O2) putchar(*(--O1));
  putchar(ch);
}
}  // namespace IO
using IO ::print;
using IO ::read;
long long const MAXN = 2e5 + 5;
struct Node {
  long long x, y;
  Node(long long _x = 0, long long _y = 0) { x = _x, y = _y; }
  bool operator<(const Node &A) const { return x ^ A.x ? x < A.x : y < A.y; }
  bool operator==(const Node &A) const { return x == A.x && y == A.y; }
  Node Ref(const Node &A) { return Node(A.x * 2 - x, A.y * 2 - y); }
} a[MAXN], A[MAXN];
map<Node, long long> mp;
bool Solve(Node Ctr, long long n, long long k) {
  long long l = 1, r = n;
  while (l <= r) {
    Node re = a[l].Ref(Ctr);
    if (re == a[r])
      ++l, --r;
    else if (re < a[r])
      --r, --k;
    else
      ++l, --k;
  }
  return (k >= 0);
}
signed main() {
  long long n, k;
  read(n), read(k);
  for (register long long i = 1; i <= n; ++i)
    read(a[i].x), read(a[i].y), a[i].x *= 2, a[i].y *= 2;
  if (k >= n) return puts("-1"), 0;
  sort(a + 1, a + 1 + n,
       [](Node x, Node y) { return x.x ^ y.x ? x.x < y.x : x.y < y.y; });
  long long ans = 0;
  for (register long long i = 1; i <= k + 1; ++i)
    for (register long long j = n - (k - i + 1); j <= n; ++j) {
      Node now((a[i].x + a[j].x) / 2, (a[i].y + a[j].y) / 2);
      if (mp.find(now) == mp.end() && Solve(now, n, k))
        A[++ans] = now, mp[now] = 1;
    }
  printf("%lld\n", ans);
  for (register long long i = 1; i <= ans; ++i)
    printf("%.2lf %.2lf\n", A[i].x / 2.0, A[i].y / 2.0);
  return 0;
}
