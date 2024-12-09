#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans;
  cin >> n;
  cout << "2" << endl;
  for (long long i = 3; i <= n + 1; ++i) {
    ans = i * i * (i - 1LL) - (i - 2LL);
    cout << ans << endl;
  }
  return 0;
}
