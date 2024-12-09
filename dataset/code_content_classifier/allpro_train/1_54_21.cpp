#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5;
int num[MaxN + 5];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> num[i];
  int ans, f1 = 0, f2 = 1000005;
  for (int i = 1; i <= n; i++) {
    if (num[i] <= 500000)
      f1 = max(num[i], f1);
    else
      f2 = min(num[i], f2);
  }
  f1--;
  f2 = 1000000 - f2;
  ans = max(f1, f2);
  cout << ans << endl;
  return 0;
}
