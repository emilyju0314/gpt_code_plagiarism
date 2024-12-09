#include <bits/stdc++.h>
const int N = 1e5 + 20, MOD = (int)(1e9) + 7;
const int oo = 0x3f3f3f3f;
using namespace std;
void boost() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
unsigned long long GCD(unsigned long long a, unsigned long long b) {
  if (a == 0) return b;
  return GCD(b % a, a);
}
int main() {
  boost();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[4 * n];
    map<int, int> m;
    n = 4 * n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    bool flag = false;
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second % 2 != 0) flag = true;
    }
    if (flag == true) {
      cout << "NO\n";
      continue;
    }
    sort(a, a + n);
    unsigned long long area = a[0] * a[n - 1];
    int i = 0, j = n - 1;
    while (i < j) {
      unsigned long long temp = a[i] * a[j];
      i += 2;
      j -= 2;
      if (temp != area) {
        flag = true;
        break;
      }
    }
    cout << (flag == true ? "NO" : "YES");
    cout << "\n";
  }
}
