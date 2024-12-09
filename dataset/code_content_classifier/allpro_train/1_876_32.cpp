#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  long long x, y, z;
  cin >> x >> y >> z;
  long long ans = 0, dif = 0;
  if ((x + y) / z > x / z + y / z) {
    ans = (x + y) / z;
    dif = min(z - x % z, z - y % z);
  } else {
    ans = x / z + y / z;
    dif = 0;
  }
  cout << ans << " " << dif;
  return 0;
}
