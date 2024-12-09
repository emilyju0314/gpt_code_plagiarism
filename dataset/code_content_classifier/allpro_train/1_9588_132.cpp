#include <bits/stdc++.h>
int main(void) {
  unsigned int n, m, k;
  unsigned int i, j;
  unsigned int *cell;
  unsigned int min = 100001;
  scanf("%u %u %u", &n, &m, &k);
  if (n % 2 == 0 || (n + 1) / 2 > m) {
    for (i = 0; i < n; i++) scanf("%u", &j);
    puts("0");
    return 0;
  }
  cell = (unsigned int *)calloc(n, sizeof(unsigned int));
  for (i = 0; i < n; i++) scanf("%u", cell + i);
  for (i = 0; i < n; i += 2)
    if (min > *(cell + i)) min = *(cell + i);
  m /= (n + 1) / 2;
  printf("%u\n", ((min < m * k) ? (min) : (m * k)));
  free(cell);
  return 0;
}
