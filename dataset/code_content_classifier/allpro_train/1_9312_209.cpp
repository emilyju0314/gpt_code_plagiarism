#include <bits/stdc++.h>
using namespace std;
int n, m;
long long int b;
vector<long long int> a;
int main() {
  scanf("%d%d", &n, &m);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a.begin(), a.end());
  while (m--) {
    scanf("%lld", &b);
    printf("%d ", upper_bound(a.begin(), a.end(), b) - a.begin());
  }
  return 0;
}
