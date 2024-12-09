#include <bits/stdc++.h>
using namespace std;
void sol() {
  long long c, cc, ccc, a, b, n, m;
  cin >> a >> b >> n >> m;
  c = min(a, b);
  cc = max(a, b);
  if (((cc - n) > c && (c < m)) || (a + b) < (n + m) || c < m) {
    cout << "NO" << endl;
  } else
    cout << "YES" << endl;
}
int main() {
  int Q;
  cin >> Q;
  while (Q--) sol();
  return 0;
}
