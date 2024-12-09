#include <bits/stdc++.h>
using namespace std;
int nums[10000005];
int su[1000005];
int an[1000005];
int main() {
  int cnt = 0;
  for (int i = 0; i < 1000005; i++) {
    nums[i] = 1;
  }
  nums[1] = nums[0] = 0;
  for (int i = 2; i < 1000005; i++) {
    if (nums[i] == 0) {
      continue;
    }
    su[cnt] = i;
    cnt++;
    for (int j = i + i; j < 1000005; j += i) {
      nums[j] = 0;
    }
  }
  int t1, cnt2;
  t1 = 0;
  cnt2 = 0;
  long long t2, t3;
  t2 = su[cnt2] * su[cnt2];
  t3 = su[t1];
  int nowan = 0;
  for (int i = 2; i < 1000005 && t1 < cnt;) {
    if (t2 == t3) {
      for (int j = i + 1; j < t2; j++) {
        an[j] = nowan;
      }
      an[t2] = nowan;
      i = t2;
      t1++;
      cnt2++;
      t2 = su[cnt2] * su[cnt2];
      t3 = su[t1];
    } else if (t2 < t3) {
      for (int j = i + 1; j < t2; j++) {
        an[j] = nowan;
      }
      nowan--;
      i = t2;
      an[i] = nowan;
      cnt2++;
      t2 = su[cnt2] * su[cnt2];
    } else {
      for (int j = i + 1; j < t3; j++) {
        an[j] = nowan;
      }
      nowan++;
      i = t3;
      an[i] = nowan;
      t1++;
      t3 = su[t1];
    }
  }
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", an[n] + 1);
  }
  return 0;
}
