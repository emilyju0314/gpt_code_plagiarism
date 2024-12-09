#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 1e6 + 5;
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do x = x * 10 + ch - '0', ch = getchar();
  while (ch <= '9' && ch >= '0');
  x *= f;
}
template <typename A, typename B>
inline void read(A &x, B &y) {
  read(x);
  read(y);
}
template <typename A, typename B, typename C>
inline void read(A &x, B &y, C &z) {
  read(x);
  read(y);
  read(z);
}
template <typename A, typename B, typename C, typename D>
inline void read(A &x, B &y, C &z, D &w) {
  read(x);
  read(y);
  read(z);
  read(w);
}
struct node {
  int v;
  long long w;
  node() {}
  node(int _v, long long _w) : v(_v), w(_w) {}
};
vector<node> e[maxn];
int Low[maxn], DFN[maxn], Stack[maxn], Belong[maxn];
int num[maxn];
int Index, top, n, m, x, y;
long long z;
int scc;
bool Instack[maxn];
long long score[maxn];
vector<int> scce[maxn];
long long dp[maxn];
void Tarjan(int u) {
  int v;
  Low[u] = DFN[u] = ++Index;
  Stack[top++] = u;
  Instack[u] = true;
  for (auto enxt : e[u]) {
    v = enxt.v;
    if (!DFN[v]) {
      Tarjan(v);
      Low[u] = min(Low[u], Low[v]);
    } else if (Instack[v] && Low[u] > DFN[v])
      Low[u] = DFN[v];
  }
  if (Low[u] == DFN[u]) {
    scc++;
    do {
      v = Stack[--top];
      Instack[v] = false;
      Belong[v] = scc;
      num[scc]++;
    } while (v != u);
  }
}
int indeg[maxn], outdeg[maxn];
long long calc(long long w) {
  long long l = 0, r = 1e6 + 5, rt;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (mid * (mid + 1) / 2 <= w)
      l = (rt = mid) + 1;
    else
      r = mid - 1;
  }
  long long ret = w * (rt + 1ll) - rt * (rt + 1ll) * (rt + 2ll) / 6ll;
  return ret;
}
inline void solve(int n) {
  memset(DFN, 0, sizeof DFN);
  memset(num, 0, sizeof num);
  memset(Instack, 0, sizeof Instack);
  Index = scc = top = 0;
  for (int i = 1; i <= n; i++)
    if (!DFN[i]) Tarjan(i);
  memset(indeg, 0, sizeof indeg);
  memset(outdeg, 0, sizeof outdeg);
  for (int u = 1; u <= n; u++) scce[Belong[u]].push_back(u);
  for (int u = 1; u <= n; u++)
    for (auto enxt : e[u]) {
      int v = enxt.v;
      if (Belong[u] != Belong[v]) {
        outdeg[Belong[u]]++;
        indeg[Belong[v]]++;
      } else {
        score[Belong[u]] += calc(enxt.w);
      }
    }
}
long long find(int nowscc) {
  if (dp[nowscc] != -1) return dp[nowscc];
  long long ret = 0;
  for (auto u : scce[nowscc])
    for (auto enxt : e[u]) {
      int v = enxt.v;
      if (Belong[u] == Belong[v]) continue;
      long long w = enxt.w;
      ret = max(ret, find(Belong[v]) + w);
    }
  dp[nowscc] = (ret + score[nowscc]);
  return dp[nowscc];
}
int main() {
  read(n, m);
  for (int i = 1; i <= m; i++) {
    read(x, y, z);
    e[x].push_back(node(y, z));
  }
  solve(n);
  memset(dp, -1, sizeof dp);
  int start;
  read(start);
  long long res = find(Belong[start]);
  cout << res;
  return 0;
}
