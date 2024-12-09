#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000LL * 1000000LL;
const long long MOD = 1000000007;
int f(long long a) {
  int left = 0;
  int right = 1000001;
  while (left < right) {
    int mid = (left + right + 1) / 2;
    if (a >= (1LL * mid * (mid - 1)) / 2)
      left = mid;
    else
      right = mid - 1;
  }
  return left;
}
int nn0, nn1;
void print(int i) {
  if (i == 1) {
    if (nn1) cout << '1';
    nn1--;
  } else {
    if (nn0) cout << '0';
    nn0--;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a00, a01, a10, a11;
  cin >> a00 >> a01 >> a10 >> a11;
  if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
    cout << "0\n";
    return 0;
  }
  if (a00 == 0) {
    if (a11 == 0) {
      if (a01 == 1 && a10 == 0) {
        cout << "01\n";
      } else if (a01 == 0 && a10 == 1) {
        cout << "10\n";
      } else {
        cout << "Impossible\n";
      }
    } else {
      int n1 = f(a11);
      if ((1LL * n1 * (n1 - 1)) / 2 != a11)
        cout << "Impossible\n";
      else {
        if (a01 + a10 == 0) {
          for (int i = 0; i < n1; i++) cout << '1';
          cout << '\n';
        } else {
          if (a01 + a10 != n1)
            cout << "Impossible\n";
          else {
            for (int i = 0; i < a10; i++) cout << '1';
            cout << '0';
            for (int i = 0; i < a01; i++) cout << '1';
            cout << '\n';
          }
        }
      }
    }
    return 0;
  }
  if (a11 == 0) {
    int n0 = f(a00);
    if ((1LL * n0 * (n0 - 1)) / 2 != a00)
      cout << "Impossible\n";
    else {
      if (a01 + a10 == 0) {
        for (int i = 0; i < n0; i++) cout << '0';
        cout << '\n';
      } else {
        if (a01 + a10 != n0)
          cout << "Impossible\n";
        else {
          for (int i = 0; i < a01; i++) cout << '0';
          cout << '1';
          for (int i = 0; i < a10; i++) cout << '0';
          cout << '\n';
        }
      }
    }
    return 0;
  }
  bool sol = true;
  int n0 = f(a00);
  if ((1LL * n0 * (n0 - 1)) / 2 != a00) sol = false;
  int n1 = f(a11);
  if ((1LL * n1 * (n1 - 1)) / 2 != a11) sol = false;
  long long b0 = 1LL * n0 * n1 - a01;
  long long b1 = 0;
  int prefix = b0 / n0;
  b0 -= 1LL * prefix * n0;
  b1 += 1LL * prefix * n0;
  if (a10 - b1 != b0) sol = false;
  if (sol == false)
    cout << "Impossible\n";
  else {
    nn0 = n0;
    nn1 = n1;
    for (int i = 1; i <= prefix; i++) print(1);
    for (int i = 0; i < n0; i++) {
      if (b0 == n0 - i)
        print(1);
      else
        print(0);
    }
    if (b0 != 0)
      print(0);
    else
      print(1);
    for (int i = 1; i <= n1 - prefix - 1; i++) print(1);
    cout << '\n';
  }
  return 0;
}
