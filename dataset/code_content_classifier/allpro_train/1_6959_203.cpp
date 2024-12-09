#include <bits/stdc++.h>
using namespace std;
char a[10001];
int main() {
  int sum = 0, ans = 0;
  cin >> a;
  int na = strlen(a);
  for (int i = 0; i < na; ++i) {
    if (a[i] == a[i + 1]) {
      sum++;
    } else {
      if (sum % 2 != 0) ans++;
      sum = 0;
    }
  }
  cout << ans;
  return 0;
}
