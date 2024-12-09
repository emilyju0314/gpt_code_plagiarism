#include <bits/stdc++.h>
using namespace std;
int best[500][500];
int can[500];
int main() {
  int n;
  cin >> n;
  memset(best, -1, sizeof best);
  for (typeof(n) i = 0; i < (n); ++i) {
    char name[20];
    scanf("%s", name);
    int l = strlen(name);
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      if (best[name[0]][ch] != -1)
        best[name[l - 1]][ch] =
            max(best[name[l - 1]][ch], best[name[0]][ch] + l);
    }
    best[name[l - 1]][name[0]] = max(best[name[l - 1]][name[0]], l);
  }
  int res = 0;
  for (char ch = 'a'; ch <= 'z'; ++ch) res = max(res, best[ch][ch]);
  cout << res;
  return 0;
}
