#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
using lim = numeric_limits<T>;
template <typename T>
istream& operator>>(istream& is, vector<T>& a) {
  for (T& x : a) {
    is >> x;
  }
  return is;
}
template <typename T>
struct grid : public vector<vector<T>> {
  int n, m;
  grid(int n, int m) : vector<vector<T>>(n, vector<T>(m)), n(n), m(m) {}
  grid(int n, int m, T zero)
      : vector<vector<T>>(n, vector<T>(m, zero)), n(n), m(m) {}
  grid(const grid& a) : vector<vector<T>>(a), n(a.n), m(a.m) {}
};
int query(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1
       << endl;
  int ans;
  cin >> ans;
  return ans;
}
int di[] = {-2, 0, -1};
int dj[] = {0, -2, -1};
int query_simple(grid<int>& g, int i, int j, int direction = 1) {
  for (int d = 0; d < 3; d++) {
    int ni = i + di[d] * direction, nj = j + dj[d] * direction;
    if (0 <= ni and ni < g.n and 0 <= nj and nj < g.m and g[ni][nj] != -1) {
      return g[ni][nj] ^ query(min(i, ni), min(j, nj), max(i, ni), max(j, nj)) ^
             1;
    }
  }
  return -1;
}
void query_double(grid<int>& g, int i) {
  if (query(i, i, i + 2, i + 1)) {
    g[i + 2][i + 1] = 1;
  } else if (query(i + 1, i, i + 2, i + 2)) {
    g[i + 1][i] = 0;
  } else if (g[i + 1][i + 1] or g[i + 2][i]) {
    g[i + 2][i + 1] = 0;
  } else {
    g[i + 1][i] = 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  grid<int> g(n, n, -1);
  g[0][0] = 1, g[n - 1][n - 1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (not((i & 1) ^ (j & 1)) and g[i][j] == -1) {
        g[i][j] = query_simple(g, i, j);
      }
    }
  }
  for (int i = 0; i < n; i += 2) {
    if (g[i][i] != g[i + 2][i + 2]) {
      query_double(g, i);
      break;
    }
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i & 1) ^ (j & 1) and g[i][j] == -1) {
          g[i][j] = query_simple(g, i, j);
        }
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if ((i & 1) ^ (j & 1) and g[i][j] == -1) {
          g[i][j] = query_simple(g, i, j, -1);
        }
      }
    }
  }
  cout << "!" << endl;
  for (auto row : g) {
    for (int elem : row) {
      cout << elem;
    }
    cout << endl;
  }
  return 0;
}
