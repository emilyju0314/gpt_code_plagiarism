#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int i, j;
  float x, avg = 0;
  for (i = 0; i < n; i += 1) {
    cin >> a[i];
    avg += a[i];
  }
  int sum = avg;
  avg = avg / (n * 1.0);
  if (avg >= 4.5)
    cout << 0;
  else {
    sort(a, a + n);
    int c = 0;
    for (i = 0; i < n; i++) {
      c++;
      sum += 5 - a[i];
      avg = sum / (n * 1.0);
      if (avg >= 4.5) {
        cout << c;
        return 0;
      }
    }
  }
  return 0;
}
