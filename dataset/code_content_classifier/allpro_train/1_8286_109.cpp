#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 7;
int n, cnt[MAXN], k;
int main() {
  int sum = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    for (int j = i + i; j <= n; j += i) cnt[j]++, sum++;
  if (k > sum) {
    puts("No");
    return 0;
  }
  sum = 0;
  int num = 0;
  for (int i = 1; i <= n && sum < k; i++) sum += cnt[i], num = i;
  int tt = num;
  for (int i = 1; i <= num; i++)
    if (cnt[i] == 1 && k <= sum - num / i) sum -= num / i, tt--, cnt[i] = -1;
  if (sum != k) {
    puts("No");
    return 0;
  }
  puts("Yes");
  printf("%d\n", tt);
  for (int i = 1; i <= num; i++)
    if (cnt[i] >= 0) printf("%d ", i);
  return 0;
}
