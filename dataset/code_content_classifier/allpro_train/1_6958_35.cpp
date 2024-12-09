#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, m, t1, t2;
  cin >> n >> m;
  vector<unsigned long long> d;
  unsigned long long l, r = 0;
  for (l = 1; l <= m && (l * (l - 1) / 2) + (l & 1 ? 0 : (l / 2 - 1)) <= n - 1;
       ++l)
    ;
  --l;
  cerr << l << endl;
  for (int i = 0; i < m; ++i) {
    cin >> t1 >> t2;
    d.push_back(t2);
  }
  sort(d.begin(), d.end());
  for (int i = 1; i <= l; ++i) {
    r += d[d.size() - i];
  }
  cout << r << endl;
}
