#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 2;
int n, m, k;
int v[650][650];
int cnt = 0;
void dfs(int s, vector<bool> &used) {
  cnt++;
  used[s] = true;
  for (int i = 1; i <= n * m; i++) {
    if (!used[i] && v[s][i] == 1) {
      dfs(i, used);
    }
  }
}
int main() {
  int node = 0;
  cin >> n >> m;
  int alln = n * m;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '>') {
      for (int j = 1; j < m; j++) {
        v[i * m + j][i * m + j + 1] = 1;
      }
    } else {
      for (int j = 0; j < m - 1; j++) {
        v[(i + 1) * m - j][(i + 1) * m - j - 1] = 1;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    char c;
    cin >> c;
    if (c == '^') {
      for (int j = 1; j < n; j++) {
        v[(n - j) * m + i][(n - j - 1) * m + i] = 1;
      }
    } else {
      for (int j = 1; j < n; j++) {
        v[m * (j - 1) + i][m * j + i] = 1;
      }
    }
  }
  set<int> st;
  for (int i = 1; i <= n * m; i++) {
    vector<bool> used(MAXN, false);
    cnt = 0;
    dfs(i, used);
    st.insert(cnt);
  }
  if (st.size() == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
