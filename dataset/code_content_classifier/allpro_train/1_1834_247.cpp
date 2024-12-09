#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    map<int, int> count;
    for (int i = 0, j; i < n; i++) {
      scanf("%d", &j);
      count[j]++;
    }
    long long ans = 0;
    for (int i = 1; i <= 10; i++) {
      ans += ((long long)count[-i] * count[i]);
    }
    long long val = count[0];
    if (val) ans += ((val) * (val - 1)) / 2;
    cout << ans << endl;
  }
  return 0;
}
