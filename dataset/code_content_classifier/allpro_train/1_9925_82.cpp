#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
int main() {
  int n;
  cin >> n;
  int from = -1e9;
  int to = 1e9;
  int add = 0;
  for (int i = (0); i < (n); i++) {
    int c, d;
    cin >> c >> d;
    if (d == 1) {
      from = max(from, 1900 - add);
    } else if (d == 2) {
      to = min(to, 1899 - add);
    }
    add += c;
  }
  if (from > to)
    puts("Impossible");
  else if (to == 1e9)
    puts("Infinity");
  else
    cout << to + add << endl;
  return 0;
}
