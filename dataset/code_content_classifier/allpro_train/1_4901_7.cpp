#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Int(T &n) {
  n = 0;
  int f = 1;
  register int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
  n = n * f;
}
template <typename T>
T gcd(T a, T b) {
  return !b ? a : gcd(b, a % b);
}
template <typename T>
T modinverse(T bs) {
  return modpow(bs, 1000000007LL - 2);
}
template <typename T>
inline void umin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void umax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T, typename W>
inline void Int(T &x, W &y) {
  Int(x), Int(y);
}
template <typename T, typename W, typename Q>
inline void Int(T &x, W &y, Q &z) {
  Int(x, y), Int(z);
}
const int N = 6e6 + 7;
const int inf = 1e9 + 7;
int tests = 1, CaseNo = 0;
int nd, res, t[N][3];
int newNode() {
  ++nd;
  t[nd][0] = t[nd][1] = -1;
  return nd;
}
void insert(int curNode, int x, int pos) {
  if (pos < 0) {
    t[curNode][2] = 1;
    return;
  }
  int &to = t[curNode][1 & (x >> pos)];
  if (to == -1) to = newNode();
  insert(to, x, pos - 1);
  t[curNode][2] = 0;
  if (~t[curNode][0]) t[curNode][2] += t[t[curNode][0]][2];
  if (~t[curNode][1]) t[curNode][2] += t[t[curNode][1]][2];
}
void ask(int curNode, int x, int pos) {
  if (curNode < 0) return;
  int bit = 1 & (x >> pos);
  if (t[t[curNode][bit]][2] == (1 << pos)) bit ^= 1;
  res |= (bit ^ (1 & (x >> pos))) << pos;
  ask(t[curNode][bit], x, pos - 1);
}
int solve() {
  int n, m;
  Int(n, m);
  int root = newNode();
  while (n--) {
    int x;
    Int(x);
    insert(root, x, 19);
  }
  int x = 0;
  while (m--) {
    int y;
    Int(y);
    x ^= y;
    res = 0;
    ask(root, x, 19);
    printf("%d\n", res);
  }
  return 0;
}
int main() {
  while (tests--) {
    solve();
  }
  return 0;
}
