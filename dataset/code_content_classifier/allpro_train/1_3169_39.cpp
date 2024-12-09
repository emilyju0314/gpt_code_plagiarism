#include <bits/stdc++.h>
using namespace std;
class f {
 public:
  int a = 0, t = 0, g = 0, c = 0;
};
const int N = 1e5 + 5;
vector<vector<f> > BIT(55, vector<f>(N, *(new f())));
char str[N], e[15];
int n;
void add(f &x, f &y, f &z) {
  z.a = x.a + y.a;
  z.c = x.c + y.c;
  z.g = x.g + y.g;
  z.t = x.t + y.t;
}
void sub(f &x, f &y, f &z) {
  z.a = x.a - y.a;
  z.c = x.c - y.c;
  z.g = x.g - y.g;
  z.t = x.t - y.t;
}
void update(int p, int in, f diff) {
  if (in > n) return;
  add(BIT[p][in], diff, BIT[p][in]);
  int parent = in + (in & (-in));
  update(p, parent, diff);
}
f getSum(int p, int in) {
  if (in == 0) return *(new f());
  int parent = in - (in & (-in));
  f ans = getSum(p, parent);
  add(BIT[p][in], ans, ans);
  return ans;
}
void change(int x, char pr, char ch) {
  if (pr == ch) return;
  str[x - 1] = ch;
  f diff;
  switch (pr) {
    case 'A':
      diff.a = -1;
      break;
    case 'T':
      diff.t = -1;
      break;
    case 'G':
      diff.g = -1;
      break;
    case 'C':
      diff.c = -1;
      break;
  };
  switch (ch) {
    case 'A':
      diff.a = 1;
      break;
    case 'T':
      diff.t = 1;
      break;
    case 'G':
      diff.g = 1;
      break;
    case 'C':
      diff.c = 1;
      break;
  };
  int p;
  for (int i = 1; i <= 10; i++) {
    p = (i * (i - 1)) / 2;
    p += x % i;
    update(p, x, diff);
  }
}
int infec(int l, int r) {
  int ans = 0;
  f cnt, L, R;
  int t = strlen(e);
  int p = (t * (t - 1)) / 2;
  int m;
  for (int i = 0; i < t; i++) {
    m = (l + i) % t;
    R = getSum(p + m, r);
    L = getSum(p + m, l - 1);
    sub(R, L, cnt);
    switch (e[i]) {
      case 'A':
        ans += cnt.a;
        break;
      case 'T':
        ans += cnt.t;
        break;
      case 'G':
        ans += cnt.g;
        break;
      case 'C':
        ans += cnt.c;
        break;
    };
  }
  return ans;
}
int main() {
  scanf(" %s", str);
  n = strlen(str);
  for (int i = 1; i <= n; i++) {
    change(i, '\0', str[i - 1]);
  }
  int q;
  scanf("%d", &q);
  int a, x, l, r;
  char ch;
  while (q--) {
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d %c", &x, &ch);
      change(x, str[x - 1], ch);
    } else {
      scanf("%d %d %s", &l, &r, e);
      printf("%d\n", infec(l, r));
    }
  }
  return 0;
}
