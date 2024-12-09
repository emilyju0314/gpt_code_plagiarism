#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0 || n == 1) {
    cout << 0;
    return 0;
  }
  vector<int> a(n + 1);
  vector<int> answ(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int max, res;
  for (int j = 0; j < n; j++) {
    max = j + 1;
    res = 0;
    for (int i = 1; i <= n; i++) {
      res +=
          2 * (a[i] * abs(i - max) + a[i] * abs(i - 1) + a[i] * abs(max - 1));
    }
    answ[j] = res;
  }
  cout << *(min_element(answ.begin(), answ.end()));
  return 0;
}
