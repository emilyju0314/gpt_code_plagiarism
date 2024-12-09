#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int itr = 0; itr < t; itr++) {
    int a, b, n, s;
    cin >> a >> b >> n >> s;
    int x = s / n, y = s % n;
    if (x > a) {
      y += (x - a) * n;
    }
    if (y > b) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
