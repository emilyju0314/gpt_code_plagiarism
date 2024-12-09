#include <bits/stdc++.h>
using namespace std;
const int M = 1000 * 100 + 1;
int n;
vector<int> e[M];
int h[M], h2[M], pos[M];
int sz[M], mx[M], stop[M];
char rnk[M];
int dfs(int fa, int st, int num) {
  sz[st] = 1;
  mx[st] = 0;
  int mi = -1;
  for (int i = 0; i < e[st].size(); i++) {
    int ch = e[st][i];
    if (stop[ch] == 0 && ch != fa) {
      int t = dfs(st, ch, num);
      if (mi < 0 || mx[t] < mx[mi]) mi = t;
      sz[st] += sz[ch];
      mx[st] = max(mx[st], sz[ch]);
    }
  }
  mx[st] = max(mx[st], num - sz[st]);
  if (mi < 0 || mx[st] < mx[mi]) mi = st;
  return mi;
}
int find_mid(int st) {
  dfs(-1, st, -1);
  int num = sz[st];
  return dfs(-1, st, num);
}
void fill(int st, char c) {
  int u = find_mid(st);
  rnk[u] = c;
  stop[u] = 1;
  for (int i = 0; i < e[u].size(); i++) {
    int ch = e[u][i];
    if (stop[ch] == 0) fill(ch, c + 1);
  }
}
int main(int argc, const char* argv[]) {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  fill(1, 'A');
  for (int i = 1; i <= n; i++) {
    cout << rnk[i];
    char ed = (i < n ? ' ' : '\n');
    cout << ed;
  }
  return 0;
}
