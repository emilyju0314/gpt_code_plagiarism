#include <bits/stdc++.h>
using namespace std;
long long n, s;
long long h[100020];
int f[100020];
bool check(int bandwidth) {
  h[1] = 1;
  long long sum = 1, cur_sz = n;
  for (int i = 2;; i++) {
    if (h[i - 1] * bandwidth + sum >= n) {
      h[i] = n - sum;
      cur_sz += h[i];
      break;
    }
    h[i] = h[i - 1] * bandwidth;
    cur_sz += n - sum;
    sum += h[i];
  }
  return cur_sz <= s;
}
void output(int bandwidth) {
  for (int i = 1; i <= n; i++) h[i] = 1;
  int head = 2, tail = n;
  long long cur_sz = n * (n + 1) / 2;
  for (;;) {
    if (cur_sz - (tail - head) <= s) {
      h[tail - (cur_sz - s)]++;
      h[tail]--;
      break;
    }
    cur_sz -= tail - head;
    h[head]++;
    if (h[head] >= h[head - 1] * bandwidth) {
      head++;
    }
    h[tail]--;
    tail--;
  }
  long long sum = 1;
  for (int i = 2; h[i]; i++) {
    for (int j = sum + 1, fa = sum - h[i - 1] + 1; j <= sum + h[i]; j++) {
      f[j] = fa;
      fa++;
      if (fa > sum) {
        fa = sum - h[i - 1] + 1;
      }
    }
    sum += h[i];
  }
  for (int i = 2; i <= n; i++) {
    printf("%d ", f[i]);
  }
  puts("");
}
int main() {
  while (scanf("%lld%lld", &n, &s) != EOF) {
    if (s < 2 * n - 1 || s > n * (n + 1) / 2) {
      puts("No");
      continue;
    }
    int low = 0, high = n - 1;
    while (low + 1 < high) {
      int mid = (low + high) >> 1;
      if (check(mid))
        high = mid;
      else
        low = mid;
    }
    puts("Yes");
    output(high);
  }
}
