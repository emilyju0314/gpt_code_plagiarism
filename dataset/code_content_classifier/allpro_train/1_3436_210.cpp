#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n], count = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j]) a[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) count++;
  }
  cout << count << endl;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) cout << a[i] << " ";
  }
  cout << endl;
}
