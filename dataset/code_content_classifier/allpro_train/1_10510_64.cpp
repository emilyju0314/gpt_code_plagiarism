#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int mod = 1e9 + 7;
const int N = 2000010;
int a[N];
int *h, extra;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) a[i] = i;
  h = a + 1;
  extra = 0;
  for (int k = 2; k <= n; k++, h++) {
    for (int i = n / k * k; i >= 0; i -= k) {
      h[(i + k > n) ? n : (i + k)] = h[i];
    }
  }
  for (int i = 1; i <= n; i++) cout << h[i - 1] << " ";
  cout << endl;
  return 0;
}
