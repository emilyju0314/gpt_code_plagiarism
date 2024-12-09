#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2, class T3 = hash<T1>>
using umap = unordered_map<T1, T2, T3>;
template <class T>
using uset = unordered_set<T>;
template <class T>
using vec = vector<T>;
const long long infll = numeric_limits<long long>::max() >> 1;
const int inf = numeric_limits<int>::max() >> 1;
const int N = 1e6 + 1;
int n, m;
string t[N];
vec<int> dst[N];
vec<int> tmp[N];
pair<int, int> adj[8] = {{1, 1},  {1, 0},  {1, -1}, {0, 1},
                         {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    t[i] = '#' + t[i];
  }
  for (int i = 1; i <= n; ++i) {
    dst[i].resize(m + 1);
    for (int j = 1; j <= m; ++j) {
      dst[i][j] = inf;
    }
  }
}
int dijkstra() {
  auto cmp = [](pair<int, int> x, pair<int, int> y) {
    return dst[x.first][x.second] > dst[y.first][y.second];
  };
  priority_queue<pair<int, int>, vec<pair<int, int>>, decltype(cmp)> pq(cmp);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (t[i][j] != 'X') {
        continue;
      }
      if (i == 1 || j == 1 || i == n || j == m) {
        dst[i][j] = 0;
        pq.push({i, j});
      } else {
        for (pair<int, int> p : adj) {
          int ix = i + p.first;
          int jx = j + p.second;
          if (t[ix][jx] == '.') {
            dst[i][j] = 0;
            pq.push({i, j});
            break;
          }
        }
      }
    }
  }
  int res = 0;
  while (!pq.empty()) {
    int i = pq.top().first;
    int j = pq.top().second;
    pq.pop();
    res = max(res, dst[i][j]);
    for (pair<int, int> p : adj) {
      int ix = i + p.first;
      int jx = j + p.second;
      if (ix > 0 && ix <= n && jx > 0 && jx <= m) {
        if (t[ix][jx] == '.') {
          continue;
        }
        if (dst[ix][jx] > dst[i][j] + 1) {
          dst[ix][jx] = dst[i][j] + 1;
          pq.push({ix, jx});
        }
      }
    }
  }
  return res;
}
bool test(int k) {
  queue<pair<int, int>> q;
  for (int i = 1; i <= n; ++i) {
    tmp[i].resize(m + 1);
    for (int j = 1; j <= m; ++j) {
      tmp[i][j] = inf;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (t[i][j] == 'X' && dst[i][j] >= k) {
        tmp[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    for (pair<int, int> p : adj) {
      int ix = i + p.first;
      int jx = j + p.second;
      if (ix > 0 && ix <= n && jx > 0 && jx <= m) {
        if (tmp[ix][jx] > tmp[i][j] + 1) {
          tmp[ix][jx] = tmp[i][j] + 1;
          q.push({ix, jx});
        }
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (t[i][j] == 'X' && tmp[i][j] == inf) {
        return 0;
      }
      if (t[i][j] == 'X') {
        res = max(res, tmp[i][j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (t[i][j] == '.' && tmp[i][j] <= res) {
        return 0;
      }
    }
  }
  return 1;
}
int bin_search(int l, int r) {
  if (l == r) {
    return l;
  }
  int q = l + r + 1 >> 1;
  if (test(q)) {
    return bin_search(q, r);
  } else {
    return bin_search(l, q - 1);
  }
}
void solve() {
  int q = dijkstra();
  int k = bin_search(0, N);
  cout << k << "\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (dst[i][j] >= k) {
        cout << t[i][j];
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  input();
  solve();
}
