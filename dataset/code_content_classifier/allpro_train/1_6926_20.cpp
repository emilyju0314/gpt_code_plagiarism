#include <bits/stdc++.h>
using namespace std;
int i, j, n, rez;
int main() {
  cin >> n;
  vector<int> v(n + 1);
  map<int, int> m;
  for (i = 1; i <= n; i++) {
    cin >> v[i];
    m[v[i]]++;
  }
  for (i = 1; i <= n; i++) {
    bool ok = false;
    for (j = 1; j < 31; j++) {
      int x = (1 << j) - v[i];
      if (m.count(x) && (m[x] > 1 || (m[x] == 1 && x != v[i]))) ok = true;
    }
    if (!ok) rez++;
  }
  cout << rez;
  return 0;
}
