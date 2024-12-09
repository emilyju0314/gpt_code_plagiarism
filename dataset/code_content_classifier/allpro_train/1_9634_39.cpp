#include <bits/stdc++.h>
using namespace std;
void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T a, Args... args) {
  cout << a << " ";
  print(args...);
}
long long llipowerp(long long x, long long y, long long p = LLONG_MAX) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long binarySearch(vector<int> arr, int l, int r, int x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
template <typename T>
inline void printvec(vector<T> inp) {
  for (auto it : inp) cout << it << " ";
  cout << "\n";
}
int n, m;
vector<string> a;
vector<vector<int>> vis;
bool get(int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m) return false;
  return (a[i][j] == '#' && !vis[i][j]);
}
void dfs(int i, int j) {
  vis[i][j] = 1;
  if (get(i, j + 1)) dfs(i, j + 1);
  if (get(i + 1, j)) dfs(i + 1, j);
  if (get(i - 1, j)) dfs(i - 1, j);
  if (get(i, j - 1)) dfs(i, j - 1);
}
int main() {
  cin >> n >> m;
  a.resize(n);
  vis.resize(n);
  for (int i = 0; i < n; i++) {
    vis[i].resize(m, 0);
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  bool con = true;
  for (int i = 0; i < n; i++) {
    bool bw = false;
    bool wb = false;
    for (int j = 0; j < m - 1; j++) {
      if (a[i][j] == '#' && a[i][j + 1] == '.') {
        bw = true;
      }
      if (a[i][j] == '.' && a[i][j + 1] == '#' && bw) {
        wb = true;
      }
    }
    if (bw && wb) {
      con = false;
      break;
    }
  }
  for (int j = 0; j < m; j++) {
    bool bw = false;
    bool wb = false;
    for (int i = 0; i < n - 1; i++) {
      if (a[i][j] == '#' && a[i + 1][j] == '.') {
        bw = true;
      }
      if (a[i][j] == '.' && a[i + 1][j] == '#' && bw) {
        wb = true;
      }
    }
    if (bw && wb) {
      con = false;
      break;
    }
  }
  int wr = 0;
  int wc = 0;
  for (int i = 0; i < n; i++) {
    bool con2 = true;
    for (int j = 0; j < m; j++) {
      if (a[i][j] != '.') {
        con2 = false;
        break;
      }
    }
    if (con2) wr++;
  }
  for (int i = 0; i < m; i++) {
    bool con2 = true;
    for (int j = 0; j < n; j++) {
      if (a[j][i] != '.') {
        con2 = false;
        break;
      }
    }
    if (con2) wc++;
  }
  if (wr > 0 && wc == 0) con = false;
  if (wc > 0 && wr == 0) con = false;
  if (!con)
    cout << -1 << "\n";
  else {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j] && a[i][j] == '#') {
          dfs(i, j);
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
}
