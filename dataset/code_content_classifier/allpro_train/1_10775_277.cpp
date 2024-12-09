#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int com(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int main(void) {
  int n, k, i;
  cin >> n >> k;
  if (n / 2 > k)
    cout << -1;
  else if (n == 1 && k != 0)
    cout << -1;
  else {
    i = n / 2 - 1;
    int l = k - i;
    if (n > 1) {
      cout << l << " " << l * 2 << " ";
      for (l = l * 2 + 1; i > 0; i--, l += 2) printf("%d %d ", l, l + 1);
    }
    if (n % 2) printf("%d", l);
  }
}
