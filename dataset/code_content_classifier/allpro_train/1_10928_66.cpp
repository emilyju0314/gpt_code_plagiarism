#include <bits/stdc++.h>
using namespace std;
const int n = 1e6 + 5;
int M, m;
void slove(long long a) {
  while (a) {
    int t = a % 10;
    M = max(M, t);
    m = min(m, t);
    a /= 10;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, k;
    cin >> a >> k;
    for (int i = 1; i < k; i++) {
      M = 0, m = 1e9;
      slove(a);
      a += M * m;
      if (M * m == 0) break;
    }
    cout << a << endl;
  }
}
