#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, u, k, j;
  long double best, tmp;
  cin >> n >> u;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  best = -1;
  k = 0;
  for (int i = 0; i < n - 1; i++) {
    j = i + 1;
    while (k + 1 < n && v[k + 1] - v[i] <= u) {
      k++;
    }
    if (k - i >= 2) {
      tmp = (long double)(v[k] - v[j]) / (long double)(v[k] - v[i]);
      if (tmp > best) {
        best = tmp;
      }
    }
  }
  if (best < 0) {
    cout << "-1\n";
  } else {
    cout << fixed << setprecision(12) << best << '\n';
  }
  return 0;
}
