#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int num[2 * N];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> num[i];
  for (int i = k; i < n; i++)
    if (num[i] != num[i - 1]) {
      cout << -1 << endl;
      return 0;
    }
  for (int i = n - 2; i >= 0; i--)
    if (num[i] != num[i + 1]) {
      cout << i + 1 << endl;
      return 0;
    }
  cout << 0 << endl;
  return 0;
}
