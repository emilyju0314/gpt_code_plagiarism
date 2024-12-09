#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  if (a > b) {
    cout << n;
  } else {
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (A[i] <= a) count++;
    }
    cout << ceil(count / 2.0);
  }
  return 0;
}
