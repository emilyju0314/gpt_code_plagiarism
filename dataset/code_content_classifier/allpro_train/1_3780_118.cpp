#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  n--;
  long long int K;
  K = ((n * n) + n) / 2;
  if (K < m) {
    cout << "Impossible";
    return 0;
  }
  if (K == m) {
    for (int i = 0; i <= n; i++) cout << "(";
    for (int i = 0; i <= n; i++) cout << ")";
    return 0;
  }
  int t = 0;
  while (K > m) {
    K -= n--;
    t++;
  }
  if (K <= m) {
    int diff = m - K;
    for (int i = 0; i <= n; i++) {
      if (diff == i && t--) cout << "()";
      cout << "(";
    }
    for (int i = 0; i <= n; i++) {
      cout << ")";
    }
    for (int i = 0; i < t; i++) cout << "()";
    cout << endl;
  }
  return 0;
}
