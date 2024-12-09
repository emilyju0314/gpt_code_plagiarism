#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
inline long long read() {
  register long long x = 0, f = 1;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  return x * f;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  puts("");
}
const int BASE = 32;
int n, P, a[50005];
bitset<BASE> f[BASE + 1][50005];
int b[233];
int main() {
  n = read(), P = read();
  for (register int i = (1); i <= int(n); ++i) {
    a[i] = read();
  }
  int m = n;
  n = 0;
  for (register int i = (1); i <= int(m); ++i)
    if (a[i] < BASE) b[++n] = i;
  f[0][0].set(0);
  for (register int i = (0); i < int(n); ++i) {
    f[i + 1][a[b[i + 1]] % P].set(a[b[i + 1]]);
    for (register int j = (0); j < int(P); ++j) {
      for (register int k = (0); k < int(BASE); ++k)
        if (f[i][j][k]) {
          f[i + 1][(1ll * j * (a[b[i + 1]] >= 10 ? 100 : 10) + a[b[i + 1]]) % P]
              .set(k ^ a[b[i + 1]]);
          f[i + 1][j].set(k);
        }
    }
  }
  int Xor = 0, Rem = 0;
  vector<int> ans;
  ans.clear();
  for (register int i = (n); i >= int(1); --i) {
    bool flag = false;
    for (int x = 0; x < P && (!flag); ++x) {
      for (int y = 0; y < BASE && (!flag); ++y) {
        if (f[i - 1][x][y] &&
            (1ll * x * (a[b[i]] >= 10 ? 100 : 10) + a[b[i]]) % P == Rem &&
            (y ^ a[b[i]]) == Xor) {
          ans.push_back(b[i]);
          Rem = x;
          Xor = y;
          flag = true;
          break;
        }
      }
    }
    if (flag && Rem == 0 && Xor == 0) break;
  }
  if (ans.size()) {
    reverse(ans.begin(), ans.end());
    puts("Yes");
    writeln(ans.size());
    for (unsigned i = 0; i < ans.size(); ++i) write(ans[i]), putchar(' ');
  } else
    puts("No");
  return 0;
}
