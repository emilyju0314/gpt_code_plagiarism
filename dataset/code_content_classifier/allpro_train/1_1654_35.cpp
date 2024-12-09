#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int k, n, A[N], dp[N][N], nxt[N];
int f(int i, int j) {
  if (i == n || j == 0) return 0;
  int &r = dp[i][j];
  if (r != -1) return r;
  r = max(f(i + 1, j), f(nxt[i], j - 1) + nxt[i] - i);
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset((dp), (-1), sizeof(dp));
  cin >> n >> k;
  for (int x = (0), qwerty = (n); x < qwerty; x++) cin >> A[x];
  sort(A, A + n);
  for (int x = (0), qwerty = (n); x < qwerty; x++)
    nxt[x] = upper_bound(A, A + n, A[x] + 5) - A;
  cout << f(0, k) << "\n";
}
