#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, H;
  cin >> N >> M >> H;
  vector<pair<int, bool>> r(N), c(M);
  vector<vector<int>> ans(N);
  for (int i = 0; i < M; ++i) {
    cin >> c[i].first;
    c[i].second = false;
  }
  for (int i = 0; i < N; ++i) {
    cin >> r[i].first;
    r[i].second = false;
  }
  int temp;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) {
      cin >> temp;
      if (temp == 0)
        ans[i].push_back(0);
      else {
        ans[i].push_back(-1);
      }
    }
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) {
      if (ans[i][j] != 0) {
        if (r[i].first == c[j].first) {
          ans[i][j] = r[i].first;
          r[i].second = true;
          c[j].second = true;
        } else if (r[i].first > c[j].first) {
          ans[i][j] = c[j].first;
        } else {
          ans[i][j] = r[i].first;
        }
      }
    }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
