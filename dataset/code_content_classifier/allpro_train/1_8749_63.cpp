#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int d = 1;
  for (int i = 2; i < k; i++) {
    if (n % i == 0) d = i;
  }
  cout << n / d * k + d;
  return 0;
}
