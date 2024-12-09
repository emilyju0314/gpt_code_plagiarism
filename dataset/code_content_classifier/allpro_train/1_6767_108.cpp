#include <bits/stdc++.h>
using namespace std;
bool bo[200005];
int tot[200005];
long long hashh[2][200005], base[200005];
int read() {
  int A;
  bool K;
  char C;
  C = A = K = 0;
  while (C < '0' || C > '9') K |= C == '-', C = getchar();
  while (C > '/' && C < ':') A = (A << 3) + (A << 1) + (C ^ 48), C = getchar();
  return (K ? -A : A);
}
int main() {
  int n, q, i, l1, l2, len;
  n = read();
  for (i = 1; i <= (n); i++) {
    bo[i] = getchar() == '1';
    if (!bo[i])
      hashh[0][i] = (hashh[0][i - 1] * 33331 + (i & 1)) % 33333331,
      hashh[1][i] = (hashh[1][i - 1] * 33331 + (!(i & 1))) % 33333331;
    else
      hashh[1][i] = hashh[1][i - 1], hashh[0][i] = hashh[0][i - 1];
    tot[i] = tot[i - 1] + (!bo[i]);
  }
  q = read();
  base[0] = 1;
  for (i = 1; i <= (n); i++) base[i] = base[i - 1] * 33331 % 33333331;
  while (q--) {
    l1 = read(), l2 = read(), len = read();
    puts((tot[l1 + len - 1] - tot[l1 - 1] == tot[l2 + len - 1] - tot[l2 - 1] &&
                  (hashh[l1 & 1][l1 + len - 1] -
                   hashh[l1 & 1][l1 - 1] *
                       base[tot[l1 + len - 1] - tot[l1 - 1]] % 33333331 +
                   33333331) %
                          33333331 ==
                      (hashh[l2 & 1][l2 + len - 1] -
                       hashh[l2 & 1][l2 - 1] *
                           base[tot[l2 + len - 1] - tot[l2 - 1]] % 33333331 +
                       33333331) %
                          33333331
              ? "Yes"
              : "No"));
  }
  return 0;
}
