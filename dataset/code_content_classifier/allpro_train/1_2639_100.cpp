#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n = 0, j = 0, k = 0, i = 0;
  cin >> n >> k;
  long long int a[n];
  for (i = 0; i < (n); i++) cin >> (a)[i];
  ;
  long long int mi = 0, ma = 0;
  mi = 9e18;
  for (i = 0; i < n; i++) {
    ma = max(ma, a[i]);
    mi = min(mi, a[i]);
  }
  if (ma - mi > k)
    cout << "NO\n";
  else {
    cout << "YES";
    cout << "\n";
    ;
    for (i = 0; i < n; i++) {
      for (j = 0; j < mi; j++) cout << "1 ";
      for (j = 1; j <= (a[i] - mi); j++) cout << j << " ";
      cout << "\n";
      ;
    }
  }
  return 0;
}
