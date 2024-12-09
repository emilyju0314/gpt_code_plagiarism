#include <bits/stdc++.h>
using namespace std;
string a;
string b;
int ans[1000 + 7];
int main() {
  int m, n, q;
  cin >> m >> n >> q;
  cin >> a >> b;
  int tmp = 0;
  for (int i = 0; i < m; i++) {
    if (a[i] == b[0]) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (a[i + j] == b[j])
          cnt++;
        else
          break;
      }
      if (cnt == n) tmp += 1;
    }
    ans[i + 1] = tmp;
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    y = y - n + 1;
    if (x > y)
      cout << "0" << endl;
    else
      cout << ans[y] - ans[x - 1] << endl;
  }
}
