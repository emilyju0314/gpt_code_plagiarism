#include <bits/stdc++.h>
using namespace std;
int main() {
  int Case = 1;
  int n, m, k;
  char dump[2];
  while (scanf("%d", &n) == 1) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      v.push_back(k);
    }
    sort(v.begin(), v.end());
    long long int sum = 0;
    for (int i = 0; i < v.size() - 1; i++) {
      sum += v[i];
    }
    long long int ans = (v[v.size() - 1] - sum) + 1;
    printf("%I64d\n", ans);
  }
  return 0;
}
