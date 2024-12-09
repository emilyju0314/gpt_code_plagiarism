#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, k;
  ifstream ifile("input.txt");
  if (ifile) {
    freopen("input.txt", "rt", stdin);
  }
  if (ifile) {
    freopen("output.txt", "wt", stdout);
  }
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    if (k % 2 == 1)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
