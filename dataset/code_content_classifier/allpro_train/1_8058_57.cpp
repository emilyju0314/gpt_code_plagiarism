#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b[100], ans = 0, i = 0;
  cin >> a;
  for (i = 0; i < a; i++) {
    cin >> b[i];
  }
  sort(b, b + a);
  for (i = 1; i < a; i += 2) {
    ans += b[i] - b[i - 1];
  }
  cout << ans;
}
