#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int z;
  scanf("%d", &z);
  vector<int> a(z);
  int n = 0;
  for (int i = 0; i < z; i++) {
    scanf("%d", &a[i]);
    n += a[i];
  }
  for (int g = 1; g <= n; g++) {
    if (n % g) {
      continue;
    }
    bool can = true;
    for (int i = 0; i < z; i++) {
      if (a[i] % (n / g)) {
        can = false;
        break;
      }
    }
    if (!can) {
      continue;
    }
    int odd = -1;
    int need = 0;
    for (int i = 0; i < z; i++) {
      int x = a[i] / (n / g);
      need += x;
      if (x % 2) {
        if (odd == -1) {
          odd = i;
        } else {
          can = false;
          break;
        }
      }
    }
    if (need > g) {
      can = false;
    }
    if (!can) {
      continue;
    }
    string str = "";
    for (int i = 0; i < z; i++) {
      for (int j = 0; j < a[i] / (n / g) / 2; j++) {
        str.push_back(i + 'a');
      }
    }
    string rev = str;
    reverse(rev.begin(), rev.end());
    if (odd > -1) {
      str.push_back(odd + 'a');
    }
    str += rev;
    if ((int)str.size() > g) {
      continue;
    }
    int ans = n / g * (odd == -1 ? 2 : 1);
    printf("%d\n", ans);
    for (int t = 0; t * g < n; t++) {
      printf("%s", str.c_str());
    }
    puts("");
    exit(0);
  }
  puts("0");
  for (int i = 0; i < z; i++) {
    for (int j = 0; j < a[i]; j++) {
      putchar(i + 'a');
    }
  }
  puts("");
  return 0;
}
