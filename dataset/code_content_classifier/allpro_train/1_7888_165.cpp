#include <bits/stdc++.h>
using namespace std;
int mx = 0;
int he(int i) {
  if (i < 2) return 0;
  if (i < 4) return 1;
  if (i < 8) return 2;
  if (i < 16) return 3;
  return 4;
}
int power(int i) {
  int a = 1;
  while (i--) {
    a *= 2;
  }
  return a;
}
int n;
int last[35], a[35];
int f(int i) {
  if (i >= n) {
    last[i] = a[i];
    mx = max(mx, 1);
    return 1;
  }
  int x = f(2 * i), y = f(2 * i + 1);
  if (x == 1 && y == 1 && last[2 * i] <= last[2 * i + 1]) {
    last[i] = last[2 * i + 1];
    mx = max(mx, power(he(n) - he(i)));
    return 1;
  }
  return 0;
}
int main() {
  cin >> n;
  memset(a, 0, sizeof a);
  for (int i = n; i <= (int)(2 * n - 1); i++) {
    cin >> a[i];
  }
  f(1);
  cout << mx << endl;
  return 0;
}
