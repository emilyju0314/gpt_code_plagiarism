#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  unsigned long long int n, k, m, d, i, f, ans, cou = 0, p;
  cin >> n >> k >> m >> d;
  for (i = 1; i <= d; i++) {
    f = (k * (i - 1)) + 1;
    if ((i - 1) != 0) {
      if (((f - 1) / (i - 1)) != k || f == 0) {
        f = 1300000000000000000;
      }
    }
    ans = n / f;
    if (ans > m) {
      ans = m;
    }
    cou = max(cou, ans * i);
  }
  cout << cou << "\n";
}
