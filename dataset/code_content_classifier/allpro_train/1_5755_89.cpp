#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, n2, m2;
  cin >> n >> n2 >> m >> m2;
  vector<int> o(n);
  for (int i = 0; i < n; i++) cin >> o[i];
  vector<int> k(n2);
  int lt;
  int c = 0;
  for (int i = 0; i < n2; i++) {
    cin >> lt;
    if (lower_bound(o.begin(), o.end(), lt) - o.begin() >= m) c++;
  }
  if (c >= m2)
    cout << "YES\n";
  else
    cout << "NO\n";
}
