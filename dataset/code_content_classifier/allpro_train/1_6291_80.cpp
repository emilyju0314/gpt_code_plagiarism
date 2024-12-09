#include <bits/stdc++.h>
namespace fast_IO {
const int IN_LEN = 10000000, OUT_LEN = 10000000;
char ibuf[IN_LEN], obuf[OUT_LEN], *ih = ibuf + IN_LEN, *oh = obuf,
                                  *lastin = ibuf + IN_LEN,
                                  *lastout = obuf + OUT_LEN - 1;
inline char getchar_() {
  return (ih == lastin) &&
                 (lastin = (ih = ibuf) + fread(ibuf, 1, IN_LEN, stdin),
                  ih == lastin)
             ? EOF
             : *ih++;
}
inline void putchar_(const char x) {
  if (oh == lastout) fwrite(obuf, 1, oh - obuf, stdout), oh = obuf;
  *oh++ = x;
}
inline void flush() { fwrite(obuf, 1, oh - obuf, stdout); }
}  // namespace fast_IO
using namespace fast_IO;
template <typename T>
inline T max(const T a, const T b) {
  return a > b ? a : b;
}
template <typename T>
inline T min(const T a, const T b) {
  return a < b ? a : b;
}
template <typename T>
inline T abs(const T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline void swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}
template <typename T>
inline T gcd(const T a, const T b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
template <typename T>
inline T square(const T x) {
  return x * x;
};
template <typename T>
inline void read(T& x) {
  char cu = getchar();
  x = 0;
  bool fla = 0;
  while (!isdigit(cu)) {
    if (cu == '-') fla = 1;
    cu = getchar();
  }
  while (isdigit(cu)) x = x * 10 + cu - '0', cu = getchar();
  if (fla) x = -x;
}
template <typename T>
void printe(const T x) {
  if (x >= 10) printe(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void print(const T x) {
  if (x < 0)
    putchar('-'), printe(-x);
  else
    printe(x);
}
int n, m, h;
int head[100001], nxt[200001], tow[200001], tmp, vau[100001];
int belo[100001], n_d = 0;
inline void addb(const int u, const int v) {
  tmp++;
  nxt[tmp] = head[u];
  head[u] = tmp;
  tow[tmp] = v;
}
int tot, DFN[100001], LOW[100001], beg;
int stack[100001], top, size[100001];
inline void push(const int x) { stack[++top] = x; }
inline int pop() { return stack[top--]; }
void DFS(const int u) {
  DFN[u] = LOW[u] = ++tot;
  push(u);
  for (register int i = head[u]; i; i = nxt[i]) {
    const int v = tow[i];
    if (!DFN[v]) {
      DFS(v);
      LOW[u] = min(LOW[u], LOW[v]);
    } else if (belo[v] == 0)
      LOW[u] = min(LOW[u], DFN[v]);
  }
  if (LOW[u] == DFN[u]) {
    n_d++;
    register int cl = pop();
    while (cl != u) {
      belo[cl] = n_d;
      size[n_d]++;
      cl = pop();
    }
    belo[cl] = n_d;
    size[n_d]++;
  }
}
bool could[100001];
inline void addb_d(const int u, const int v) {
  if (u == v) return;
  could[u] = 0;
}
inline void draw() {
  for (register int i = 1; i <= n; i++)
    for (register int j = head[i]; j; j = nxt[j]) addb_d(belo[i], belo[tow[j]]);
}
int res = 0;
bool sign = 0;
int main() {
  read(n), read(m), read(h);
  for (register int i = 1; i <= n; i++) read(vau[i]);
  for (register int i = 1; i <= m; i++) {
    int u, v;
    read(u), read(v);
    if ((vau[u] + 1) % h == vau[v]) addb(u, v);
    if ((vau[v] + 1) % h == vau[u]) addb(v, u);
  }
  for (beg = 1; beg <= n; beg++)
    if (!DFN[beg]) DFS(beg);
  memset(could, 1, sizeof(could));
  draw();
  size[0] = 0x7fffffff;
  for (register int i = 1; i <= n_d; i++)
    if (could[i] && size[res] > size[i]) res = i;
  print(size[res]), putchar('\n');
  for (register int i = 1; i <= n; i++)
    if (belo[i] == res) {
      if (sign)
        putchar(' ');
      else
        sign = 1;
      print(i);
    }
  return 0;
}
