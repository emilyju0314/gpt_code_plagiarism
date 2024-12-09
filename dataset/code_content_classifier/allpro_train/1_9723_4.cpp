#include <bits/stdc++.h>
using namespace std;
int t, n, k, d1, d0, dem, luu[300030];
string s;
bool kt;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    kt = true;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < k; i++) luu[i] = -1;
    for (int i = 0; i < n; i++)
      if (s[i] == '?')
        continue;
      else if (luu[i % k] == -1)
        luu[i % k] = s[i] - '0';
      else if (luu[i % k] != (s[i] - '0')) {
        cout << "NO"
             << "\n";
        kt = false;
        break;
      }
    dem = d1 = d0 = 0;
    if (!kt) continue;
    for (int i = 0; i < k; i++)
      if (luu[i] == -1)
        dem++;
      else if (luu[i] == 0)
        d0++;
      else
        d1++;
    if ((d0 > k / 2) || (d1 > k / 2)) {
      cout << "NO"
           << "\n";
      continue;
    }
    cout << "YES"
         << "\n";
  }
  return 0;
}
