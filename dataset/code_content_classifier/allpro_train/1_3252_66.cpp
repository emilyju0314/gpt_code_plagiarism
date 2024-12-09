#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
struct bs {
  long long A[(14868489)];
  void clr() { (memset(A, 0, sizeof(A))); }
  void tr(int H) {
    for (int i(0); i < H >> 6; i++) A[i] = -1;
    for (int k(H - (H & 63)); k < H; k++) ad(k);
  }
  bool is(bs &r) {
    for (int i(0); i < (14868489); i++)
      if (A[i] & r.A[i]) return 1;
    return 0;
  }
  void operator|=(bs &r) {
    for (int i(0); i < (14868489); i++) A[i] |= r.A[i];
  }
  void operator&=(bs &r) {
    for (int i(0); i < (14868489); i++) A[i] &= r.A[i];
  }
  void operator^=(bs &r) {
    for (int i(0); i < (14868489); i++) A[i] ^= r.A[i];
  }
  void ad(int u) { A[u >> 6] |= 1ull << (u & 63); }
  void cg(int u) { A[u >> 6] ^= 1ull << (u & 63); }
  bool ct(int v) { return (A[v >> 6] >> (v & 63)) & 1; }
  int bt() {
    int l(0);
    for (int i(0); i < (14868489); i++) l += __builtin_popcountll(A[i]);
    return l;
  }
} C;
char s[16];
int N, A[16], B[16], U, V, T, G[16];
void bt(int b) {
  for (int i(0); i < N; i++) printf("%d", b >> i & 1);
}
void dfs(int b, int u, int v, int x, int y) {
  if (C.ct((b + (u << 16) + (v << 16) * 121))) return;
  C.ad((b + (u << 16) + (v << 16) * 121));
  if (b == (1 << N) - 1) {
    T = min(T, max(U - u, V - v));
    return;
  }
  for (int i(0); i < N; i++)
    if (!(b & 1 << i))
      dfs(b | 1 << i, u + min(x, A[i]), v + min(y, B[i]), x + G[i], y + !G[i]);
}
int main(void) {
  scanf("%d", &N), C.clr();
  for (int i(0); i < N; i++)
    scanf(" %c%d%d", s + i, A + i, B + i), U += A[i], V += B[i],
        G[i] = s[i] == 'R';
  T = max(U, V), dfs(0, 0, 0, 0, 0);
  printf("%d\n", T + N);
  return 0;
}
