#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, i, j;
    cin >> n >> m;
    long long int a[n][m];
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cin >> a[i][j];
        if ((i + j) % 2 != a[i][j] % 2) a[i][j]++;
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
