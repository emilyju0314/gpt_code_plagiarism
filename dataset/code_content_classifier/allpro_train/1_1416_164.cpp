#include <bits/stdc++.h>
using namespace std;
char s[1010][20];
int val[1010];
map<string, int> mp;
struct node {
  char s[20];
};
bool cmp(const node &a, const node &b) { return strcmp(a.s, b.s) < 0; }
node a[1010];
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    mp.clear();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s%d", s[i], &val[i]);
      if (mp.find(s[i]) == mp.end()) {
        mp[s[i]] = val[i];
        strcpy(a[cnt++].s, s[i]);
      } else
        mp[s[i]] = max(mp[s[i]], val[i]);
    }
    sort(a, a + cnt, cmp);
    n = cnt;
    printf("%d\n", n);
    for (int i = 0; i < cnt; i++) {
      int better = 0;
      for (int j = 0; j < cnt; j++) {
        if (mp[a[j].s] > mp[a[i].s]) better++;
      }
      printf("%s ", a[i].s);
      if (better * 2 > n)
        puts("noob");
      else if (better * 5 > n)
        puts("random");
      else if (better * 10 > n)
        puts("average");
      else if (better * 100 > n)
        puts("hardcore");
      else
        puts("pro");
    }
  }
  return 0;
}
