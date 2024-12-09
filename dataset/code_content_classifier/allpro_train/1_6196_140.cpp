#include <bits/stdc++.h>
using namespace std;
namespace IO {
inline int read() {
  int w = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    w = (w << 3) + (w << 1) + (ch ^ 48);
    ch = getchar();
  }
  return w * f;
}
inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[++top] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[top--] + 48);
  puts("");
}
}  // namespace IO
using namespace IO;
namespace CL {
const int maxn = 1e5 + 5;
int n, m, q;
map<string, int> H;
namespace UnionSet {
int f[maxn << 1];
inline void init() {
  for (int i = 1; i <= (n << 1); i++) f[i] = i;
}
inline int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}
}  // namespace UnionSet
using namespace UnionSet;
inline int main() {
  n = read();
  m = read();
  q = read();
  init();
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    H[s] = i;
  }
  for (int i = 1; i <= m; i++) {
    int op = read();
    string x, y;
    cin >> x >> y;
    int fx = find(H[x]), fy = find(H[y]), ex = find(H[x] + n),
        ey = find(H[y] + n);
    if (op == 1) {
      if (fx == ey || ex == fy) {
        puts("NO");
        continue;
      } else {
        puts("YES");
        f[fx] = fy;
        f[ex] = ey;
      }
    }
    if (op == 2) {
      if (fx == fy || ex == ey) {
        puts("NO");
        continue;
      } else {
        puts("YES");
        f[ex] = fy;
        f[ey] = fx;
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    string x, y;
    cin >> x >> y;
    int fx = find(H[x]), fy = find(H[y]), ex = find(H[x] + n),
        ey = find(H[y] + n);
    if (fx == fy || ex == ey)
      puts("1");
    else if (fx == ey || ex == fy)
      puts("2");
    else
      puts("3");
  }
  return 0;
}
}  // namespace CL
signed main() { return CL::main(); }
