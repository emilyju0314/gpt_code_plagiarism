#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a;
  cin >> n >> m >> a;
  n = ceil(n * 1.0 / a);
  m = ceil(m * 1.0 / a);
  cout << n * m << endl;
  return 0;
}
