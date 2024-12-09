#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b = 0;
  cin >> n >> a;
  int k[n];
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  for (int j = 0; j < n; j++) {
    if (k[j] >= k[a - 1] && k[j] > 0) {
      b += 1;
    }
  }
  cout << b;
}
