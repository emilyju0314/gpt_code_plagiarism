#include <bits/stdc++.h>
using namespace std;
int lefti[1000 + 10];
bool used[1000 + 10];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> lefti[i];
  for (int t = 0; t < n; ++t) {
    for (int i = 1; i <= n; ++i) {
      if (used[i] == false && lefti[i] == 0) {
        cout << i << " ";
        used[i] = true;
        for (int j = i - k; j >= 1; --j) {
          lefti[j]--;
          lefti[j] = max(lefti[j], 0);
        }
        break;
      }
    }
  }
  cout << endl;
  return 0;
}