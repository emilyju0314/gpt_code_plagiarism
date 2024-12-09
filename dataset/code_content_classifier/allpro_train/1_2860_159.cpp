#include <bits/stdc++.h>
using namespace std;
const int maxn = 150005;
int N, par[maxn], lft[maxn], rht[maxn], L[maxn], R[maxn];
inline int root(int u) {
  while (u != par[u]) {
    par[u] = par[par[u]];
    u = par[u];
  }
  return u;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    par[i] = L[i] = R[i] = i;
    lft[i] = rht[i] = -1;
  }
  for (int t = 1; t < N; t++) {
    int a, b;
    cin >> a >> b;
    a = root(a), b = root(b);
    rht[R[a]] = L[b];
    lft[L[b]] = R[a];
    R[a] = R[b];
    par[b] = a;
  }
  int rt = -1;
  for (int i = 1; i <= N; i++)
    if (root(i) == i) rt = i;
  int st = L[rt];
  while (st != -1) {
    cout << st << " ";
    st = rht[st];
  }
}
