#include <bits/stdc++.h>
#pragma GCC optimization("unroll-loops")
using namespace std;
bool home = 1;
signed realMain();
signed main() {
  home = 0;
  if (home) {
    freopen("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
  realMain();
}
const int N = (int)5e4 + 7;
const int Q = (int)5e3 + 7;
const int L = (int)1e6 + 7;
int n, q, a[N], tab[N];
int pre[L];
int sol[Q];
vector<pair<int, int>> question[N];
int eval(int x, int y) {
  if (x <= y) return pre[y] ^ pre[x - 1];
  return pre[x] ^ pre[y - 1];
}
signed realMain() {
  for (int i = 1; i < L; i++) {
    pre[i] = pre[i - 1] ^ i;
  }
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    question[r].push_back({l, i});
  }
  for (int r = 1; r <= n; r++) {
    for (int i = r; i >= 1; i--) {
      tab[i] = max(tab[i], eval(a[i], a[r]));
      tab[i] = max(tab[i], tab[i + 1]);
    }
    for (auto &it : question[r]) {
      sol[it.second] = tab[it.first];
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << sol[i] << "\n";
  }
  return 0;
}
