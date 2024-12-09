#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, j, max = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (x[i] > max) {
      j = i;
      max = x[i];
    }
  }
  x[j] = 1;
  if (max == 1) x[j] = 2;
  sort(x.begin(), x.end());
  for (int i = 0; i < n; i++) cout << x[i] << " ";
  return 0;
}
