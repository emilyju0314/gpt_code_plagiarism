#include <bits/stdc++.h>
using namespace std;
int n, k, x;
bool memo[10005];
long long byk[10005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    memo[x] = true;
    byk[x]++;
  }
  long long ans = 0;
  for (int i = 0; i <= 10000; i++) {
    for (int j = i; j <= 10000; j++) {
      if (memo[i] && memo[j]) {
        int x = i ^ j;
        int z = __builtin_popcount(x);
        if (z == k) {
          if (i != j)
            ans += (byk[i] * byk[j]);
          else
            ans += (byk[i] * (byk[j] - 1) / 2);
        }
      }
    }
  }
  cout << ans << endl;
}
