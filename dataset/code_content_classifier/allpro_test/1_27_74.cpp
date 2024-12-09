#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const long long mod = 1e9 + 7;
long long fscn();
vector<vector<long long>> matrixMultiplication(vector<vector<long long>> &a,
                                               vector<vector<long long>> &b);
long long binpow(long long a, long long b);
long long binpow(long long a, long long b, long long m);
vector<vector<long long>> matrixBinPow(vector<vector<long long>> &a,
                                       long long b);
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n, m, k;
  cin >> n >> m >> k;
  int minDia;
  long long edges_for_complete_graph = (n * (n - 1)) / 2;
  if (m < n - 1 || m > edges_for_complete_graph)
    minDia = INT_MAX;
  else if (n == 1)
    minDia = 0;
  else if (m == edges_for_complete_graph)
    minDia = 1;
  else
    minDia = 2;
  if (minDia < k - 1)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long T;
  cin >> T;
  while (T--) solve();
}
long long fscn() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  bool negative = false;
  register int c;
  long long number = 0;
  c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) {
    number = number * 10 + c - 48;
  }
  if (negative) {
    number *= -1;
  }
  return number;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
vector<vector<long long>> matrixMultiplication(vector<vector<long long>> &a,
                                               vector<vector<long long>> &b) {
  int p = a.size(), q = a[0].size(), r = b[0].size();
  vector<vector<long long>> ans(p, vector<long long>(r, 0));
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < r; j++) {
      for (int k = 0; k < q; k++) {
        ans[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return ans;
}
vector<vector<long long>> matrixBinPow(vector<vector<long long>> &a,
                                       long long b) {
  vector<vector<long long>> res(a.size(), vector<long long>(a.size(), 0ll));
  for (long long i = 0; i < a.size(); i++) res[i][i] = 1ll;
  while (b > 0) {
    if (b & 1) res = matrixMultiplication(res, a);
    a = matrixMultiplication(a, a);
    b >>= 1;
  }
  return res;
}
