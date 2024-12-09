#include <bits/stdc++.h>
using namespace std;
int k, cnt[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int a[21];
int main() {
  scanf("%d", &k);
  if (k > 36)
    cout << -1 << endl;
  else {
    while (k >= 2) cout << 8, k -= 2;
    while (k) cout << 9, k--;
    cout << endl;
  }
  return 0;
}
