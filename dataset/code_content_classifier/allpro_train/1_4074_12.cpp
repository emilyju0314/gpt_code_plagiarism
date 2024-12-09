#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
int N;
vector<int> edge[MAXN];
long double pascal[MAXN][MAXN];
long double C(int x, int y) { return pascal[x][y]; }
long double eval(vector<long double> v) { return v[(int)v.size() - 1]; }
vector<long double> append(vector<long double> v) {
  vector<long double> res;
  for (int i = 0; i <= v.size(); i++) res.push_back(0.0);
  int nsize = v.size();
  for (int i = 0; i <= nsize; i++) {
    for (int j = 0; j < i; j++) {
      res[i] += v[j] / nsize / 2.;
    }
    if (i < nsize) res[i] += v[i] * (nsize - i) / nsize;
  }
  return res;
}
vector<long double> combine(vector<long double> l, vector<long double> r) {
  vector<long double> res;
  int ntot = l.size() + r.size() - 1;
  for (int i = 0; i < ntot; i++) res.push_back(0.0);
  for (int i = 0; i < l.size(); i++)
    for (int j = 0; j < r.size(); j++) {
      res[i + j] += l[i] * r[j] * C(i + j, i) *
                    C(ntot - 1 - i - j, l.size() - i - 1) /
                    C(ntot - 1, l.size() - 1);
    }
  return res;
}
vector<long double> flood(int cloc, int last) {
  vector<long double> v;
  v.push_back(1.0);
  for (int neigh : edge[cloc]) {
    if (neigh == last) continue;
    vector<long double> nv = flood(neigh, cloc);
    nv = append(nv);
    v = combine(v, nv);
  }
  return v;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  pascal[0][0] = 1;
  for (int i = 1; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++) {
      pascal[i][j] = pascal[i - 1][j];
      if (j) pascal[i][j] += pascal[i - 1][j - 1];
    }
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  cout << fixed << setprecision(8);
  for (int i = 0; i < N; i++) {
    vector<long double> v = flood(i, -1);
    cout << eval(v) << "\n";
  }
}
