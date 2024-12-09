#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int a[N], b[N], h[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i], h[i] = a[i] + b[i];
  for (int i = 1; i < n; i++) h[i] = min(h[i], h[i - 1] + 1);
  for (int j = n - 2; j >= 0; j--) h[j] = min(h[j], h[j + 1] + 1);
  for (int i = 0; i < n; i++) {
    if (h[i] < a[i]) {
      cout << "-1\n";
      return 0;
    }
    sum += h[i] - a[i];
  }
  cout << sum << "\n";
  for (int i = 0; i < n; i++) cout << h[i] << " ";
}
