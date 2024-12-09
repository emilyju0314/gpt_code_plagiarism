#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  int res = 1;
  for (int i = 2; i <= min(a, b); ++i) res *= i;
  cout << res << endl;
  return 0;
}
