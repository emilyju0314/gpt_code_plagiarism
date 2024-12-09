#include <bits/stdc++.h>
using namespace std;
const int Len = 1000006, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
typedef int Arr[Len];
inline int IN() {
  char c;
  register int x = 0;
  for (; (c = getchar()) < 48 && c ^ '-' || c > 57;)
    ;
  bool f = c == '-';
  if (f) (c = getchar());
  for (; c > 47 && c < 58; (c = getchar())) x = x * 10 + c - 48;
  if (f) x = -x;
  return x;
}
struct ww {
  int x, y;
  void IN() {
    x = ::IN();
    y = ::IN();
  }
  bool operator!=(const ww& A) { return x ^ A.x || y ^ A.y; }
} S, T, tar, UP, DOWN, LEFT, RIGHT, g[Len];
template <class T>
struct Arrr {
  T a[333][333];
  T& operator[](ww x) { return a[x.x + 111][x.y + 111]; }
  void clr() { memset(a, 0, sizeof a); }
};
Arr q;
Arrr<bool> a, vis;
Arrr<int> pre;
int mmm;
bool trapped;
inline void pri(int d) {
  if (!d)
    putchar('L');
  else if (d == 1)
    putchar('R');
  else if (d == 2)
    putchar('U');
  else
    putchar('D');
}
inline ww nxt(ww u, int d) {
  u.x += dx[d];
  u.y += dy[d];
  return u;
}
inline bool out105(ww u) {
  return u.x > 105 || u.x < -105 || u.y > 105 || u.y < -105;
}
inline bool free(ww u) { return out105(u) || !a[u]; }
inline void Move(int d) {
  S = nxt(S, d);
  assert(free(S));
  if (free(nxt(T, d))) T = nxt(T, d), q[++*q] = d;
  pri(d);
}
inline void BFS() {
  int l = 0, r = 1;
  trapped = 1;
  for (vis[g[l] = S] = 1; l ^ r; ++l) {
    if (l == Len) l = 0;
    ww u = g[l];
    for (int _r = 4, d = 0; d < _r; ++d) {
      ww v = nxt(u, d);
      if (out105(v))
        trapped = 0, tar = v, pre[tar] = d;
      else if (free(v) && !vis[v]) {
        vis[g[r++] = v] = 1;
        pre[v] = d;
        if (r == Len) r = 0;
      }
    }
  }
}
inline void track() {
  for (ww u = T; u != S; u = nxt(u, pre[u] ^ 1)) q[++*q] = pre[u];
  reverse(q + 1, q + *q + 1);
  for (int i = 1; i <= *q && S != T; ++i) Move(q[i]);
}
inline void pret() {
  if (S.x <= LEFT.x || T.x <= LEFT.x)
    for (; S.x >= -100 && S.x <= 100 || T.x >= -100 && T.x <= 100;) Move(0);
  else
    for (; S.x >= -100 && S.x <= 100 || T.x >= -100 && T.x <= 100;) Move(1);
  if (S.y >= UP.y || T.y >= UP.y)
    for (; S.y >= -100 && S.y <= 100 || T.y >= -100 && T.y <= 100;) Move(2);
  else
    for (; S.y >= -100 && S.y <= 100 || T.y >= -100 && T.y <= 100;) Move(3);
}
inline void fixup() {
  pret();
  for (; T.y >= DOWN.y;) Move(3);
  for (; T.x > DOWN.x;) Move(0);
  for (; T.x < DOWN.x;) Move(1);
  for (; S.y < T.y;) Move(2);
}
inline void fixdown() {
  pret();
  for (; T.y <= UP.y;) Move(2);
  for (; T.x > UP.x;) Move(0);
  for (; T.x < UP.x;) Move(1);
  for (; S.y > T.y;) Move(3);
}
inline void fixright() {
  pret();
  for (; T.x >= LEFT.x;) Move(0);
  for (; T.y > LEFT.y;) Move(3);
  for (; T.y < LEFT.y;) Move(2);
  for (; S.x < T.x;) Move(1);
}
inline void fixleft() {
  pret();
  for (; T.x <= RIGHT.x;) Move(1);
  for (; T.y > RIGHT.y;) Move(3);
  for (; T.y < RIGHT.y;) Move(2);
  for (; S.x > T.x;) Move(0);
}
inline void fix() {
  if (T.y > S.y) fixup();
  if (T.y < S.y) fixdown();
  if (T.x > S.x) fixright();
  if (T.x < S.x) fixleft();
}
inline void gao() {
  for (ww u = tar; u != S; u = nxt(u, pre[u] ^ 1)) q[++*q] = pre[u];
  for (int i = *q; i; --i) Move(q[i]);
  for (int _r = 1000, i = 0; i < _r; ++i) Move(q[1]);
  if (!out105(T)) {
    int l = 0, r = 1;
    vis.clr();
    for (vis[g[l] = T] = 1; l ^ r; ++l) {
      if (l == Len) l = 0;
      ww u = g[l];
      for (int _r = 4, d = 0; d < _r; ++d) {
        ww v = nxt(u, d);
        if (out105(v)) {
          tar = v;
          pre[tar] = d;
          break;
        } else if (free(v) && !vis[v]) {
          vis[g[r++] = v] = 1;
          pre[v] = d;
          if (r == Len) r = 0;
        }
      }
    }
    *q = 0;
    for (ww u = tar; u != T; u = nxt(u, pre[u] ^ 1)) q[++*q] = pre[u];
    for (int i = *q; i; --i) Move(q[i]);
  }
  fix();
}
int main() {
  S.IN();
  T.IN();
  UP.y = -1e9;
  DOWN.y = 1e9;
  LEFT.x = 1e9;
  RIGHT.x = -1e9;
  for (int _r = mmm = IN(), i = 0; i < _r; ++i) {
    ww u;
    u.IN();
    if (u.y > UP.y) UP = u;
    if (u.y < DOWN.y) DOWN = u;
    if (u.x > RIGHT.x) RIGHT = u;
    if (u.x < LEFT.x) LEFT = u;
    a[u] = 1;
  }
  if (!mmm) return puts(S != T ? "-1" : "");
  BFS();
  if (!vis[T]) return puts("-1"), 0;
  if (trapped) return track(), 0;
  gao();
}
