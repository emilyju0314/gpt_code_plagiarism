#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, t, s = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    if (k % i == 0 && k / i <= n) s++;
  }
  cout << s;
}
