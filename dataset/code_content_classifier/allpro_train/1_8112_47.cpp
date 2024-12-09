#include <bits/stdc++.h>
using namespace std;
using LF = double;
using LL = long long;
using basis = complex<LF>;
const LF PI = acos(-1.0l);
const int N = 125005;
const int Maxb = 19;
const int Maxp = 450;
const int MOD = 13313;
vector<int> rev;
vector<basis> omega;
inline void calc_rev(int n, int log_n) {
  omega.assign(n, 0);
  rev.assign(n, 0);
  for (int i = 0; i < n; i++) {
    rev[i] = 0;
    for (int j = 0; j < log_n; j++) {
      if ((i >> j) & 1) rev[i] |= 1 << (log_n - j - 1);
    }
  }
}
inline void fft(vector<basis> &A, int n, bool invert) {
  for (int i = 0; i < n; i++) {
    if (i < rev[i]) swap(A[i], A[rev[i]]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    LF ang = 2 * PI / len * (invert ? -1 : +1);
    int half = (len >> 1);
    basis curomega(cos(ang), sin(ang));
    omega[0] = basis(1, 0);
    for (int i = 1; i < half; i++) omega[i] = omega[i - 1] * curomega;
    for (int i = 0; i < n; i += len) {
      basis t;
      int pu = i, pv = i + half, pu_end = i + half, pw = 0;
      for (; pu != pu_end; pu++, pv++, pw++) {
        t = A[pv] * omega[pw];
        A[pv] = A[pu] - t;
        A[pu] += t;
      }
    }
  }
  if (invert)
    for (int i = 0; i < n; i++) A[i] /= n;
}
inline void multiply(int n, vector<basis> &A, vector<basis> &B,
                     vector<int> &C) {
  fft(A, n, false);
  fft(B, n, false);
  for (int i = 0; i < n; i++) A[i] *= B[i];
  fft(A, n, true);
  for (int i = 0; i < n; i++) {
    C[i] = (int)(A[i].real() + 0.5);
  }
}
inline void solve(int n, vector<int> &coeffA, vector<int> &coeffB,
                  vector<int> &result) {
  vector<basis> A(n), B(n);
  for (int i = 0; i < n; i++) {
    A[i] = coeffA[i];
    B[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    B[i] = coeffB[i];
  }
  vector<int> C(n);
  multiply(n, A, B, C);
  for (int i = 0; i < n; i++) {
    int add = C[i];
    result[i] += add;
  }
}
inline void do_FFT(vector<int> &A, vector<int> &B, vector<int> &result) {
  int n = 1, bits = 0;
  while (n < 2 * A.size() || n < 2 * B.size()) n <<= 1, bits++;
  result.assign(n, 0);
  calc_rev(n, bits);
  vector<int> tempA(A.begin(), A.end());
  vector<int> tempB(B.begin(), B.end());
  tempA.resize(n);
  tempB.resize(n);
  solve(n, tempA, tempB, result);
}
int n, m;
string S, T;
vector<int> indexes[6][2];
vector<int> graph[N][6];
int vis[6];
int dfs(int u, int v) {
  int ans = 1;
  vis[v] = 1;
  for (auto k : graph[u][v]) {
    if (!vis[k]) ans += dfs(u, k);
  }
  return ans;
}
int work(int curr_position) {
  int ans = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 6; i++) {
    if (!vis[i]) ans += dfs(curr_position, i) - 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> S >> T;
  int i, j;
  n = S.size();
  m = T.size();
  for (i = 0; i <= n - 1; i++) {
    indexes[S[i] - 'a'][0].push_back(i);
  }
  for (j = 0; j <= m - 1; j++) {
    indexes[T[j] - 'a'][1].push_back(j);
  }
  for (i = 0; i <= 5; i++) {
    for (j = 0; j <= 5; j++) {
      if (i == j) continue;
      vector<int> polynomial1(n + 1, 0), polynomial2(m, 0);
      for (int x : indexes[i][0]) polynomial1[x] = 1;
      for (int x : indexes[j][1]) polynomial2[m - 1 - x] = 1;
      vector<int> res;
      do_FFT(polynomial1, polynomial2, res);
      for (int k = 0; k < n - m + 1; k++) {
        if (res[m - 1 + k]) {
          graph[k][i].push_back(j);
          graph[k][j].push_back(i);
        }
      }
    }
  }
  for (i = 0; i <= n - m; i++) {
    cout << work(i) << " ";
  }
  return 0;
}
