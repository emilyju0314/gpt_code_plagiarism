#include <bits/stdc++.h>
using namespace std;
long long n, h, current, mx, H, m[20000], y[20000], t[20000], j, l, ans[10];
bool buv[20000];
int main() {
  cin >> n >> h;
  mx = 0;
  H = h;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> y[i] >> m[i];
    if (m[i] > mx && y[i] <= h) {
      mx = m[i];
      j = i;
    }
  }
  for (int z = 1; z <= 2; z++) {
    for (int i = 1; i <= n; i++) buv[i] = 0;
    current = z - 1;
    h = H;
    for (int i = 1; i <= n; i++) {
      l = 0;
      mx = 0;
      for (int j = 1; j <= n; j++)
        if (t[j] == (current + 1) % 2 && m[j] > mx && y[j] <= h &&
            buv[j] != 1) {
          mx = m[j];
          l = j;
        }
      if (l != 0) {
        ans[z]++;
        buv[l] = true;
        h += mx;
        current++;
      }
    }
  }
  cout << max(ans[1], ans[2]) << endl;
}
