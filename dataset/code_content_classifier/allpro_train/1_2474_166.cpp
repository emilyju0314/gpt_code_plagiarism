#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  int x, res = 0, c = 0;
  string a, b;
  cin >> x >> a >> b;
  if (b == "month")
    for (int j = 1; j <= 12; ++j) {
      if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
        if (x <= 31) res++;
      if (j == 4 || j == 6 || j == 9 || j == 11)
        if (x <= 30) res++;
      if (j == 2)
        if (x <= 29) res++;
    }
  else {
    if (x == 5 || x == 6) {
      cout << 53;
      return 0;
    } else {
      cout << 52;
      return 0;
    }
  }
  cout << res;
  return 0;
}
