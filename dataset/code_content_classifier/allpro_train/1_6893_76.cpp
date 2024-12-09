#include <bits/stdc++.h>
using namespace std;
map<int, int> M;
map<int, vector<int> > O;
int f(int u) {
  if (u == 0) return 0;
  if (M.count(u) > 0) return M[u];
  int a = 0, v;
  bool MEX[30];
  for (int i = 0; i < 30; i++) MEX[i] = 0;
  for (int i = 1; i < 30; i++) {
    v = (u >> i) | a;
    if (u <= v) continue;
    if (f(v) < 30) MEX[f(v)] = 1;
    a |= u & (1 << (i - 1));
  }
  for (int i = 0; i < 30; i++)
    if (!MEX[i]) return M[u] = i;
}
int main() {
  int n, x, p;
  while (cin >> n) {
    O.clear();
    for (int i = 0; i < n; i++) {
      M.clear();
      cin >> x;
      while (x > 1) {
        p = x;
        for (int j = 2; j * j <= x; j++)
          if (x % j == 0) {
            p = j;
            break;
          }
        M[p]++;
        x /= p;
      }
      for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
        O[it->first].push_back(it->second);
      }
    }
    int r = 0;
    M.clear();
    for (map<int, vector<int> >::iterator it = O.begin(); it != O.end(); it++) {
      int o = 0;
      for (int i = 0; i < (it->second).size(); i++) {
        o |= (1 << ((it->second)[i] - 1));
      }
      r ^= f(o);
    }
    if (r)
      cout << "Mojtaba" << endl;
    else
      cout << "Arpa" << endl;
  }
  return 0;
}
