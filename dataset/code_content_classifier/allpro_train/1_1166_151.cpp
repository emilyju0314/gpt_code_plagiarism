#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main() {
  cin >> a >> b;
  long long ans = 0;
  while (b) {
    ans += a / b;
    a %= b;
    swap(a, b);
  }
  cout << ans << endl;
}
