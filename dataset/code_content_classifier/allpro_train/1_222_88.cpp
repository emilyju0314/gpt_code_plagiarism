#include <bits/stdc++.h>
using namespace std;
int q;
char s[100005] = {0};
bitset<100005> m[27], ans;
int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      m[s[i] - 'a'][i + 1] = 1;
    }
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int pos;
      char ne;
      scanf("%d %c", &pos, &ne);
      m[s[pos - 1] - 'a'][pos] = 0;
      m[ne - 'a'][pos] = 1;
      s[pos - 1] = ne;
    } else if (op == 2) {
      int tl, tr;
      char s2[100005] = {0};
      scanf("%d %d %s", &tl, &tr, s2);
      ans.set();
      int lens2 = strlen(s2);
      for (int j = 0; j < lens2; j++) {
        ans &= (m[s2[j] - 'a'] >> j);
      }
      int leftN = (ans >> (tl)).count();
      int rigthN = (ans >> (tr - lens2 + 2)).count();
      if (leftN - rigthN < 0) leftN = rigthN;
      printf("%d\n", leftN - rigthN);
    }
  }
  return 0;
}
