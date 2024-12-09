#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int main() {
  map<int, int>::iterator ptr;
  int n, i, x, a[3];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    m[x]++;
  }
  if (m.size() > 3) {
    cout << "NO";
    return 0;
  }
  if (m.size() <= 2) {
    cout << "YES";
    return 0;
  }
  i = 0;
  for (ptr = m.begin(); ptr != m.end(); ptr++) a[i++] = ptr->first;
  if ((a[0] + a[2]) == (2 * a[1]))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
