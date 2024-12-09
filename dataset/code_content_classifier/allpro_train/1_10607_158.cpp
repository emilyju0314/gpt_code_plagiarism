#include <bits/stdc++.h>
using namespace std;
int f[10];
int ans[10];
int len;
long long n;
int get(int x, int y) {
  int ans = 0;
  for (int i = 1; i <= x; i++) {
    int t = i;
    while (t % y == 0) {
      ans++;
      t /= y;
    }
  }
  return ans;
}
int main() {
  cin >> len;
  cin >> n;
  while (n) {
    int d = n % 10;
    for (int i = 1; i <= d; i++) {
      int t = i;
      while (t % 2 == 0) f[1]++, t /= 2;
      while (t % 3 == 0) f[2]++, t /= 3;
      while (t % 5 == 0) f[3]++, t /= 5;
      while (t % 7 == 0) f[4]++, t /= 7;
    }
    n /= 10;
  }
  int p[] = {0, 2, 3, 5, 7};
  for (int i = 4; i >= 1; i--) {
    for (int j = 0; j < f[i]; j++) cout << p[i];
    for (int j = i - 1; j >= 1; j--) f[j] -= f[i] * get(p[i], p[j]);
  }
  cout << endl;
  return 0;
}
