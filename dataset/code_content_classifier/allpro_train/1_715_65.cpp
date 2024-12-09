#include <bits/stdc++.h>
const int maxn = 100100;
using namespace std;
char a[maxn];
struct data {
  char p, q;
} p[15];
int main() {
  scanf("%s", a + 1);
  int l = strlen(a + 1);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char ch[5];
    scanf("%s", ch);
    p[i].p = ch[0];
    p[i].q = ch[1];
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int na = 0, nb = 0;
    for (int j = 1; j <= l; j++) {
      if (a[j] == p[i].p)
        na++;
      else if (a[j] == p[i].q)
        nb++;
      else {
        sum += min(na, nb);
        na = 0;
        nb = 0;
      }
    }
    sum += min(na, nb);
  }
  cout << sum << endl;
}
