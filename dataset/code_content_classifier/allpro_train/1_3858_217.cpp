#include <bits/stdc++.h>
using namespace std;
void init_ios() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
long long n;
signed main() {
  init_ios();
  cin >> n;
  if (n % 2 == 0)
    cout << "2\n";
  else
    cout << "1\n";
}
