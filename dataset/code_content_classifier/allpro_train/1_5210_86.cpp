#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 500005;
int tot, qj, n, mx;
int a[N], ans[N], fa[N], qq[10];
pair<int, int> q[N];
set<int> s;
inline int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }
struct heap {
  bitset<N> vis;
  priority_queue<int> q;
  void push(int x) {
    if (vis[x])
      vis[x] = 0;
    else
      q.push(x);
  }
  void erase(int x) { vis[x] = 1; }
  int top() {
    while (vis[q.top()]) {
      vis[q.top()] = 0;
      q.pop();
    }
    return q.top();
  }
} Q;
void solve(int x) {
  auto L = s.lower_bound(x), R = s.upper_bound(x + 1);
  L--;
  tot = 0;
  for (auto i = L;; i++) {
    qq[++tot] = *i;
    if (i == R) break;
  }
}
void bao(int l, int r) {
  for (int i = gf(l); i <= r; i = gf(i)) {
    ans[i] = qj;
    fa[i] = i + 1;
  }
}
void upderase(int x) {
  solve(x);
  for (int i = (int)(1); i <= (int)(tot - 1); i++) {
    int L = qq[i], R = qq[i + 1];
    Q.erase(R - L);
  }
}
void updinsert(int x) {
  solve(x);
  for (int i = (int)(1); i <= (int)(tot - 1); i++) {
    int L = qq[i], R = qq[i + 1];
    Q.push(R - L);
    if (a[L] == 1 && a[R] == 1)
      bao(L, R);
    else if (a[L] == 1)
      bao(L, (L + R) / 2 - 1);
    else if (a[R] == 1)
      bao((L + R) / 2, R);
  }
}
void re(int x) {
  upderase(x);
  if (x != 1 && a[x] == a[x - 1]) s.erase(x);
  if (x != n && a[x] == a[x + 1]) s.erase(x + 1);
  a[x] = 1;
  if (x == 1) a[0] = 1;
  if (x == n) a[n + 1] = 1;
  if (x != 1 && a[x] == a[x - 1]) s.insert(x);
  if (x != n && a[x] == a[x + 1]) s.insert(x + 1);
  updinsert(x);
}
int main() {
  n = read();
  for (int i = (int)(1); i <= (int)(n); i++) q[i] = make_pair(read(), i);
  sort(q + 1, q + n + 1);
  for (int i = (int)(0); i <= (int)(n + 3); i++) fa[i] = i;
  for (int i = (int)(0); i <= (int)(n + 2); i++) {
    s.insert(i);
    Q.push(1);
  }
  for (int i = (int)(n); i >= (int)(1); i--) {
    qj = q[i].first;
    re(q[i].second);
    if (q[i].first != q[i - 1].first) mx = max(mx, Q.top());
  }
  writeln((mx - 1) / 2);
  for (int i = (int)(1); i <= (int)(n); i++) wri(ans[i]);
}
