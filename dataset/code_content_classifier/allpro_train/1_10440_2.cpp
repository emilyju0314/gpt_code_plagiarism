#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << (a[0] == 1 ? "YES" : "NO");
    return 0;
  } else {
    cout << (count(a, a + n, 0) == 1 ? "YES" : "NO");
    return 0;
  }
  return 0;
}
