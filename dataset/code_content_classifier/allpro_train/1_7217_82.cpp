#include <bits/stdc++.h>
using namespace std;
int n, i, a, x = 1, m[5000];
int main() {
  cin >> n;
  while (i < n) {
    cin >> a;
    m[a]++;
    while (m[x] != 0) {
      x++;
    }
    i++;
  }
  cout << x;
  return 0;
}
