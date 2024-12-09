#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int c, hr, hb, wr, wb, ans = 0;
  cin >> c >> hr >> hb >> wr >> wb;
  for (int i = 0; i <= 100000; i++) {
    if (c >= wr * i) ans = max(ans, (hr * i) + (hb * ((c - wr * i) / wb)));
    if (c >= wb * i) ans = max(ans, (hb * i) + (hr * ((c - wb * i) / wr)));
  }
  cout << ans << endl;
  return 0;
}
