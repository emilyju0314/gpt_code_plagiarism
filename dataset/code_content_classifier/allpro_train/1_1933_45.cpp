#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  srand(__rdtsc());
  int n;
  set<int> s;
  map<int, int> f;
  map<int, int> b;
  int fr, bc;
  cin >> n;
  int n2 = (n + 1) / 2;
  for (int i = 0; i < n; i++) {
    cin >> fr >> bc;
    s.insert(fr);
    s.insert(bc);
    f[fr]++;
    if (bc != fr) b[bc]++;
  }
  bool flag = true;
  int ans = n;
  for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
    if (f[*it] * 2 >= n) {
      cout << "0" << endl;
      return 0;
    }
    if ((f[*it] + b[*it]) >= n2) {
      flag = false;
      ans = min(ans, n2 - f[*it]);
    }
  }
  if (flag) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
