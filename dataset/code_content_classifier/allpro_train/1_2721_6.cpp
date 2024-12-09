#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x[100005] = {0}, y[100005] = {0}, xi[n + 5], yi[n + 5];
  for (int i = 1; i <= n; i++) {
    cin >> xi[i] >> yi[i];
    x[xi[i]]++;
    y[yi[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    int total = (n - 1) * 2;
    int home = total / 2, away = total / 2, d;
    d = x[yi[i]];
    home += d;
    away -= d;
    cout << home << " " << away << "\n";
  }
  return 0;
}
