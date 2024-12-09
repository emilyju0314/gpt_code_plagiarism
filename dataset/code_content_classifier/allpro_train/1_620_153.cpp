#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int a1[1000] = {0};
  int b1[1000] = {0};
  int c1[1000] = {0};
  int i = 0, j = 0, k = 0;
  while (a > 0) {
    a1[i] = a % 3;
    i++;
    a = a / 3;
  }
  while (b > 0) {
    b1[j] = b % 3;
    j++;
    b = b / 3;
  }
  k = (i > j) ? i : j;
  for (int l = k - 1; l >= 0; l--) {
    c1[l] = (a1[l] + b1[l]) % 3;
  }
  for (int l = k - 1; l >= 0; l--) {
    c1[l] = (c1[l] + a1[l]) % 3;
  }
  int ans = 0;
  for (int l = k - 1; l >= 0; l--) {
    ans = ans * 3;
    ans += c1[l];
  }
  cout << ans;
  return 0;
}
