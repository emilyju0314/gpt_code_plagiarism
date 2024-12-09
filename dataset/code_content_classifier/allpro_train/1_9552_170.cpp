#include <bits/stdc++.h>
using namespace std;
int who(int n, vector<int> &par) {
  if (n == par[n]) return n;
  return par[n] = who(par[n], par);
}
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    int flag = 0;
    cin >> n;
    vector<int> v(n), par(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (i && v[i] != v[i - 1]) flag = 1;
    }
    if (flag) {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) par[i] = i;
      int tmp;
      for (int i = 0; i < n; i++) {
        if (who(i, par) == i) {
          tmp = i;
          for (int j = i + 1; j < n; j++) {
            if (v[j] == v[i]) {
              par[who(j, par)] = who(i, par);
            }
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (who(i, par) != 0)
          cout << i + 1 << " " << 1 << endl;
        else if (i)
          cout << i + 1 << " " << tmp + 1 << endl;
      }
    } else
      cout << "NO" << endl;
  }
}
