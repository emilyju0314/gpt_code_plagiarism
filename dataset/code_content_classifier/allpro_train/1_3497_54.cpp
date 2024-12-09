#include <bits/stdc++.h>
using namespace std;
using namespace std;
using namespace std;
int x[1000005], krok[1000005], nast[1000005];
int a, b, difference, n;
int current, ans, dop;
int main(void) {
  scanf("%d", &n);
  for (int(i) = 0; (i) < (n); ++(i)) scanf("%d", &x[i]);
  scanf("%d %d", &a, &b);
  difference = a - b;
  sort(x, x + n);
  for (int(i) = 0; (i) < (difference + 1); ++(i)) krok[i] = 1;
  for (int(i) = 0; (i) < (n); ++(i))
    if ((i == 0 || x[i] != x[i - 1])) {
      dop = (x[i] - b % x[i]) % x[i];
      for (int j = dop; j <= difference; j += x[i])
        krok[j] = max(krok[j], x[i] - 1);
    }
  nast[0] = krok[0];
  for (long long(i) = (1); (i) <= (difference); ++(i)) {
    nast[i] = i + krok[i];
    nast[i] = max(nast[i], nast[i - 1]);
  }
  for (; current < difference;) {
    current = nast[current];
    ++ans;
  }
  printf("%d", ans);
}
