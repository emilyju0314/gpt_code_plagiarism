#include <bits/stdc++.h>
using namespace std;
const long long int N = 3e5 + 5, inf = 1e9 + 7;
int n, c[4][N], col[N], tmp[N];
vector<int> vec[N];
long long int rs = N * inf;
void bfs(int x, int y, int z) {
  queue<int> q1;
  q1.push(1);
  memset(tmp, 0, sizeof tmp);
  tmp[1] = x;
  long long int cur = c[x][1];
  bool f = 1;
  while (!q1.empty()) {
    int u = q1.front();
    q1.pop();
    if (vec[u].size() > 2) {
      f = 0;
      break;
    }
    if (vec[u].size() == 1) {
      int v = vec[u][0];
      if (tmp[v]) continue;
      if (tmp[u] == x) {
        tmp[v] = y;
        cur += c[y][v];
      } else if (tmp[u] == y) {
        tmp[v] = z;
        cur += c[z][v];
      } else {
        tmp[v] = x;
        cur += c[x][v];
      }
      q1.push(v);
    } else if (vec[u].size() == 2) {
      int v1 = vec[u][0], v2 = vec[u][1];
      if (tmp[v1] == 0 && tmp[v2] == 0) {
        if (tmp[u] == x) {
          tmp[v1] = y, tmp[v2] = z;
          cur += (c[y][v1] + c[z][v2]);
        } else if (tmp[u] == y) {
          tmp[v1] = x, tmp[v2] = z;
          cur += (c[x][v1] + c[z][v2]);
        } else {
          tmp[v1] = x, tmp[v2] = y;
          cur += (c[x][v1] + c[y][v2]);
        }
        q1.push(v1);
        q1.push(v2);
      } else if (tmp[v1] == 0) {
        int id = 0;
        for (int j = 1; j <= 3; j++) {
          if (j != tmp[u] && j != tmp[v2]) {
            id = j;
          }
        }
        tmp[v1] = id;
        cur += c[id][v1];
        q1.push(v1);
      } else if (tmp[v2] == 0) {
        int id = 0;
        for (int j = 1; j <= 3; j++) {
          if (j != tmp[u] && j != tmp[v1]) {
            id = j;
          }
        }
        tmp[v2] = id;
        cur += c[id][v2];
        q1.push(v2);
      }
    }
    if (f == 0) break;
  }
  if (rs > cur && f) {
    rs = cur;
    for (int i = 1; i <= n; i++) col[i] = tmp[i];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  while (tc--) {
    vector<int> vc;
    vc.push_back(1);
    vc.push_back(2);
    vc.push_back(3);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[1][i];
    for (int i = 1; i <= n; i++) cin >> c[2][i];
    for (int i = 1; i <= n; i++) cin >> c[3][i];
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      vec[u].push_back(v);
      vec[v].push_back(u);
    }
    do {
      bfs(vc[0], vc[1], vc[2]);
    } while (next_permutation(vc.begin(), vc.end()));
    if (rs == N * inf)
      cout << "-1\n";
    else {
      cout << rs << "\n";
      for (int i = 1; i <= n; i++) cout << col[i] << " ";
      cout << "\n";
    }
  }
  return 0;
}
