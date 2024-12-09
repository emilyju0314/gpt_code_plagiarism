#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m;
  cin >> t;
  while (t--) {
    int *a;
    cin >> n;
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (a[0] < a[n - 1]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
