#include <bits/stdc++.h>
using namespace std;
inline void beg();
inline void fin();
const int N = 5e3 + 5;
int n, m;
map<string, int> tab;
int v1[N], o[N], v2[N], type[N], bit[N];
int ans1[N], ans2[N];
string val[N];
int justdoit(int a, int b, int c) {
  if (!c)
    return a ^ b;
  else if (c == 1)
    return a & b;
  else
    return a | b;
}
int main() {
  beg();
  cin >> n >> m;
  tab["?"] = n;
  for (int i = 0; i < n; i++) {
    string var, result;
    cin >> var >> result >> result;
    tab[var] = i;
    if (result[0] <= '1') {
      type[i] = 1;
      val[i] = result;
      continue;
    }
    string op, var2;
    cin >> op >> var2;
    v1[i] = tab[result];
    o[i] = (op[0] == 'X' ? 0 : (op[0] == 'A' ? 1 : 2));
    v2[i] = tab[var2];
  }
  for (int i = 0; i < m; i++) {
    int res = -1;
    for (int b = 0; b < 2; b++) {
      int sum = 0;
      bit[n] = b;
      for (int j = 0; j < n; j++) {
        if (type[j] == 1) {
          sum += (val[j][i] == '1');
          bit[j] = val[j][i] - '0';
        } else {
          int x = justdoit(bit[v1[j]], bit[v2[j]], o[j]);
          sum += x;
          bit[j] = x;
        }
      }
      if (res == -1)
        res = sum;
      else {
        if (sum > res)
          ans2[i] = b;
        else if (sum < res)
          ans1[i] = b;
      }
    }
  }
  for (int i = 0; i < m; i++) cout << ans1[i];
  cout << endl;
  for (int i = 0; i < m; i++) cout << ans2[i];
  cout << endl;
  fin();
  return 0;
}
inline void beg() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
}
inline void fin() {}
