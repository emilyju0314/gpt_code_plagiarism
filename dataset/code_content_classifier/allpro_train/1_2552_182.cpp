#include <bits/stdc++.h>
using namespace std;
map<string, int> mapa;
int main() {
  string t1, t2;
  int n, i, ans = 0;
  scanf("%d\n", &n);
  for (i = 0; i < n; ++i) {
    getline(cin, t1);
    if (mapa[t1] == 0) {
      mapa[t1] = 1;
      ++ans;
    }
  }
  cout << ans;
  return 0;
}
