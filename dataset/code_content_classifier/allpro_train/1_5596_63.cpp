#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    if (x > b && x < c) {
      ans++;
    }
  }
  cout << ans << '\n';
}
