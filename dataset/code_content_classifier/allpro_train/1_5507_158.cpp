#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool t[100001] = {0};
  int k = 0, maxk = 0, a;
  for (int j = 0; j < 2 * n; j++) {
    cin >> a;
    if (t[a]) {
      t[a] = false;
      k--;
    } else {
      t[a] = true;
      k++;
      maxk = max(maxk, k);
    }
  }
  cout << maxk;
}
