#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0, i = 0;
  cin >> n;
  vector<int> a(n * n);
  for (int i = 0; i < n * n; i++) {
    a[i] = i + 1;
  }
  k = n / 2;
  for (int j = 0; j < n; j++) {
    for (i; i < k; i++) {
      cout << a[i] << " " << a[n * n - i - 1] << " ";
    }
    k = k + n / 2;
    cout << endl;
  }
  return 0;
}
