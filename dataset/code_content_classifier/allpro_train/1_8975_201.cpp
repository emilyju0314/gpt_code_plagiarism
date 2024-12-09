#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c = 0, d = 0;
  int n;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (a < 0)
      c++;
    else
      d++;
  }
  if (c == 1 || d == 1 || c == 0 || d == 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
