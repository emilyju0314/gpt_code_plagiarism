#include <bits/stdc++.h>
using namespace std;
bool com(long long a, long long b, long long c) {
  return (c >= min(a, b)) && (c <= max(a, b));
}
int main() {
  ios::sync_with_stdio(0);
  string a;
  cin >> a;
  bool ok = 0;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == 'a' && i != 0 && !ok) {
      if (a[i] == 'a' && a[i + 1] == 't') {
        cout << "@";
        ok = 1;
        i++;
      } else
        cout << a[i];
    } else if (a[i] == 'd' && i < a.length() - 3 && i != 0) {
      if (a[i] == 'd' && a[i + 1] == 'o' && a[i + 2] == 't') {
        cout << ".";
        i += 2;
      } else
        cout << a[i];
    } else
      cout << a[i];
  }
  return 0;
}
