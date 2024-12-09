#include <bits/stdc++.h>
using namespace std;
int main() {
  int nTests = 0;
  cin >> nTests;
  for (int test = 0; test < nTests; ++test) {
    int n = 0;
    cin >> n;
    int a0 = 0;
    cin >> a0;
    int maxi = a0;
    int maxDiff = 0;
    for (int i = 1; i < n; ++i) {
      int ai = 0;
      cin >> ai;
      if (ai > maxi) {
        maxi = ai;
      }
      if (ai < maxi) {
        maxDiff = max(maxDiff, maxi - ai);
      }
    }
    cout << static_cast<int>(ceil(log2(maxDiff + 1))) << "\n";
  }
  return 0;
}
