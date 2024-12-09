#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sq = sqrt(n);
  for (int i = sq; i >= 1; i--) {
    int ans = n / i;
    if (ans * i == n) {
      cout << i << " " << ans;
      return 0;
    }
  }
}
