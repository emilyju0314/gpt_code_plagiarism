#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(double(-1));
int main() {
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  cnt = b / a;
  cnt += ((b % a) == 0) ? 0 : 1;
  cout << cnt << endl;
  return 0;
}
