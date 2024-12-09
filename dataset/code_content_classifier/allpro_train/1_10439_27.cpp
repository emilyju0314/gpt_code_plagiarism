#include <bits/stdc++.h>
using namespace std;
int n, kol = 3;
long long a[100];
int main() {
  cin >> n;
  if (n <= 2) {
    cout << "-1";
    return 0;
  }
  a[0] = 6;
  a[1] = 10;
  a[2] = 15;
  int j = 2;
  for (int i = kol; i < n; ++i) {
    a[i] = a[2] * j;
    ++j;
  }
  for (int i = 0; i < n; ++i) cout << a[i] << endl;
  return 0;
}
