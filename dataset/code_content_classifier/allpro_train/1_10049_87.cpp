#include <bits/stdc++.h>
using namespace std;
const long long LLINF = 8e18;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const int N = 1e5;
int n, ans;
int a[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int i = 0, j = 1;
  while (j < n) {
    if (a[i] < a[j]) {
      ans++;
      i++;
      j++;
    } else {
      j++;
    }
  }
  cout << ans;
  return 0;
}
