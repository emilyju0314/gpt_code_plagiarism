#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  long long alpha = y - n + 1;
  if (alpha <= 0) {
    cout << -1 << endl;
    return 0;
  }
  if (!(alpha * alpha + n - 1 >= x)) {
    cout << -1 << endl;
    return 0;
  }
  cout << alpha << endl;
  for (int i = 1; i < n; i++) puts("1");
  return 0;
}
