#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ans = n + 1;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      n /= i;
      ans += n;
      i = 1;
    }
  }
  cout << ans << endl;
}
