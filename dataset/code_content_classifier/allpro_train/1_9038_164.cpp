#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const bool debug = true;
const int MOD = 1e9 + 7;
const long long INFL = LLONG_MAX;
const int output_precision = 15;
stringstream ss;
int K, N, A[30], bad[2];
int f[1 << 24];
long long sum[1 << 24];
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(output_precision);
  cout << fixed;
  ss.precision(output_precision);
  ss << fixed;
  cin >> N;
  for (int(i) = 0, j1234 = N; (i) < j1234; (i)++) cin >> A[i];
  cin >> K;
  for (int(i) = 0, j1234 = K; (i) < j1234; (i)++) {
    int foo;
    cin >> foo;
    bad[i] = foo;
  }
  for (int i = 2; i > K; i--) bad[i - 1] = -1;
  f[0] = 1;
  for (int(i) = 1, j1234 = (1 << N) - 1; (i) <= j1234; (i)++) {
    long long s = sum[i];
    int cur = 1;
    long long sum = 0;
    for (int(j) = 0, j1234 = N; (j) < j1234; (j)++) {
      if (cur & i) {
        sum += A[j];
        f[i] += f[i ^ cur];
        if (f[i] > MOD) f[i] -= MOD;
      }
      cur <<= 1;
    }
    if (sum == bad[0] || sum == bad[1]) f[i] = 0;
  }
  cout << f[(1 << N) - 1] << '\n';
}
