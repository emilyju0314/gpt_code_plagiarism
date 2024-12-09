#include <bits/stdc++.h>
using namespace std;
long long int a[200000 + 1];
vector<long long int> b;
int main() {
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  for (long long int i = 1; i <= m; i++) {
    long long int l, r;
    cin >> l >> r;
    long long int sum = 0;
    for (long long int i = l; i <= r; i++) {
      sum += a[i];
    }
    b.push_back(sum);
  }
  long long int max_sum = 0;
  for (long long int i = 0; i < b.size(); i++) {
    if (b[i] > 0) {
      max_sum += b[i];
    }
  }
  cout << max_sum << endl;
  return 0;
}
