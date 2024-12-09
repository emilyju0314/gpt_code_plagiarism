#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 4000000 + 10;
int N, M, nxt[N_MAX], pre[N_MAX];
long long a[N_MAX];
namespace Ninit {
void init() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i) scanf("%I64d", &a[i]);
}
}  // namespace Ninit
namespace Nwork {
long long A[N_MAX];
int tmp, num, used[N_MAX], vis[N_MAX];
void prepare() {
  num = 0;
  memset(nxt, 0, sizeof(nxt));
  memset(pre, 0, sizeof(pre));
  for (int i = 2; i <= N; ++i)
    if (a[i] != a[i - 1]) {
      A[++num] = a[i] - a[i - 1];
      if (num > 1 && ((A[num] > 0) == (A[num - 1] > 0))) {
        --num;
        A[num] += A[num + 1];
      }
      if (num < 2 && A[num] <= 0) --num;
    }
  while (num > 0 && A[num] < 0) --num;
  for (int i = 1; i <= num; ++i) {
    nxt[i - 1] = i;
    pre[i] = i - 1;
  }
  nxt[num] = 0;
  pre[0] = num;
  A[0] = 0;
}
pair<long long, int> t[N_MAX], val;
queue<int> Q;
void add(int x) {
  if (!vis[x] && pair<long long, int>(abs(A[x]), x) <= val) {
    vis[x] = 1;
    Q.push(x);
  }
}
long long abs(long long x) { return x < 0 ? -x : x; }
void merge(int x) {
  if (used[x]) return;
  int L = pre[x], R = nxt[x];
  if (L > 0 && abs(A[x]) > abs(A[L])) return;
  if (R > 0 && abs(A[x]) > abs(A[R])) return;
  if (L > 0)
    pre[x] = pre[L];
  else
    pre[x] = 0;
  if (R > 0)
    nxt[x] = nxt[R];
  else
    nxt[x] = 0;
  nxt[pre[x]] = x;
  pre[nxt[x]] = x;
  used[L] = 1;
  used[R] = 1;
  A[x] += A[L] + A[R];
  if (L == 0) {
    nxt[0] = nxt[R];
    pre[nxt[R]] = 0;
    used[x] = 1;
  }
  if (R == 0) {
    pre[0] = pre[L];
    nxt[pre[L]] = 0;
    used[x] = 1;
  }
  if (pre[x] > 0) add(pre[x]);
  if (nxt[x] > 0) add(nxt[x]);
  add(x);
}
void solve() {
  memset(used, 0, sizeof(used));
  memset(vis, 0, sizeof(vis));
  for (;;) {
    tmp = 0;
    for (int i = nxt[0]; i; i = nxt[i])
      if (!used[i]) t[++tmp] = pair<long long, int>(abs(A[i]), i);
    if (tmp <= M * 2) break;
    int del = (tmp - M * 2 + 1) / 2;
    nth_element(t + 1, t + del, t + tmp + 1);
    val = t[del];
    while (!Q.empty()) Q.pop();
    for (int i = nxt[0]; i; i = nxt[i]) add(i);
    while (!Q.empty()) {
      int top = Q.front();
      Q.pop();
      vis[top] = 0;
      merge(top);
    }
  }
  long long ret = 0LL;
  for (int i = nxt[0]; i; i = nxt[i])
    if (A[i] > 0) ret += A[i];
  printf("%I64d\n", ret);
}
void main() {
  prepare();
  solve();
}
}  // namespace Nwork
int main() {
  Ninit::init();
  Nwork::main();
  return 0;
}
