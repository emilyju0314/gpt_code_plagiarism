#include <bits/stdc++.h>
using namespace std;
int A[200010];
int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    ans += 1;
    int lr = i;
    while (lr < N && A[lr] == -1) lr += 1;
    if (lr == N) break;
    int next = lr + 1;
    while (next < N && A[next] == -1) next += 1;
    if (next == N) break;
    int dist = next - lr;
    if (abs(A[next] - A[lr]) % dist) {
      i = next - 1;
      continue;
    }
    int diff = (A[next] - A[lr]) / dist;
    int r = next + 1;
    if (A[lr] - (lr - i) * 1LL * diff <= 0) {
      i = next - 1;
      continue;
    }
    while (r < N) {
      long long expectedvalue = A[next] + diff * 1LL * (r - next);
      if (expectedvalue <= 0) break;
      if (!(A[r] == -1 || A[r] == expectedvalue)) {
        break;
      }
      r += 1;
    }
    i = r - 1;
  }
  cout << ans << endl;
}
