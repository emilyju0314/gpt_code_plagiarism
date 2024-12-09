#include <bits/stdc++.h>
int A[6];
int B[6];
using namespace std;
int main() {
  int n, k;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    A[k]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> k;
    B[k]++;
  }
  int t = 0;
  for (int i = 1; i <= 5; i++) {
    if ((A[i] + B[i]) % 2 != 0) {
      cout << -1;
      return 0;
    }
    t = t + (max(A[i], B[i]) - min(A[i], B[i])) / 2;
  }
  cout << t / 2;
  return 0;
}
