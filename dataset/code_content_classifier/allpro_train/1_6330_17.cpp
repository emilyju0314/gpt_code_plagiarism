#include <bits/stdc++.h>
using namespace std;
int N, M, cnt, a[200001], turn[201][201], lst[201], f[200001], siz[201];
long long ans;
vector<int> id[201];
map<vector<int>, int> dfn;
int getf(int x) { return f[x] == x ? x : getf(f[x]); }
void mrg(int x, int y) {
  int a = getf(x), b = getf(y);
  if (a == b) return;
  if (siz[a] < siz[b]) swap(a, b);
  f[b] = a;
  siz[a] += siz[b];
}
int get() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
int main() {
  N = get(), M = get();
  cnt = 1;
  for (int i = 1; i <= M; i++) cnt *= i;
  vector<int> x(M);
  for (int i = 0; i <= M - 1; i++) x[i] = i;
  for (int i = 0; i <= cnt - 1; i++) {
    id[i] = x, dfn[x] = i;
    next_permutation(x.begin(), x.end());
  }
  for (int i = 0; i <= cnt - 1; i++)
    for (int j = 0; j <= cnt - 1; j++) {
      vector<int> a = id[i], b = id[j], c(M);
      for (int k = 0; k <= M - 1; k++) c[k] = a[b[k]];
      turn[i][j] = dfn[c];
    }
  for (int i = 1; i <= N; i++) {
    vector<int> x(M);
    for (int j = 0; j <= M - 1; j++) x[j] = get() - 1;
    a[i] = dfn[x];
  }
  for (int i = 1; i <= N; i++) {
    lst[a[i]] = i;
    vector<int> x;
    for (int j = 0; j <= cnt - 1; j++)
      if (lst[j]) x.push_back(lst[j]);
    sort(x.begin(), x.end(), greater<int>());
    for (int j = 0; j <= cnt - 1; j++) f[j] = j, siz[j] = 1;
    int pre = i;
    for (auto j : x) {
      ans += (pre - j) * siz[getf(0)];
      if (getf(0) != getf(a[j]))
        for (int k = 0; k <= cnt - 1; k++) mrg(k, turn[k][a[j]]);
      pre = j;
      if (siz[getf(0)] == cnt) break;
    }
    ans += siz[getf(0)] * pre;
  }
  cout << ans << endl;
  return 0;
}
