#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30);
const long long llinf = (1ll << 60);
const double eps = (1e-10);
const int xx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
const int yy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int main() {
  int n;
  scanf("%d", &n);
  int cnt[10] = {0};
  bool fl = true;
  char input[4][4];
  getchar();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      char x;
      scanf("%c", &x);
      if (x == '.') continue;
      cnt[x - '0']++;
      if (cnt[x - '0'] > (n * 2)) fl = false;
    }
    getchar();
  }
  if (fl)
    cout << "YES\n";
  else
    cout << "NO\n";
}
