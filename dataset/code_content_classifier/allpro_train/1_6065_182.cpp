#include <bits/stdc++.h>
using namespace std;
int c[401];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> c[i];
  int ans = -1;
  for (int i = 1; i < n; i++) {
    for (int j = i; j < n; j++) {
      int p = c[i - 1] - 1, cnt = 1, w = c[j];
      for (int k = i; k <= j; k++) {
        cnt += p / c[k];
        w += p / c[k] * c[k];
        p %= c[k];
      }
      p = w;
      for (int k = 0; k < n; k++) {
        cnt -= p / c[k];
        p %= c[k];
      }
      if (cnt < 0 && (ans == -1 || w < ans)) ans = w;
    }
  }
  cout << ans << endl;
  return 0;
}
