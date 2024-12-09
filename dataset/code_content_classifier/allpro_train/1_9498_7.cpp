#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long data = 0, w = 1;
  char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    data = (data << 1) + (data << 3) + (ch ^ 48), ch = getchar();
  return data * w;
}
long long q;
const long long M = 1e5;
struct Seg {
  long long sum[1000005], Max[1000005], SM[1000005], num[1000005];
  void C() {
    memset(Max, 0x3f, sizeof(Max));
    memset(SM, -0x3f, sizeof(SM));
  }
  void pushup(long long x) {
    sum[x] = sum[x << 1] + sum[x << 1 | 1];
    Max[x] = max(Max[x << 1], Max[x << 1 | 1]);
    if (Max[x << 1] < Max[x << 1 | 1])
      SM[x] = max(Max[x << 1], SM[x << 1 | 1]), num[x] = num[x << 1 | 1];
    if (Max[x << 1 | 1] < Max[x << 1])
      SM[x] = max(Max[x << 1 | 1], SM[x << 1]), num[x] = num[x << 1];
    if (Max[x << 1] == Max[x << 1 | 1])
      SM[x] = max(SM[x << 1], SM[x << 1 | 1]),
      num[x] = num[x << 1] + num[x << 1 | 1];
  }
  void Min(long long x, long long v) {
    sum[x] += (v - Max[x]) * num[x];
    Max[x] = v;
  }
  void pushdown(long long x) {
    if (Max[x << 1] > Max[x]) Min(x << 1, Max[x]);
    if (Max[x << 1 | 1] > Max[x]) Min(x << 1 | 1, Max[x]);
  }
} T[2];
const long long inf = 0x3f3f3f3f;
void insert(long long x, long long l, long long r, long long ql, long long qr,
            long long t, long long v) {
  if (T[t].Max[x] <= v) return;
  if (l == r) {
    T[t].Max[x] = v;
    if (T[t ^ 1].Max[x] < inf)
      T[t].num[x] = T[t ^ 1].num[x] = 1, T[t].sum[x] = T[t].Max[x],
      T[t ^ 1].sum[x] = T[t ^ 1].Max[x];
    return;
  }
  if (ql <= l && r <= qr && T[t].Max[x] < inf && v > T[t].SM[x])
    return void(T[t].Min(x, v));
  T[0].pushdown(x);
  T[1].pushdown(x);
  long long mid = l + r >> 1;
  if (ql <= mid) insert(x << 1, l, mid, ql, qr, t, v);
  if (mid < qr) insert(x << 1 | 1, mid + 1, r, ql, qr, t, v);
  T[0].pushup(x);
  T[1].pushup(x);
}
long long ask(long long x, long long l, long long r, long long ql,
              long long qr) {
  if (ql > r || qr < l) return 0;
  if (ql <= l && r <= qr) return T[0].sum[x] + T[1].sum[x];
  T[0].pushdown(x);
  T[1].pushdown(x);
  long long mid = l + r >> 1;
  return ask(x << 1, l, mid, ql, qr) + ask(x << 1 | 1, mid + 1, r, ql, qr);
}
int main() {
  T[0].C();
  T[1].C();
  q = read();
  while (q--) {
    long long op = read(), l = read(), r = read(), v;
    if (op == 1) v = read(), insert(1, 1, M, l, r - 1, (v > 0), abs(v));
    if (op == 2) cout << ask(1, 1, M, l, r - 1) << '\n';
  }
  return 0;
}
