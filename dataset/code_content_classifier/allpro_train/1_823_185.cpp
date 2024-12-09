#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, bx, m, by;
  long long x = 0, y = 0;
  cin >> n >> bx;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    x *= bx;
    x += k;
  }
  cin >> m >> by;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    y *= by;
    y += k;
  }
  if (x < y)
    cout << "<";
  else if (x > y)
    cout << ">";
  else
    cout << "=";
}
