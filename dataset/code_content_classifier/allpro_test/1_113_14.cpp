#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    int x, y;
    cin >> a >> x;
    cin >> b >> y;
    if (a.length() + x > b.length() + y)
      puts(">");
    else if (a.length() + x < b.length() + y)
      puts("<");
    else {
      bool jud = true;
      for (int i = 0; i < min(a.length(), b.length()); i++)
        if (a[i] > b[i]) {
          puts(">");
          jud = 0;
          break;
        } else if (a[i] < b[i]) {
          puts("<");
          jud = 0;
          break;
        }
      if (jud) {
        if (a.length() < b.length()) {
          for (int j = a.length(); j < b.length(); j++)
            if (b[j] != '0') {
              jud = 0;
              puts("<");
              break;
            }
        } else {
          for (int j = b.length(); j < a.length(); j++)
            if (a[j] != '0') {
              jud = 0;
              puts(">");
              break;
            }
        }
        if (!jud) continue;
        puts("=");
      }
    }
  }
  return 0;
}
