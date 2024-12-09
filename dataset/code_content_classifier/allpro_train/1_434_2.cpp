#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int p[n], s[n], c[k];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      if (s[c[i] - 1] == s[j] && p[c[i] - 1] < p[j]) {
        cnt++;
        break;
      }
    }
  }
  cout << cnt;
  return 0;
}
