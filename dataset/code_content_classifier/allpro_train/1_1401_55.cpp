#include <bits/stdc++.h>
const int INF = 1e9;
const double E = 1e-10;
const long long P = 1e9 + 7;
const long long Q = 31;
using namespace std;
void hello() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void show(vector<int>& arr) {
  for (auto i : arr) cout << i << " ";
  cout << "\n";
}
void show(vector<vector<int>>& arr) {
  for (auto i : arr) show(i);
  cout << "\n";
}
int gcd(int a, int b) {
  while (a && b) {
    a %= b;
    swap(a, b);
  }
  return a + b;
}
const int MAXN = 3e5 * 4 + 10;
vector<int> tree[MAXN];
void build(vector<int>& data, int v, int l, int r) {
  if (l == r) {
    tree[v] = {data[l]};
  } else {
    int m = (l + r) / 2;
    build(data, 2 * v, l, m);
    build(data, 2 * v + 1, m + 1, r);
    tree[v].resize(r - l + 1);
    merge(tree[2 * v].begin(), tree[2 * v].end(), tree[2 * v + 1].begin(),
          tree[2 * v + 1].end(), tree[v].begin());
  }
}
int query(int v, int l, int r, int cl, int cr) {
  if (cl >= l && cr <= r)
    return tree[v].end() - upper_bound(tree[v].begin(), tree[v].end(), r);
  if (cl > r || cr < l) return 0;
  int cm = (cl + cr) / 2;
  return query(2 * v, l, r, cl, cm) + query(2 * v + 1, l, r, cm + 1, cr);
}
signed main() {
  hello();
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> matr(n);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    vector<pair<int, int>> tmp(t);
    for (int j = 0; j < t; ++j) cin >> tmp[j].first >> tmp[j].second;
    matr[i].resize(t);
    for (int j = 0; j < t; ++j)
      matr[i][j] = {tmp[(j + 1) % t].first - tmp[j].first,
                    tmp[(j + 1) % t].second - tmp[j].second};
    for (int j = 0; j < t; ++j) {
      int g = gcd(abs(matr[i][j].first), abs(matr[i][j].second));
      matr[i][j].first /= g;
      matr[i][j].second /= g;
    }
  }
  vector<pair<int, int>> data;
  vector<int> sz(n + 1);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    sz[i] = cnt;
    for (int j = 0; j < matr[i].size(); ++j) data.push_back(matr[i][j]);
    cnt += matr[i].size();
  }
  sz[n] = cnt;
  map<pair<int, int>, int> check;
  vector<int> seq(cnt);
  for (int i = cnt - 1; i >= 0; --i) {
    if (!check.count(data[i]))
      seq[i] = INF;
    else
      seq[i] = check[data[i]];
    check[data[i]] = i;
  }
  build(seq, 1, 0, cnt - 1);
  int q;
  cin >> q;
  for (int v = 0; v < q; ++v) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    cout << query(1, sz[l], sz[r + 1] - 1, 0, cnt - 1) << "\n";
  }
}
