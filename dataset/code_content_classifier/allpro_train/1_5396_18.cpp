#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 5;
const int inf = 1e9;
int main() {
  long long m, n;
  cin >> m >> n;
  n = m - n;
  long long aa = m, bb = n;
  int a[20] = {}, b[20] = {};
  int p = 0;
  while (m > 0) {
    p++;
    a[p] = m % 10;
    m /= 10;
  }
  int lena = p;
  p = 0;
  while (n > 0) {
    p++;
    b[p] = n % 10;
    n /= 10;
  }
  int lenb = p;
  for (int i = lena; i >= 1; i--) {
    if (a[i] == b[i])
      cout << a[i];
    else {
      bool ok = 1;
      for (int j = i - 1; j >= 1; j--)
        if (a[j] != 9) ok = 0;
      if (!ok) a[i]--;
      if (a[i] != 0 || i != lena) cout << a[i];
      for (int j = i - 1; j >= 1; j--) cout << 9;
      break;
    }
  }
}
