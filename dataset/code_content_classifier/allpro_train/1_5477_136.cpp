#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sum1 = s[0] - 48;
  int sum2 = s[n / 2] - 48;
  bool test1 = true;
  bool test2 = false;
  for (int i = 0; i < n; i++) {
    if (i != 0 && i < n / 2) sum1 = sum1 + s[i] - 48;
    if (i != n / 2 && i > n / 2) sum2 = sum2 + s[i] - 48;
    if (s[i] != '4' && s[i] != '7') {
      test1 = false;
      break;
    }
  }
  if (sum1 == sum2) test2 = true;
  if (test1 && test2)
    cout << "YES";
  else
    cout << "NO";
}
