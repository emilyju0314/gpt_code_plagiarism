#include <bits/stdc++.h>
using namespace std;
long long int n, t, sz, sf, a, b;
pair<int, pair<int, int> > p[200000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i < 2 * n; i++) {
      cin >> a >> b;
      p[i] = make_pair(a, make_pair(b, i));
    }
    sort(p + 1, p + 2 * n);
    sf = 0, sz = 0;
    for (int i = 1; i < 2 * n; i++)
      if (i % 2)
        sf += p[i].second.first;
      else
        sz += p[i].second.first;
    cout << "YES" << endl;
    if (sf > sz) {
      for (int i = 1; i < 2 * n; i++) {
        if (i % 2) cout << p[i].second.second << ' ';
      }
    } else {
      for (int i = 1; i < 2 * n; i++) {
        if (i % 2 == 0 or i == 2 * n - 1) cout << p[i].second.second << ' ';
      }
    }
    cout << endl;
  }
}
