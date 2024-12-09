#include <bits/stdc++.h>
using namespace std;
long long cnt[2000005];
int main() {
  int q;
  scanf("%d", &q);
  int t = 1;
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    int c = 0;
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        if (cnt[i] == 0) {
          cnt[i] = t;
          c++;
        } else if (cnt[i] < t - y) {
          c++;
          cnt[i] = t;
        } else {
          cnt[i] = t;
        }
        int tem = x / i;
        if (tem != i) {
          if (cnt[tem] == 0) {
            cnt[tem] = t;
            c++;
          } else if (cnt[tem] < t - y) {
            cnt[tem] = t;
            c++;
          } else {
            cnt[tem] = t;
          }
        }
      }
    }
    t++;
    printf("%ld\n", c);
  }
  return 0;
}
