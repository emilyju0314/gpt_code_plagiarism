#include <bits/stdc++.h>
int v[300001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int highSingle = 0, highPair = 0;
  int singlel = n / 2, singler = singlel;
  int pairl = n / 2, pairr = pairl;
  if (n % 2 == 0) {
    singler--;
    pairl--;
    highPair = std::min(v[pairl], v[pairr]);
  } else {
    highSingle = v[singlel];
  }
  for (int i = 0; i < n - 1; i++) {
    if ((n - i) % 2 == 0) {
      singlel--;
      singler++;
      highSingle = std::max(highSingle, v[singlel]);
      highSingle = std::max(highSingle, v[singler]);
      printf("%d ", highSingle);
    } else {
      pairl--;
      pairr++;
      highPair = std::max(highPair, std::min(v[pairl], v[pairl + 1]));
      highPair = std::max(highPair, std::min(v[pairr], v[pairr - 1]));
      printf("%d ", highPair);
    }
  }
  printf("%d", highSingle);
  printf("\n");
  return 0;
}
