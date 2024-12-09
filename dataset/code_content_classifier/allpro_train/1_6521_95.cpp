#include <bits/stdc++.h>
using namespace std;
bool ff[15];
bool chk(int a, int b) {
  for (int i = 0; i < 10; i++) ff[i] = false;
  while (a != 0) {
    ff[a % 10] = true;
    a /= 10;
  }
  while (b != 0) {
    if (ff[b % 10]) return true;
    b /= 10;
  }
  return false;
}
int main() {
  int n;
  int ans = 0;
  cin >> n;
  for (int i = 1; i <= (int)sqrt(n); i++) {
    if (n % i == 0 || i == 1) {
      if (chk(n, i)) ans++;
      if (i * i != n && chk(n, n / i)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
