#include <bits/stdc++.h>
using namespace std;
auto clk = clock();
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
void test_case() {
  long long int n;
  cin >> n;
  long long int a[n + 1];
  long long int t = -1, b = -1, c = -1;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long int i = 2; i <= n - 1; i++) {
    for (long long int j = i - 1; j >= 1; j--) {
      if (a[j] < a[i]) {
        t = j;
        break;
      }
    }
    for (long long int j = i + 1; j <= n; j++) {
      if (a[j] < a[i]) {
        c = j;
        break;
      }
    }
    if (t != -1 && c != -1) {
      b = i;
      break;
    }
    t = -1, c = -1;
  }
  if (b != -1) {
    cout << "YES" << endl;
    cout << t << " " << b << " " << c << endl;
  } else
    cout << "NO" << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  cout << fixed << setprecision(10);
  long long int t = 1;
  cin >> t;
  while (t--) {
    test_case();
  }
  return 0;
}
