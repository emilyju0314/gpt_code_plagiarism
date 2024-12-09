#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a[10000], first = -1, val, t = 1;
  cin >> n;
  cin >> a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    if (a[i - 1] > a[i] || a[i - 1] == a[i]) t = 0;
  }
  if (t == 1) {
    cout << "YES";
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1] || a[i] == a[i + 1]) {
      first = i;
      val = a[i];
      break;
    }
  }
  if (first == -1) {
    first == n - 1;
    val = a[n - 1];
  }
  for (int i = 0; a[i] != val; i++) {
    if (a[i] == a[i + 1]) {
      cout << "NO";
      return 0;
    }
  }
  for (int i = first; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      first = i;
      break;
    }
    if (a[i + 1] == val) {
      first = i + 1;
    }
  }
  for (int i = first; i < n - 1; i++) {
    if (a[i] < a[i + 1] || a[i] == a[i + 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
