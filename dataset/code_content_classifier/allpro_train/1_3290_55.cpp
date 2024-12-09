#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int x) { return x && (!(x & (x - 1))); }
bool printPowerOfTwo() {
  for (int j = 0; j < 31; j++) {
    cout << (1 << j) << endl;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
  }
  for (int i = 0; i < n; i++) {
    s += "01";
  }
  cout << s.substr(0, n);
}
