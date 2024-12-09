#include <bits/stdc++.h>
using namespace std;
const int MAXINT = 0x6fffffff;
const long long MAXLONG = (long long)1 << 60;
const int MAXN = 105;
set<int> sa, sb;
int arr[MAXN];
int n, a, b;
int main() {
  while (scanf("%d %d %d", &n, &a, &b) != -1) {
    sa.clear();
    sb.clear();
    for (long long i = (0); i < (a); i += 1) {
      int x;
      scanf("%d", &x);
      sa.insert(x);
    }
    for (long long i = (0); i < (b); i += 1) {
      int x;
      scanf("%d", &x);
      sb.insert(x);
    }
    for (long long i = (0); i < (n); i += 1) {
      if (sa.find(i + 1) != sa.end()) {
        printf("1");
      } else {
        printf("2");
      }
      putchar(i + 1 == n ? '\n' : ' ');
    }
  }
  return 0;
}
