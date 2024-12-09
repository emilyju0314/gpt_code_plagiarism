#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char c;
  long long m = 0;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if ((c - '1') % 2 == 0)
      ;
    else
      m += (i + 1);
  }
  cout << m << endl;
  return 0;
}
