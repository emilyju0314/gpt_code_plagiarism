#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t n;
  cin >> n;
  vector<int64_t> A(n, 0);
  int64_t s = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    s += A[i];
  }
  int64_t nn = (n * (n - 1)) / 2;
  int64_t p = (s - nn) / n;
  vector<int64_t> B(n, 0);
  for (int64_t i = 0; i < n; i++) {
    B[i] += p + i;
  }
  for (int64_t i = 0; i < s - p * n - nn; i++) {
    B[i] += 1;
  }
  for (int64_t i = 0; i < n; i++) {
    cout << B[i];
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << endl;
}
