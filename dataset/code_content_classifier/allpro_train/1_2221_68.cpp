#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, y, z, l;
  string s;
  cin >> n >> k;
  int lo = 1, hi = n;
  while (lo < hi) {
    int mid = (hi + lo) / 2;
    cout << "1 " << mid << " " << mid + 1 << "\n";
    fflush(stdout);
    cin >> s;
    if (s[0] == 'T')
      hi = mid;
    else
      lo = mid + 1;
  }
  x = lo;
  if (x != 1) {
    lo = 1, hi = x - 1;
    while (lo < hi) {
      int mid = (hi + lo) / 2;
      cout << "1 " << mid << " " << mid + 1 << "\n";
      fflush(stdout);
      cin >> s;
      if (s[0] == 'T')
        hi = mid;
      else
        lo = mid + 1;
    }
    y = lo;
    cout << "1 " << y << " " << x << "\n";
    cin >> s;
    if (s[0] != 'T') y++;
  }
  if (x == 1 || y == x) {
    lo = x + 1, hi = n;
    while (lo < hi) {
      int mid = (hi + lo) / 2;
      cout << "1 " << mid << " " << mid + 1 << "\n";
      fflush(stdout);
      cin >> s;
      if (s[0] == 'T')
        hi = mid;
      else
        lo = mid + 1;
    }
    y = lo;
  }
  cout << "2 " << x << " " << y << "\n";
  fflush(stdout);
  return 0;
}
