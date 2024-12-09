#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, a[100000], x, d;
  cin >> n >> x;
  for (i = 0; i < n; i++) cin >> a[i];
  d = 0;
  sort(a, a + n);
  while (a[(n - 1) / 2] != x) {
    a[n++] = x;
    sort(a, a + n);
    d++;
  }
  cout << d;
}
