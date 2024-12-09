#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool cmax(T &x, T y) {
  return y > x ? x = y, true : false;
}
template <typename T>
inline bool cmin(T &x, T y) {
  return y < x ? x = y, true : false;
}
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int MAXN = 2e5 + 5;
const int oo = 0x3f3f3f3f;
int N, Q, a[MAXN], c[MAXN];
struct tree {
  int to[105];
} t[MAXN * 3];
void Build(int le, int ri, int k) {
  for (int i = 1; i <= 100; i++) t[k].to[i] = i;
  if (le == ri) return;
  int mi = (le + ri) >> 1;
  Build(le, mi, k << 1);
  Build(mi + 1, ri, k << 1 | 1);
}
void mark(int k, int *o) {
  for (int i = 1; i <= 100; i++) t[k].to[i] = o[t[k].to[i]];
}
void Pushdown(int k) {
  mark(k << 1, t[k].to);
  mark(k << 1 | 1, t[k].to);
  for (int i = 1; i <= 100; i++) t[k].to[i] = i;
}
void Cov(int le, int ri, int k, int L, int R) {
  if (le != ri) Pushdown(k);
  if (L <= le && ri <= R) {
    mark(k, c);
    return;
  }
  int mi = (le + ri) >> 1;
  if (L <= mi) Cov(le, mi, k << 1, L, R);
  if (mi + 1 <= R) Cov(mi + 1, ri, k << 1 | 1, L, R);
}
void DFS(int le, int ri, int k) {
  if (le != ri) Pushdown(k);
  if (le == ri) {
    printf("%d ", t[k].to[a[le]]);
    return;
  }
  int mi = (le + ri) >> 1;
  DFS(le, mi, k << 1);
  DFS(mi + 1, ri, k << 1 | 1);
}
int main() {
  N = read();
  for (int i = 1; i <= N; i++) a[i] = read();
  Build(1, N, 1);
  Q = read();
  while (Q--) {
    int le = read(), ri = read(), x = read(), y = read();
    for (int i = 1; i <= 100; i++) c[i] = i;
    c[x] = y;
    Cov(1, N, 1, le, ri);
  }
  DFS(1, N, 1);
  puts("");
  return 0;
}
