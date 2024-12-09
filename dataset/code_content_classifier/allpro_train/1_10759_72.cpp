#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9, oo = numeric_limits<double>::infinity();
double simplexMethodPD(vector<vector<double>> &A, vector<double> &b,
                       vector<double> &c, vector<double> &x) {
  int n = c.size(), m = b.size();
  vector<vector<double>> T(m + 1, vector<double>(n + m + 1));
  vector<int> base(n + m), row(m);
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) T[j][i] = A[j][i];
    T[j][n + j] = 1;
    base[row[j] = n + j] = 1;
    T[j][n + m] = b[j];
  }
  for (int i = 0; i < n; ++i) T[m][i] = c[i];
  while (1) {
    int p = 0, q = 0;
    for (int i = 0; i < n + m; ++i)
      if (T[m][i] <= T[m][p]) p = i;
    for (int j = 0; j < m; ++j)
      if (T[j][n + m] <= T[q][n + m]) q = j;
    double t = min(T[m][p], T[q][n + m]);
    if (t >= -eps) {
      x.resize(n);
      for (int i = 0; i < m; ++i)
        if (row[i] < n) x[row[i]] = T[i][n + m];
      return -T[m][n + m];
    }
    if (t < T[q][n + m]) {
      for (int j = 0; j < m; ++j)
        if (T[j][p] >= eps)
          if (T[j][p] * (T[q][n + m] - t) >= T[q][p] * (T[j][n + m] - t)) q = j;
      if (T[q][p] <= eps) return oo;
    } else {
      for (int i = 0; i < n + m + 1; ++i) T[q][i] = -T[q][i];
      for (int i = 0; i < n + m; ++i)
        if (T[q][i] >= eps)
          if (T[q][i] * (T[m][p] - t) >= T[q][p] * (T[m][i] - t)) p = i;
      if (T[q][p] <= eps) return -oo;
    }
    for (int i = 0; i < m + n + 1; ++i)
      if (i != p) T[q][i] /= T[q][p];
    T[q][p] = 1;
    base[p] = 1;
    base[row[q]] = 0;
    row[q] = p;
    for (int j = 0; j < m + 1; ++j)
      if (j != q) {
        double alpha = T[j][p];
        for (int i = 0; i < n + m + 1; ++i) T[j][i] -= T[q][i] * alpha;
      }
  }
  return oo;
}
bool SolveInteger(vector<vector<double>> &A, vector<double> &B,
                  vector<double> &C, long long &best,
                  vector<long long> &solution) {
  vector<double> x;
  double v = simplexMethodPD(A, B, C, x);
  if (v == oo || v == -oo) return false;
  if ((long long)ceil(v) >= best) return true;
  for (int i = 0; i < (int)x.size(); ++i) {
    double a = floor(x[i]);
    double b = ceil(x[i]);
    if (min(x[i] - a, b - x[i]) >= eps) {
      vector<vector<double>> NA = A;
      vector<double> NB = B;
      int vars = C.size();
      vector<double> nv(vars);
      nv[i] = -1;
      NA.push_back(nv);
      NB.push_back(-b);
      bool ok = SolveInteger(NA, NB, C, best, solution);
      NA.pop_back();
      NB.pop_back();
      nv[i] = 1;
      NA.push_back(nv);
      NB.push_back(a);
      ok |= SolveInteger(NA, NB, C, best, solution);
      return ok;
    }
  }
  long long cur_value = (long long)round(v);
  if (cur_value < best) {
    best = cur_value;
    solution = vector<long long>(x.begin(), x.end());
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for (int u, v, w; m--;) {
    cin >> u >> v >> w;
    --u, --v;
    adj[u].push_back({v, w});
  }
  vector<vector<double>> M;
  vector<double> b, c(n);
  for (int u = 0; u < n; ++u)
    for (auto v : adj[u]) {
      vector<double> x(n);
      x[u] = -1;
      x[v.first] = 1;
      b.push_back(-1);
      M.push_back(x);
      c[u] += v.second;
      c[v.first] -= v.second;
    }
  vector<double> x;
  auto ans = simplexMethodPD(M, b, c, x);
  assert(abs(ans) < 1e60);
  for (int i = 0; i < n; ++i) cout << round(x[i]) << " \n"[i + 1 == n];
  return 0;
}
