#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int x[N], n;
bool ok;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  if (n == 1) {
    if (x[0] == 0) {
      cout << "UP";
      return 0;
    }
    if (x[0] == 15) {
      cout << "DOWN";
      return 0;
    }
    cout << "-1";
    return 0;
  }
  if (x[n - 1] == 15) {
    cout << "DOWN";
    return 0;
  }
  if (x[n - 1] == 0) {
    cout << "UP";
    return 0;
  }
  for (int i = 1; i < n; i++)
    if (x[i] > x[i - 1])
      ok = true;
    else
      ok = false;
  if (ok == true)
    cout << "UP";
  else
    cout << "DOWN";
  return 0;
}
