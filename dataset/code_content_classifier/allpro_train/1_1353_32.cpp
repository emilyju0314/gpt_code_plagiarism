#include <bits/stdc++.h>
using namespace std;
void swap(string &s, long long i, long long j) {
  char tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
}
int main() {
  long long i, j, k, m, n, t, x, y;
  long long a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0) {
    cout << "0" << endl;
    return 0;
  }
  double l0 = (sqrt(1 + 8 * a1) + 1) / 2;
  double l1 = (sqrt(1 + 8 * a4) + 1) / 2;
  long long len0 = l0;
  long long len1 = l1;
  if ((double)len0 != l0 || (double)len1 != l1) {
    cout << "Impossible" << endl;
    return 0;
  }
  if (len1 == 0) {
    if (a2 || a3) len1 = 1;
  }
  if (len0 == 0) {
    if (a2 || a3) len0 = 1;
  }
  long long tmp = len1 * len0;
  string s;
  if (a1 + a2 + a3 == 0 && a4) {
    while (len1--) {
      cout << '1';
    }
    cout << '\n';
    return 0;
  } else if (a2 + a3 + a4 == 0 && a1) {
    while (len0--) {
      cout << '0';
    }
    cout << '\n';
    return 0;
  } else if (tmp != a2 + a3) {
    cout << "Impossible" << endl;
    return 0;
  } else {
    long long end = a2 / len0, mid = 0, st = 0;
    if (a2 % len0 != 0) mid = a2 % len0, st--;
    st += len1 - end;
    while (st--) cout << '1';
    for (i = 1; i <= len0; i++) {
      cout << '0';
      if (mid == i) cout << '1';
    }
    while (end--) {
      cout << '1';
    }
    cout << '\n';
  }
  return 0;
}
