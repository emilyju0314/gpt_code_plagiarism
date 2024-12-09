#include <bits/stdc++.h>
int main(int argc, char **args) {
  int i, size, diff, *input, succ = 1;
  scanf("%d", &size);
  input = (int *)malloc((size - 1) * sizeof(*input));
  scanf("%d", &diff);
  diff = size - diff;
  for (i = 0; i < size - 1; i++) {
    scanf("%d", &input[i]);
    if (i + 1 != (input[i] + (i % 2 ? diff : size - diff)) % size) {
      succ = 0;
    }
  }
  printf("%s\n", succ ? "Yes" : "No");
  free(input);
  return 0;
}
