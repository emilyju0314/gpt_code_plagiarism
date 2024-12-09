#include <bits/stdc++.h>
using namespace std;
int t[50000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    t[i + n] = t[i];
  }
  vector<int> div;
  for (int i = 3; i <= n; i++)
    if (n % i == 0) div.push_back(i);
  sort((div).begin(), (div).end());
  reverse((div).begin(), (div).end());
  long long ans = -(1LL << 60);
  for (int i = 0; i < ((int)(div).size()); i++) {
    int k = n / div[i];
    for (int steps = 1; steps <= k; steps++) {
      long long tmp = 0;
      for (int j = steps; j < steps + n; j += k) tmp += t[j];
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
