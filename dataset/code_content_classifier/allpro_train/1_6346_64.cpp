#include <bits/stdc++.h>
typedef struct pair {
  long long x;
  int num;
} pair;
int cmp(const void *a, const void *b) {
  pair p = *(pair *)a, q = *(pair *)b;
  if (p.x == q.x && p.num == q.num) {
    return 0;
  } else if (p.x > q.x || (p.x == q.x && p.num > q.num)) {
    return -1;
  } else {
    return 1;
  }
}
int n, k, pos[100000];
pair a[100000];
long long b;
void read_n(void) {
  scanf("%d%d%I64d", &n, &k, &b);
  int i;
  for (i = 0; i < n; ++i) {
    scanf("%I64d", &a[i].x);
    a[i].num = i;
  }
}
void solve(void) {
  if (n == 2) {
    if (b < a[0].x) {
      printf("1");
    } else {
      printf("2");
    }
    return;
  }
  qsort(a, n, sizeof(pair), cmp);
  int i;
  for (i = 0; i < n; ++i) {
    pos[a[i].num] = i;
  }
  long long sum = 0;
  for (i = 0; i < k - 1; ++i) {
    sum += a[i].x;
  }
  int pretend = k - 1;
  if (pos[n - 1] < k - 1) {
    sum -= a[pos[n - 1]].x;
    sum += a[pretend].x;
    ++pretend;
  }
  for (i = 0; i < n - 1; ++i) {
    if (pos[i] < pretend) {
      sum = sum - a[pos[i]].x + a[pretend].x;
      if (b - sum < a[pos[i]].x) {
        printf("%d", i + 1);
        return;
      }
      sum = sum + a[pos[i]].x - a[pretend].x;
    } else {
      if (b - sum < a[pos[i]].x) {
        printf("%d", i + 1);
        return;
      }
    }
  }
  printf("%d", n);
}
int main(void) {
  read_n();
  solve();
  return 0;
}
