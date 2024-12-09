#include <bits/stdc++.h>
int asalmi(int x) {
  int i, k = (int)sqrt(x);
  for (i = 2; i <= k; i++)
    if (x % i == 0) return 0;
  return 1;
}
using namespace std;
long long m, n;
void read() {
  int i, j;
  cin >> n;
  switch (n) {
    case 1:
      cout << 2;
      break;
    case 2:
      cout << 3;
      break;
    case 3:
      cout << 1;
      break;
    case 4:
      cout << 2;
      break;
    case 5:
      cout << 1;
      break;
  }
}
void solve() { int i, j; }
void write() { int i, j; }
int main() {
  read();
  solve();
  write();
  return 0;
}
