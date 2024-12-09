#include <bits/stdc++.h>
using namespace std;
const long long MX = 2000;
long long mrk[MX];
void RESET() { cout << "R" << endl; }
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  char res;
  for (long long i = 0; i < n; i++) {
    cout << "? " << i + 1 << endl;
    cin >> res;
    if (res == 'Y') {
      mrk[i] = 1;
    }
  }
  RESET();
  long long m = n / max(1LL, k / 2), l = max(1LL, k / 2);
  for (long long i = 0; i < m - 2; i++) {
    for (long long j = i + 2; j < m; j++) {
      for (long long k = i * l; k < i * l + l; k++) {
        cout << "? " << k + 1 << endl;
        cin >> res;
      }
      for (long long k = j * l; k < j * l + l; k++) {
        cout << "? " << k + 1 << endl;
        cin >> res;
        if (res == 'Y') mrk[k] = 1;
      }
      RESET();
    }
  }
  long long cnt = 0;
  for (long long i = 0; i < n; i++)
    if (!mrk[i]) cnt++;
  cout << "! " << cnt << endl;
  return 0;
}
