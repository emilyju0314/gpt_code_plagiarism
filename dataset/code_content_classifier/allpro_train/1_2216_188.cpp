#include <bits/stdc++.h>
using namespace std;
int a[5];
int kiemtra(int x, int y, int z) {
  if (x < y + z && y < z + x && z < x + y) return 1;
  if (x == y + z || y == x + z || z == x + y) return 2;
  return 0;
}
void solve() {
  int i, j, k, x, gan;
  gan = 0;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      for (k = 0; k < 4; k++)
        if (i != j && j != k && i != k) {
          x = kiemtra(a[i], a[j], a[k]);
          if (x == 1) {
            cout << "TRIANGLE\n";
            return;
          }
          if (x == 2) gan = 1;
        }
  if (gan == 1) {
    cout << "SEGMENT\n";
    return;
  }
  cout << "IMPOSSIBLE\n";
}
void input() {
  int i;
  while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
    solve();
  }
}
int main() {
  input();
  return 0;
}
