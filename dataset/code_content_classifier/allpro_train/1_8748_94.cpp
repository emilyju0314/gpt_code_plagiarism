#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1123456;
const int MAXINT = 1e9;
const long long MAXLL = 9223372036854775258LL;
string s;
string get(int x, int y) {
  cout << x << " " << y << endl;
  cin >> s;
  return s;
}
int main() {
  int n, l = 1, r = 1e9 - 2, y = 1e9 - 228, max_pos = 1, min_pos = 1e9 + 1,
         need = 0, how = 1;
  char L, R;
  bool flag = 1;
  string z, z1;
  cin >> n;
  if (n == 1) {
    get(1, 1);
    cout << 0 << " " << 2 << " " << 2 << " " << 2 << endl;
    return 0;
  }
  if (get(1, y) == "black")
    L = 'b', R = 'w';
  else
    L = 'w', R = 'b';
  for (int i = 1; i < n; ++i) {
    int c = (l + r) / 2;
    if (abs(min_pos - c) < 4 || abs(max_pos - c) < 4) {
      need = n - i;
      break;
    }
    z = get(c, y);
    if (z[0] == L)
      l = c, max_pos = max(max_pos, c);
    else
      r = c, min_pos = min(min_pos, c);
  }
  min_pos = max_pos;
  if (need == 0) {
    cout << min_pos + 1 << " " << y << " " << min_pos + 1 << " " << y - 1
         << endl;
    return 0;
  }
  if (need == 1) {
    z = get(min_pos + 1, y + 1);
    if (z[0] == L)
      cout << min_pos + 1 << " " << y << " " << min_pos + 2 << " " << y + 1
           << endl;
    else
      cout << min_pos + 1 << " " << y << " " << min_pos - 1 << " " << y + 1
           << endl;
    return 0;
  }
  if (need == 2) {
    z = get(min_pos + 2, y + 1);
    z1 = get(min_pos + 2, y - 1);
    if (z[0] == z1[0]) {
      if (z[0] == L)
        cout << min_pos + 3 << " " << y << " " << min_pos + 3 << " " << y + 1
             << endl;
      else
        cout << min_pos + 1 << " " << y << " " << min_pos + 1 << " " << y + 1
             << endl;
    } else {
      if (z[0] == L)
        cout << min_pos + 2 << " " << y << " " << min_pos + 3 << " " << y + 1
             << endl;
      else
        cout << min_pos + 2 << " " << y << " " << min_pos + 1 << " " << y + 1
             << endl;
    }
  }
  return 0;
}
