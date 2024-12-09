#include <bits/stdc++.h>
using namespace std;
int A[5005], a[5005];
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n + 1; i++) {
    int val;
    if (i <= n) {
      cout << "? " << 1 << " " << i << endl;
      cin >> val;
      a[i] = val;
    } else {
      cout << "? " << 2 << " " << 3 << endl;
      cin >> val;
      A[1] = (a[2] + a[3] - val) / 2;
    }
  }
  cout << "! " << A[1] << " ";
  for (int i = 2; i <= n; i++) cout << a[i] - A[1] << " ";
  return 0;
}
