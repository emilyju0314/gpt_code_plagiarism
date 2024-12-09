#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n >> v;
  int k = 1, sum = 0;
  if (v >= n) {
    cout << n - 1 << endl;
    return 0;
  }
  for (int i = 1; i <= (n - v); i++) {
    k -= 1;
    if (k < v) {
      sum += (v - k) * i;
      k = v;
    }
  }
  cout << sum << endl;
  return 0;
}
