#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v;
  for (int i = 0; i < n; i++) {
    long long int a;
    cin >> a;
    v.push_back(a);
  }
  long long int maxi = -1;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      long long int buy = v[i];
      long long int left = k % buy;
      long long int bought = k / buy;
      long long int sold = (v[j] * bought) + left;
      if (sold > maxi) {
        maxi = max(maxi, sold);
      }
    }
  }
  if (maxi < k)
    cout << k;
  else
    cout << maxi;
  return 0;
}
