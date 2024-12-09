#include <bits/stdc++.h>
using namespace std;
pair<int, int> A[200000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      int a;
      cin >> a;
      A[i].first = a;
      A[i].second = i;
    }
    sort(A, A + N);
    int ans = INT_MAX;
    for (int i = 1; i < N; i++) {
      if (A[i].first == A[i - 1].first)
        ans = min(ans, A[i].second - A[i - 1].second + 1);
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
  }
}
