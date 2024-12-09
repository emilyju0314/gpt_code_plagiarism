#include <bits/stdc++.h>
using namespace std;
const int head = 0;
const int INF = 10000000;
const int maxn = 1700;
const int maxd = 1000000;
int N, M, K, n, m, cnt, res;
int mat[maxn][maxn], s[maxn], l[maxd], r[maxd], u[maxd], d[maxd], c[maxd],
    o[maxn], row[maxd];
bool use[maxn];
void makegragh(int &n, int &m) {
  memset(mat, 0, sizeof(mat));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (i > 0) mat[i * m + j + 1][(i - 1) * m + j + 1] = 1;
      if (i < n - 1) mat[i * m + j + 1][(i + 1) * m + j + 1] = 1;
      if (j > 0) mat[i * m + j + 1][i * m + (j - 1) + 1] = 1;
      if (j < m - 1) mat[i * m + j + 1][i * m + (j + 1) + 1] = 1;
      mat[i * m + j + 1][i * m + j + 1] = 1;
    }
  n = n * m;
  m = n;
}
void initial(int n, int m) {
  memset(use, false, sizeof(use));
  res = n + 1;
  int i, j, rowh;
  memset(s, 0, sizeof(s));
  for (i = head; i <= m; i++) {
    r[i] = (i + 1) % (m + 1);
    l[i] = (i - 1 + m + 1) % (m + 1);
    u[i] = d[i] = i;
  }
  cnt = m + 1;
  for (i = 1; i <= n; i++) {
    rowh = -1;
    for (j = 1; j <= m; j++) {
      if (mat[i][j]) {
        s[j]++;
        u[cnt] = u[j];
        d[u[j]] = cnt;
        u[j] = cnt;
        d[cnt] = j;
        row[cnt] = i;
        c[cnt] = j;
        if (rowh == -1) {
          l[cnt] = r[cnt] = cnt;
          rowh = cnt;
        } else {
          l[cnt] = l[rowh];
          r[l[rowh]] = cnt;
          r[cnt] = rowh;
          l[rowh] = cnt;
        }
        cnt++;
      }
    }
  }
}
void remove(int c) {
  for (int i = d[c]; i != c; i = d[i]) {
    r[l[i]] = r[i];
    l[r[i]] = l[i];
  }
}
void resume(int c) {
  for (int i = d[c]; i != c; i = d[i]) r[l[i]] = l[r[i]] = i;
}
int h() {
  bool has[maxn];
  memset(has, false, sizeof(has));
  int ans = 0;
  for (int i = r[head]; i != head; i = r[i])
    if (!has[i]) {
      ans++;
      for (int j = d[i]; j != i; j = d[j])
        for (int k = r[j]; k != j; k = r[k]) has[c[k]] = true;
    }
  return ans;
}
bool dfs(int k) {
  if (k + h() >= res) return false;
  if (r[head] == head) {
    if (k < res) res = k;
    return true;
  }
  int ms = INF, cur = 0;
  for (int t = r[head]; t != head; t = r[t])
    if (s[t] < ms) {
      ms = s[t];
      cur = t;
    }
  for (int i = d[cur]; i != cur; i = d[i]) {
    remove(i);
    for (int j = r[i]; j != i; j = r[j]) {
      remove(j);
      s[c[j]]--;
    }
    dfs(k + 1);
    for (int j = l[i]; j != i; j = l[j]) {
      resume(j);
      s[c[j]]++;
    }
    resume(i);
  }
  return false;
}
int main() {
  int i, j, sum, cnt, rowh, n, m, T;
  while (~scanf("%d%d", &n, &m)) {
    sum = n * m;
    makegragh(n, m);
    initial(n, m);
    dfs(0);
    printf("%d\n", sum - res);
  }
  return 0;
}
