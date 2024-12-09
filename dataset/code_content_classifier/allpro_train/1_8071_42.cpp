#include <bits/stdc++.h>
using namespace std;
long long seive[10000002][2];
void seiv() {
  for (long long i = 2; i <= 10000000; i++) {
    if (seive[i][0] > 0) continue;
    seive[i][0] = i;
    seive[i][1] = 1;
    for (long long j = 2 * i; j <= 10000000; j += i) {
      if (seive[j][0] == 0) {
        seive[j][0] = i;
      }
      if (seive[j][1] == 0) {
        seive[j][1] = 1;
      } else {
        seive[j][1] *= i;
      }
    }
  }
}
long long b[500002], c[500002], arr[500002];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long i = 0; i < n; i++) {
    long long x = arr[i];
    long long x1 = -1, x2 = -1;
    if (seive[x][1] != 1) {
      x1 = seive[x][0];
      x2 = seive[x][1];
    }
    b[i] = x1;
    c[i] = x2;
  }
  for (long long i = 0; i < n; i++) cout << b[i] << " ";
  cout << endl;
  for (long long i = 0; i < n; i++) cout << c[i] << " ";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  seiv();
  t = 1;
  for (long long T = 1; T <= t; T++) {
    solve();
  }
}
