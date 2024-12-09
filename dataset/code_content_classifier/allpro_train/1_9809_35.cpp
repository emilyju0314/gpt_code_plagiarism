#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long k;
  cin >> k;
  string s = "codeforces";
  long long now = 1;
  for (int i = 0; i < 10; ++i) {
    long long now1;
    int x = 0;
    do {
      now1 = now;
      x++;
      for (int j = i; j < 10; ++j) {
        now1 = 1ll * now1 * x;
      }
    } while (now1 < k);
    for (int j = 0; j < x; ++j) {
      cout << s[i];
    }
    now *= 1ll * x;
  }
  cout << '\n';
  return 0;
}
