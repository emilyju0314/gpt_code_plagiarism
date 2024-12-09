#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0, n, cnt = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  i = 0;
  while (i < n) {
    if (a[i] == a[i + 1]) {
      i = i + 2;
      cnt++;
    } else {
      i++;
    }
  }
  int m = cnt / 2;
  cout << m;
}
