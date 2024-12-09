#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  long long ans;
  cin >> n;
  if (n != 0) {
    if (n % 2 == 1)
      ans = (n + 1) / 2;
    else
      ans = n + 1;
    cout << ans;
    return 0;
  } else
    cout << "0";
}
