#include <bits/stdc++.h>
using namespace std;
vector<int> V;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    V.push_back(a);
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  long long cur = V[0];
  long long ans = V[0];
  for (int i = 1; i < n; ++i) {
    cur--;
    if (cur > V[i]) cur = V[i];
    if (cur > 0) ans = ans + cur;
  }
  cout << ans;
  return 0;
}
