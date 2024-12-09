#include <bits/stdc++.h>
using namespace std;
const int INF = (-1u) / 2;
const long long int INF2 = (-1ull) / 2;
int a, b, i, j, k, n, m, timer = 0;
int c[1011000], cnt = 0, fl = 0, a2, a3 = -1000000, used[1011000] = {0}, p;
string s, ss;
int main() {
  scanf("%d%d", &n, &p);
  cin >> s;
  for (i = n - 1; i >= 0; i--) {
    if (int(s[i]) - 96 == p) continue;
    ss = s;
    while (1) {
      if (int(ss[i]) - 96 < p)
        ss[i]++;
      else
        break;
      if (i - 2 >= 0 && ss[i] == ss[i - 2] ||
          (i - 1 >= 0 && ss[i] == ss[i - 1]))
        continue;
      cnt = 97;
      fl = 0;
      j = i + 1;
      if (j < n) {
      rt:;
        if (cnt == 100) cnt = 97;
        ss[j] = cnt++;
        if (j - 2 >= 0 && ss[j] == ss[j - 2] ||
            (j - 1 >= 0 && ss[j] == ss[j - 1])) {
          goto rt;
        }
      }
      fl = 0;
      for (j = i + 2; j < n; j++) {
        cnt = 97;
        ss[j] = cnt++;
        if (!(j - 2 >= 0 && ss[j] == ss[j - 2] ||
              (j - 1 >= 0 && ss[j] == ss[j - 1]))) {
          continue;
        }
        ss[j] = cnt++;
        if (!(j - 2 >= 0 && ss[j] == ss[j - 2] ||
              (j - 1 >= 0 && ss[j] == ss[j - 1]))) {
          continue;
        }
        ss[j] = cnt++;
        if (!(j - 2 >= 0 && ss[j] == ss[j - 2] ||
              (j - 1 >= 0 && ss[j] == ss[j - 1]))) {
          continue;
        }
        break;
      }
      if (fl == 0) {
        cout << ss << endl;
        return 0;
      }
    }
  }
  printf("NO\n");
  return 0;
}
