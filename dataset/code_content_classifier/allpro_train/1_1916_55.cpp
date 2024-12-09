#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const long long INF = 1e18;
const long double PI = 4 * atan((long double)1);
const int INFTY = 1e7;
long long N, x, T;
bool vis[200000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < (N); i++) cin >> A[i];
  sort(A.begin(), A.end());
  int ans = 0;
  for (int i = 0; i < (int)A.size(); i++) {
    if (A[i] > 1 && !vis[A[i] - 1]) {
      ans++;
      vis[A[i] - 1] = true;
    } else if (!vis[A[i]]) {
      ans++;
      vis[A[i]] = true;
    } else if (!vis[A[i] + 1]) {
      ans++;
      vis[A[i] + 1] = true;
    }
  }
  cout << ans << endl;
}
