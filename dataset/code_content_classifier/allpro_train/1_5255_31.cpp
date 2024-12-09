#include <bits/stdc++.h>
using namespace std;
int cmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first > p2.first)
    return 1;
  else
    return 0;
}
int ans(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] != 0) return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, s, e, p, u, fl = 0;
  cin >> n >> m;
  int chk[m + 1], E[n + 1];
  vector<pair<int, int>> A[n + 1];
  vector<int> B;
  for (int i = 0; i < n + 1; i++) {
    E[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    cin >> s >> e >> p;
    chk[i + 1] = p;
    E[e] = 1;
    for (int j = s; j < e; j++) {
      pair<int, int> P = make_pair(e, i + 1);
      A[j].push_back(P);
    }
  }
  for (int i = 1; i < n + 1; i++) {
    stable_sort(A[i].begin(), A[i].end(), cmp);
    if (E[i] != 1) E[i] = 0;
  }
  for (int i = 1; i < n + 1; i++) {
    fl = 0;
    if (E[i] == 1) {
      B.push_back(m + 1);
      continue;
    }
    if (A[i].empty()) {
      B.push_back(0);
      continue;
    }
    while (!A[i].empty()) {
      u = A[i].back().second;
      if (chk[u]) {
        chk[u]--;
        B.push_back(u);
        fl = 1;
        break;
      }
      A[i].pop_back();
    }
    if (fl)
      continue;
    else
      B.push_back(0);
  }
  if (ans(chk, m + 1)) {
    cout << -1;
  } else {
    for (int i = 0; i < n; i++) {
      cout << B[i] << " ";
    }
  }
  return 0;
}
