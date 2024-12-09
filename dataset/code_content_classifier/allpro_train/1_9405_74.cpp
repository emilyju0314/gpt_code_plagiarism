#include <bits/stdc++.h>
using namespace std;
void File() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long x, y;
  cin >> x >> y;
  long long dia1 = x + y, dia2 = (x - y + n);
  pair<char, long long> R1 = {'a', LLONG_MIN}, R2 = {'a', LLONG_MAX},
                        C1 = {'a', LLONG_MIN}, C2 = {'a', LLONG_MAX},
                        D1 = {'a', LLONG_MIN}, D11 = {'a', LLONG_MAX},
                        D2 = {'a', LLONG_MIN}, D22 = {'a', LLONG_MAX};
  for (int i = 0; i < n; ++i) {
    char ch;
    long long xi, yi;
    cin >> ch >> xi >> yi;
    if (xi == x) {
      if (y > yi) {
        if (yi > R1.second) {
          R1.second = yi;
          R1.first = ch;
        }
      } else {
        if (yi < R2.second) {
          R2.second = yi;
          R2.first = ch;
        }
      }
    }
    if (yi == y) {
      if (x > xi) {
        if (xi > C1.second) {
          C1.second = xi;
          C1.first = ch;
        }
      } else {
        if (xi < C2.second) {
          C2.second = xi;
          C2.first = ch;
        }
      }
    }
    if (xi + yi == dia1) {
      if (x > xi) {
        if (xi > D1.second) {
          D1.second = xi;
          D1.first = ch;
        }
      } else {
        if (xi < D11.second) {
          D11.second = xi;
          D11.first = ch;
        }
      }
    }
    if ((xi - yi + n) == dia2) {
      if (x > xi) {
        if (xi > D2.second) {
          D2.second = xi;
          D2.first = ch;
        }
      } else {
        if (xi < D22.second) {
          D22.second = xi;
          D22.first = ch;
        }
      }
    }
  }
  if (R1.second != LLONG_MIN) {
    if (R1.first == 'R' || R1.first == 'Q') {
      cout << "YES" << endl;
      return 0;
    }
  }
  if (R2.second != LLONG_MAX) {
    if (R2.first == 'R' || R2.first == 'Q') {
      cout << "YES" << endl;
      return 0;
    }
  }
  if (C1.second != LLONG_MIN) {
    if (C1.first == 'R' || C1.first == 'Q') {
      cout << "YES" << endl;
      return 0;
    }
  }
  if (C2.second != LLONG_MAX) {
    if (C2.first == 'R' || C2.first == 'Q') {
      cout << "YES" << endl;
      return 0;
    }
  }
  if (D1.second != LLONG_MIN) {
    if (D1.first == 'B' || D1.first == 'Q') {
      cout << "YES" << endl;
      return 0;
    }
  }
  if (D11.second != LLONG_MAX) {
    if (D11.first == 'B' || D11.first == 'Q') {
      cout << "YES" << endl;
      return 0;
    }
  }
  if (D2.second != LLONG_MIN) {
    if (D2.first == 'B' || D2.first == 'Q') {
      cout << "YES" << endl;
      return 0;
    }
  }
  if (D22.second != LLONG_MAX) {
    if (D22.first == 'B' || D22.first == 'Q') {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
