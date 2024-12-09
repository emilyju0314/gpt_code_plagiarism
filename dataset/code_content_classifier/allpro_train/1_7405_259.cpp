#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const double pi = acos(-1.0), eps = 1e-6;
void File() {
  freopen("D:\\in.txt", "r", stdin);
  freopen("D:\\out.txt", "w", stdout);
}
template <class T>
inline void read(T &x) {
  char c = getchar();
  x = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
}
bool f;
int n, q, num1, num2;
int ans[1000010];
int M(int x) {
  if (x >= 0) return x % n;
  int y = -x;
  int p = y / n + 1;
  return (x + n * p) % n;
}
int main() {
  scanf("%d%d", &n, &q);
  f = 1;
  for (int i = 1; i <= q; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x;
      scanf("%d", &x);
      num1 = M(num1 + x), num2 = M(num2 + x);
      if (x % 2 != 0) f = f ^ 1;
    } else {
      if (f == 0)
        num2 = M(num2 + 1), num1 = M(num1 - 1);
      else
        num1 = M(num1 + 1), num2 = M(num2 - 1);
      f = f ^ 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    int pos;
    if (i % 2 == 0)
      pos = (i + num2) % n;
    else
      pos = (i + num1) % n;
    if (pos == 0) pos = n;
    ans[pos] = i;
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
