#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (b - a >= 2) count += 1;
  }
  cout << count;
  return 0;
}
