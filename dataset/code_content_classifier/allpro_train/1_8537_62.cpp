#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[100001];
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 1; i < n - 1; i++) {
    if (a[i] > a[0] && a[i] < a[n - 1]) {
      s++;
    }
  }
  cout << s;
  return 0;
}
