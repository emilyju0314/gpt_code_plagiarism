#include <bits/stdc++.h>
using namespace std;
int main() {
  float n, x, y;
  cin >> n >> x >> y;
  float ans = ceil((n * y) / 100);
  ans = ans - (float)x;
  int p = (int)ans;
  if (p >= 0)
    cout << p << endl;
  else
    cout << "0\n";
  return 0;
}
