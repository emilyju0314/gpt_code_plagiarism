#include <bits/stdc++.h>
using namespace std;
long long int l1, l2, r1, r2, k, c = 0;
int main() {
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  if (r1 - l2 >= 0 && r2 - l1 >= 0) {
    c = r1 - l2 + 1;
    if (l1 - l2 > 0) c = c - (l1 - l2);
    if (r1 > r2) c = c - (r1 - r2);
    if (k >= l2 && k >= l1 && k <= r1 && k <= r2) c--;
  }
  cout << c;
  return 0;
}
