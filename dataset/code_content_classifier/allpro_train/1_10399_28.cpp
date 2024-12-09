#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
long long a[MAXN], b[MAXN];
int main() {
  int x;
  cin >> x;
  for (int i = 1; i <= x; i++)
    for (int j = 1; j <= x; j++) {
      if (i * j > x && (i / j) < x && (i % j == 0)) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  cout << -1 << endl;
  return 0;
}
