#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
set<long long> se;
map<long long, long long> ma;
int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    se.insert(a[i]);
  }
  sort(a, a + n);
  long long ans = 0;
  vector<long long> bla;
  for (int i = n - 1; i >= 0; i--) {
    for (long long j = 0; j < 33; j++) {
      long long u = powl(2, j);
      long long xx = a[i];
      long long ma = 1;
      vector<long long> vv;
      vv.push_back(xx);
      while (se.count(xx - u)) {
        ma++;
        xx -= u;
        vv.push_back(xx);
        if (ma >= 3) break;
      }
      if (ma > ans) {
        ans = ma;
        bla.clear();
        for (int h = 0; h < vv.size(); h++) {
          bla.push_back(vv[h]);
        }
      }
      vv.clear();
    }
  }
  cout << ans << endl;
  for (int i = 0; i < ans; i++) {
    cout << bla[i] << " ";
  }
  return 0;
}
