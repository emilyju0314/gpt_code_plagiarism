#include <bits/stdc++.h>
using namespace std;
const long long int hell = 1000000007;
const long long int maxn = 1e3 + 5;
long long int comp[maxn][maxn], vis[maxn][maxn], store[maxn];
char a[maxn][maxn];
long long int dx[] = {1, -1, 0, 0};
long long int dy[] = {0, 0, 1, -1};
long long int n, m;
long long int timer = 0, cur_sz;
void dfs(long long int x, long long int y) {
  if (x < 1 or x > n or y < 1 or y > m or a[x][y] == '*') return;
  if (vis[x][y]) return;
  cur_sz++;
  comp[x][y] = timer;
  vis[x][y] = 1;
  for (long long int i = 0; i < 4; i++) {
    dfs(x + dx[i], y + dy[i]);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      if (a[i][j] == '*' or vis[i][j]) continue;
      timer++;
      cur_sz = 0;
      dfs(i, j);
      store[timer] = cur_sz;
    }
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      if (a[i][j] == '.')
        cout << a[i][j];
      else {
        long long int ans = 0;
        set<long long int> s;
        for (long long int k = 0; k < 4; k++) {
          s.insert(comp[i + dx[k]][j + dy[k]]);
        }
        for (auto &it : s) {
          ans += store[it];
        }
        ans++;
        ans %= 10;
        cout << ans;
      }
    }
    cout << '\n';
  }
}
