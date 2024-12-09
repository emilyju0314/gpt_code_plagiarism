#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, mod = 1e9, Maxn = 1e6;
int a[1005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (!(n & 1)) {
    cout << "Marsel" << endl;
    return 0;
  }
  int flag = 1;
  int i;
  for (i = 1; i * i <= m; i++) {
    if (m % i) continue;
    if (i >= k && m / i > 1) {
      flag = 0;
    }
    if (m / i >= k && i > 1) {
      flag = 0;
    }
  }
  if (flag) {
    cout << "Marsel" << endl;
  } else
    cout << "Timur" << endl;
  return 0;
}
