#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char a[N], b[N];
int p[N], sz[N];
int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}
void merge(int i, int j) {
  int pa = find(i);
  int pb = find(j);
  if (pa != pb) {
    p[pa] = pb;
    sz[pb] += sz[pa];
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    scanf("%s%s", a + 1, b + 1);
    int len = strlen(a + 1);
    for (int i = 1; i <= 20; ++i) p[i] = i, sz[i] = 1;
    bool flag = true;
    for (int i = 1; i <= len; ++i) {
      if (a[i] != b[i]) {
        if (a[i] > b[i]) {
          flag = false;
          break;
        }
        merge(a[i] - 'a' + 1, b[i] - 'a' + 1);
      }
    }
    if (!flag) {
      puts("-1");
    } else {
      int res = 0;
      for (int i = 1; i <= 20; ++i) find(i);
      for (int i = 1; i <= 20; ++i) {
        int p = find(i);
        if (p == i) {
          res += sz[i] - 1;
        }
      }
      printf("%d\n", res);
    }
  }
  return 0;
}
