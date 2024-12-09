#include <bits/stdc++.h>
using namespace std;
long long int dfs(long long int n) {
  long long int k = 0;
  while (n > 0) {
    k += n % 10;
    n = n / 10;
  }
  return k;
}
int main() {
  long long int n, q, i, j;
  cin >> n;
  vector<long long int> v;
  for (i = 1; i <= 110; i++) {
    if (i > n) {
      break;
    }
    if (dfs(n - i) == i) {
      v.push_back(n - i);
    }
  }
  long long int u = v.size();
  cout << u << endl;
  for (i = u - 1; i >= 0; i--) {
    cout << v[i] << endl;
  }
  return 0;
}
