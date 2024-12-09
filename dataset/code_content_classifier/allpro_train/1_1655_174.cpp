#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int D = 1e8;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int iter = -200; iter <= 200; ++iter) {
    set<int> s;
    for (int i = 0; i < n; ++i) {
      if (a[i] > iter || a[i] < iter) s.insert(abs(a[i] - iter));
    }
    if (s.size() == 0) D = 0;
    if (s.size() == 1) D = min(D, *s.begin());
  }
  if (D == (int)1e8)
    cout << -1;
  else
    cout << D;
  return 0;
}
