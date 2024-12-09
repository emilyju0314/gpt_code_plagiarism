#include <bits/stdc++.h>
using namespace std;
long long num[5005] = {0};
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  for (int i = 1; i <= n; i++) {
    num[i] += num[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + ans; j <= n; j++) {
      if (num[j] - num[i - 1] > (j - i + 1) * 100) {
        ans = j - i + 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
