#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a;
  cin >> n;
  int t[n][2];
  int s[n];
  for (int i = 0; i < n; i++) {
    cin >> t[i][0];
    cin >> t[i][1];
  }
  for (int i = 0; i < n; i++) {
    a = abs(t[i][1] - t[i][0]);
    if ((a % 5) == 0)
      s[i] = a / 5;
    else if (((a % 5) == 1) || ((a % 5) == 2))
      s[i] = (a / 5) + 1;
    else if (((a % 5) == 3) || ((a % 5) == 4))
      s[i] = (a / 5) + 2;
  }
  for (int i = 0; i < n; i++) cout << s[i] << endl;
  return 0;
}
