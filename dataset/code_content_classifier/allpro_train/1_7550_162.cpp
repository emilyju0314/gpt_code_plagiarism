#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    long long m;
    cin >> l >> r >> m;
    for (int i = l; i <= r; ++i) {
      long long down = 1ll * (m - 1) / i * i;
      long long up = 1ll * (m - 1) / i * i + i;
      long long diff = abs(m - down);
      if (diff <= r - l and down != 0) {
        cout << i << " " << l + diff << " " << l << '\n';
        break;
      }
      diff = up - m;
      if (diff <= r - l) {
        cout << i << " " << l << " " << l + diff << '\n';
        break;
      }
    }
  }
  return 0;
}
