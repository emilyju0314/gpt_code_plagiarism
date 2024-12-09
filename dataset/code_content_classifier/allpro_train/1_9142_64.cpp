#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  long long i, j, k, l, co = 0;
  long long n, m, t;
  cin >> n >> m;
  if (n == 2) {
    if (m == 1)
      cout << 4 << endl;
    else
      cout << 5 << endl;
  } else if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 ||
             n == 12) {
    if (m == 6 || m == 7)
      cout << 6 << endl;
    else
      cout << 5 << endl;
  } else {
    if (m == 7)
      cout << 6 << endl;
    else
      cout << 5 << endl;
  }
  return 0;
}
