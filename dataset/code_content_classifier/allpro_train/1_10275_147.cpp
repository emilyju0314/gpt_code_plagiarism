#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[2 * n];
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a, a + (2 * n));
  if (a[n - 1] == a[n]) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
