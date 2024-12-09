#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  string x;
  cin >> x;
  long long n = x.size();
  long long A[n + 5];
  A[0] = 0;
  for (long long i = 0; i < n; i++) A[i + 1] = A[i] + (x[i] == 'a');
  long long B[n + 5];
  B[0] = 0;
  for (long long i = 0; i < n; i++) B[i + 1] = B[i] + (x[i] == 'b');
  B[n + 1] = B[n];
  A[n + 1] = A[n];
  long long ans = 0;
  for (long long i = 1; i <= n + 1; i++) {
    for (long long j = i - 1; j <= n + 1; j++) {
      long long a1 = A[i - 1];
      long long a2 = A[n] - A[j];
      long long b = B[j] - B[i - 1];
      ans = max(ans, a1 + a2 + b);
    }
  }
  cout << ans;
}
