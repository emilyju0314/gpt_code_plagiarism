#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1e3 + 10;
const int MATRIX_SIZE = 64;
struct Matrix_Power {
  long long AA[60][MATRIX_SIZE][MATRIX_SIZE], aa[62][MATRIX_SIZE];
  int N;
  void set(long long _A[][MATRIX_SIZE], int _N,
           long long bb = (long long)1e10) {
    N = _N;
    for (int i = 0; i < (N); ++i)
      for (int j = 0; j < (N); ++j) AA[0][i][j] = _A[i][j];
    for (int round = (1); round < (60); ++round) {
      if ((1LL << round) > bb) break;
      for (int i = 0; i < (N); ++i)
        for (int j = 0; j < (N); ++j) AA[round][i][j] = 0;
      for (int i = 0; i < (N); ++i)
        for (int j = 0; j < (N); ++j)
          for (int k = 0; k < (N); ++k) {
            AA[round][i][k] += AA[round - 1][i][j] * AA[round - 1][j][k];
            AA[round][i][k] %= MOD;
          }
    }
  }
  void get(long long _a[], long long v, long long ret[]) {
    memset((aa), 0, sizeof((aa)));
    for (int i = 0; i < (N); ++i) aa[0][i] = _a[i];
    for (int i = 0; i < (61); ++i) {
      if ((1LL << i) > v) {
        memcpy(ret, aa[i], sizeof(long long) * 64);
        return;
      }
      if ((v >> i) & 1) {
        for (int j = 0; j < (N); ++j)
          for (int k = 0; k < (N); ++k) {
            aa[i + 1][j] += AA[i][j][k] * aa[i][k];
            aa[i + 1][j] %= MOD;
          }
      } else
        for (int j = 0; j < (N); ++j) aa[i + 1][j] = aa[i][j];
    }
  }
} mat;
long long A[MATRIX_SIZE][MATRIX_SIZE];
long long a[MATRIX_SIZE];
int relate[3][3];
int tran[3][MATRIX_SIZE][MATRIX_SIZE];
void build() {
  for (int i = 0; i < (3); ++i)
    for (int j = 0; j < (3); ++j) R(relate[i][j]);
  for (int col = 0; col < (3); ++col) {
    for (int j = 0; j < (64); ++j) {
      int tmp[3] = {j & 3, (j & 12) >> 2, (j & 48) >> 4};
      int ss[4] = {};
      for (int k = 0; k < (3); ++k) {
        if (relate[col][k]) ss[tmp[k]] = 1;
      }
      int me = 0;
      while (ss[me]) me++;
      tran[col][(j * 4 + me) & 63][j]++;
      A[(j * 4 + me) & 63][j]++;
    }
  }
  mat.set(A, 64);
}
vector<pair<int, int> > ban[SIZE];
int input[SIZE];
void solve(vector<pair<int, int> > &pp, int n, long long ret[]) {
  for (int i = 0; i < (4); ++i) ret[i] = 0;
  sort((pp).begin(), (pp).end());
  int now = 0;
  memset((a), 0, sizeof((a)));
  a[63] = 1;
  for (int i = 0; i < (((int)(pp).size())); ++i) {
    if (now + 1 != pp[i].first) {
      long long res[64];
      mat.get(a, pp[i].first - now - 1, res);
      memcpy(a, res, sizeof(long long) * 64);
    }
    long long tmp[64] = {};
    for (int j = 0; j < (64); ++j)
      for (int k = 0; k < (64); ++k)
        ADD(tmp[j], tran[pp[i].second - 1][j][k] * a[k]);
    memcpy(a, tmp, sizeof(long long) * 64);
    now = pp[i].first;
  }
  if (now != n) {
    long long res[64];
    mat.get(a, n - now, res);
    memcpy(a, res, sizeof(long long) * 64);
  }
  for (int i = 0; i < (64); ++i) ADD(ret[i & 3], a[i]);
}
int main() {
  MOD = 998244353;
  int n;
  R(n);
  for (int i = (1); i <= (n); ++i) R(input[i]);
  int m;
  R(m);
  for (int i = 0; i < (m); ++i) {
    int x, y, v;
    R(x, y, v);
    ban[x].push_back({y, v});
  }
  build();
  long long dp[2][4] = {};
  int now = 0, nxt = 1;
  dp[now][0] = 1;
  for (int i = (1); i <= (n); ++i) {
    long long ret[4];
    solve(ban[i], input[i], ret);
    memset((dp[nxt]), 0, sizeof((dp[nxt])));
    for (int j = 0; j < (4); ++j)
      for (int k = 0; k < (4); ++k) {
        ADD(dp[nxt][j ^ k], dp[now][j] * ret[k]);
      }
    swap(now, nxt);
  }
  W(dp[now][0]);
  return 0;
}
