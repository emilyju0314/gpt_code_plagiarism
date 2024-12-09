#include <bits/stdc++.h>
using namespace std;
int a[100005];
map<long long, int> M;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    M[sum]++;
  }
  int k = 0;
  for (auto it : M) {
    k = max(k, it.second);
  }
  cout << n - k;
  return 0;
}
