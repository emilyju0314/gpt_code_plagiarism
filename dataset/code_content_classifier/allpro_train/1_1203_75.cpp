#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int& a : A) cin >> a;
  sort(A.begin(), A.end());

  if (N % 2 && A[0] != 0) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 1, now = N % 2 + 1;
  for (int i = N % 2; i < N; i += 2) {
    if (A[i] != now || A[i+1] != now) {
      cout << 0 << endl;
      return 0;
    }
    ans *= 2; ans %= 1000000007;
    now += 2;
  }
  cout << ans << endl;
}