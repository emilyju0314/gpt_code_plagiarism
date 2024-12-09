#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, r, c1 = 1, sw = 0, i, j = 0;
  long long a[101000], b[101000];
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> a[i];
    if (i > 0 && a[i] == a[i - 1])
      c1++;
    else if (i > 0) {
      b[j] = c1;
      j++;
      c1 = 1;
    }
  }
  b[j] = c1;
  if (j == 0) {
    cout << "YES";
  } else {
    for (i = 1; i <= j; ++i) {
      if (b[i] != b[i - 1]) sw = 1;
    }
    if (sw == 0)
      cout << "YES";
    else
      cout << "NO";
  }
}
