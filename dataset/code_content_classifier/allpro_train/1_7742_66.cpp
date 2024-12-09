#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const int N = 2e3 + 2, M = 1e6 + 2;
int n, m, X[N << 1], Y[N << 1], C[N][N];
void Merge(vector<pair<int, pair<int, int> > > &v) {
  sort(v.begin(), v.end());
  int q = 0;
  for (int i = 1; i < (int)(v.size()); i++) {
    if (v[i].first != v[q].first || v[i].second.first > v[q].second.second)
      v[++q] = v[i];
    else
      v[q].second.second = v[i].second.second;
  }
  v.resize(q + 1);
}
bool Check(int t) {
  vector<pair<int, pair<int, int> > > hor, ver;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) C[i][j] = 0;
  for (int i = 0; i < n; i++)
    hor.push_back(make_pair(Y[i], make_pair(X[i] - 2 * t, X[i] + 2 * t)));
  for (int i = n; i < n + m; i++)
    ver.push_back(make_pair(X[i], make_pair(Y[i] - 2 * t, Y[i] + 2 * t)));
  Merge(hor), Merge(ver);
  for (pair<int, pair<int, int> > a : hor) {
    vector<int> adj;
    for (int i = 0; i < (int)(ver.size()); i++) {
      pair<int, pair<int, int> > b = ver[i];
      if (b.second.first <= a.first && a.first <= b.second.second &&
          a.second.first <= b.first && b.first <= a.second.second) {
        for (int j : adj)
          if (C[i][j]++) return true;
        adj.push_back(i);
      }
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n + m; i++) {
    cin >> X[i] >> Y[i];
    int x = X[i] - Y[i], y = X[i] + Y[i];
    X[i] = x, Y[i] = y;
  }
  int dw = 0, up = M;
  while (up - dw > 1) {
    int md = (dw + up) >> 1;
    if (Check(md))
      up = md;
    else
      dw = md;
  }
  if (up == M)
    cout << "Poor Sereja!" << '\n';
  else
    cout << up << '\n';
  return 0;
}
