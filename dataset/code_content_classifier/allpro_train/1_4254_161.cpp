#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
bitset<N> t, q[55];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m, n;
  cin >> m >> n;
  t.set(0);
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    for (int j = 1; j <= x; j++) {
      int k;
      cin >> k;
      q[i] |= (t << k);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      if (!(q[i] & q[j]).count()) {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }
  cout << "possible" << endl;
}
