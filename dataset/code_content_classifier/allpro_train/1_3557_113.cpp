#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
int T;
int n, m, q;
int f[maxn];
char str[2000][2000];
vector<int> vec[maxn];
queue<int> que;
int cnt[maxn];
int ans[maxn];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void bset(int x, int y) {
  int fx = find(x), fy = find(y);
  f[fx] = fy;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", str[i]);
  }
  for (int i = 1; i <= n + m; ++i) f[i] = i;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (str[i][j] == '=') {
        bset(i + 1, j + 1 + n);
      }
    }
  }
  for (int i = 1; i <= n + m; ++i) {
    f[i] = find(i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (str[i][j] == '<') {
        vec[f[i + 1]].push_back(f[j + 1 + n]);
        cnt[f[j + 1 + n]]++;
      }
      if (str[i][j] == '>') {
        vec[f[j + 1 + n]].push_back(f[i + 1]);
        cnt[f[i + 1]]++;
      }
    }
  }
  for (int i = 1; i <= n + m; ++i) {
    if (cnt[f[i]] == 0 && i == f[i]) {
      que.push(f[i]);
      ans[f[i]] = 1;
    }
  }
  while (que.size()) {
    int tmp = que.front();
    que.pop();
    for (int i = 0; i < vec[tmp].size(); ++i) {
      cnt[vec[tmp][i]]--;
      if (cnt[vec[tmp][i]] == 0) {
        que.push(vec[tmp][i]);
        ans[vec[tmp][i]] = ans[tmp] + 1;
      }
    }
  }
  for (int i = 1; i <= n + m; ++i) {
    if (cnt[i] != 0) {
      printf("NO\n");
      return 0;
    }
  }
  for (int i = 1; i <= n + m; ++i) {
    ans[i] = ans[f[i]];
  }
  printf("YES\n");
  for (int i = 1; i <= n + m; ++i) {
    printf("%d", ans[i]);
    if (i == n || i == n + m)
      printf("\n");
    else
      printf(" ");
  }
  return 0;
}
