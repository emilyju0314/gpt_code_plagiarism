#include <bits/stdc++.h>
using namespace std;
int main() {
  int f, t, n, k, happy = INT_MIN;
  cin >> n >> k;
  while (n--) {
    cin >> f >> t;
    if (k < t) {
      f -= t - k;
    }
    happy = max(happy, f);
  }
  cout << happy << "\n";
  return 0;
}
