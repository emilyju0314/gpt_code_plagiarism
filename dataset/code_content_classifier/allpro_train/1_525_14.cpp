#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long i, j, t, n, k;
  int a[4];
  for (i = 0; i < 4; i++) cin >> a[i];
  sort(a, a + 4);
  if ((a[0] + a[1] + a[2]) == a[3])
    cout << "YES";
  else if ((a[0] + a[1]) == (a[2] + a[3]))
    cout << "YES";
  else if ((a[0] + a[3]) == (a[2] + a[1]))
    cout << "YES";
  else if ((a[0] + a[2]) == (a[1] + a[3]))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
