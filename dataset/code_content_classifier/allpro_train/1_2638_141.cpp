#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000001;
int main() {
  long long n;
  cin >> n;
  long long x, y, minx, miny, maxx, maxy;
  minx = M;
  miny = M;
  maxx = M * -1;
  maxy = M * -1;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    minx = min(x, minx);
    miny = min(y, miny);
    maxx = max(x, maxx);
    maxy = max(y, maxy);
  }
  long long ans = max(maxy - miny, maxx - minx);
  cout << ans * ans;
  return 0;
}
