#include <bits/stdc++.h>
int main(int argc, const char* argv[]) {
  int n, k;
  int a[100000 + 1];
  scanf("%d%d", &n, &k);
  int i;
  int count = 0;
  int is_ukn = scanf("%d", a) != 1;
  for (i = !is_ukn; i <= n; i++)
    scanf("%d", a + i) != 1 && getchar() && count++;
  int is_man_move = (n + 1 - count) & 1;
  int is_man_end = n & 1;
  if (k == 0) {
    puts((is_ukn && is_man_move) || (!is_ukn && a[0] == 0) ? "Yes" : "No");
    return 0;
  }
  int some_ukn = is_ukn || count;
  if (some_ukn) {
    puts(is_man_end ? "Yes" : "No");
    return 0;
  }
  int sum2 = 0;
  for (i = 0; i <= n && sum2 % k == 0; i++) {
    sum2 /= k;
    sum2 += a[i];
  }
  if (i == n + 1) {
    if (k != 1 && k != -1)
      while (sum2 != 0 && sum2 % k == 0) sum2 /= k;
    if (sum2 == 0) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
