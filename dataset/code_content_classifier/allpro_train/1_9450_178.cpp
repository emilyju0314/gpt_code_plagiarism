#include <bits/stdc++.h>
using namespace std;
const long long int INF = 2e18 + 99;
bool file = 0, rt = 1;
clock_t tStart;
void FAST_IO();
int main() {
  FAST_IO();
  long long int i, j, n, m, p, sum = 0, k, t, a, b, c, d, cnt = 0, ans = 0, q;
  cin >> n;
  for (i = 2; i < n; i++) {
    ans += (i * (i + 1));
  }
  cout << ans << '\n';
  if (rt && file) {
    printf("\nTime taken: %.6fs", (double)(clock() - tStart) / CLOCKS_PER_SEC);
  }
  return 0;
}
void FAST_IO() {
  ios_base::sync_with_stdio(0);
  if (rt && file) {
    tStart = clock();
  }
  if (file) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
}
