#include <bits/stdc++.h>
using namespace std;
int grundy[] = {1, 2, 1, 4, 3, 2, 1, 5,  6, 2, 1, 8,  7,  5,  9, 8,
                7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14, 15};
int main() {
  int n;
  scanf("%d", &n);
  set<int> s;
  int raiz = sqrt(n);
  int rsp = 0;
  int conta = 0;
  for (int i = (2); i < (raiz + 1); ++i) {
    if (s.count(i)) continue;
    int ct = 0;
    int aux = i;
    while (aux <= n) {
      s.insert(aux);
      ++ct;
      if (n / aux < i) break;
      aux *= i;
    }
    rsp ^= grundy[ct - 1];
  }
  int imp = (n - (int)s.size()) & 1;
  if (imp) rsp ^= 1;
  if (rsp)
    printf("Vasya\n");
  else
    printf("Petya\n");
  return 0;
}
