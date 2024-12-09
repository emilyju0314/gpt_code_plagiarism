#include <bits/stdc++.h>
using namespace std;
template <class T>
using v2d = vector<vector<T>>;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxN = 1e2 + 10;
int n, a[4][maxN][maxN], ans = 1e9;
;
void cal(int board, pair<int, int> &ans) {
  ans.first = ans.second = 0;
  for (int i = 1; i <= (int)(n); ++i) {
    for (int j = 1; j <= (int)(n); ++j) {
      if ((i + j) % 2 == 0) {
        ans.first += (a[board][i][j] != 0);
      } else {
        ans.first += (a[board][i][j] != 1);
      }
    }
  }
  for (int i = 1; i <= (int)(n); ++i) {
    for (int j = 1; j <= (int)(n); ++j) {
      if ((i + j) % 2 == 0) {
        ans.second += (a[board][i][j] != 1);
      } else {
        ans.second += (a[board][i][j] != 0);
      }
    }
  }
}
void solve() {
  cin >> n;
  for (int board = 0; board < (int)(4); ++board) {
    for (int i = 1; i <= (int)(n); ++i) {
      for (int j = 1; j <= (int)(n); ++j) {
        char c;
        cin >> c;
        a[board][i][j] = c - '0';
      }
    }
  }
  vector<pair<int, int>> vec(4);
  for (int board = 0; board < (int)(4); ++board) {
    cal(board, vec[board]);
    cerr << vec[board].first << ' ' << vec[board].second << '\n';
  }
  vector<int> per(4);
  iota((per).begin(), (per).end(), 0);
  for (int iter = 1; iter <= (int)(24); ++iter) {
    int cur = vec[per[0]].first + vec[per[1]].first + vec[per[2]].second +
              vec[per[3]].second;
    uin(ans, cur);
    next_permutation((per).begin(), (per).end());
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
