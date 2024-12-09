#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int k, h;
  k = a[n - 1] - a[1];
  h = a[n - 2] - a[0];
  if (k > h) {
    cout << h;
  } else {
    cout << k;
  }
  return 0;
}
