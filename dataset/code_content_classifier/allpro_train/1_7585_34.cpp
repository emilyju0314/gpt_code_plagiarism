#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, cas = 0;
  scanf("%d", &T);
  while (cas++ < T) {
    int sum = 0, s[251], maxi = 0;
    for (int i = 1; i <= 250; i++) {
      scanf("%d", s + i);
      sum += s[i];
      maxi = max(s[i], maxi);
    }
    double aver = sum / 250.0, fang = 0;
    for (int i = 1; i <= 250; i++) {
      fang += (s[i] - aver) * (s[i] - aver);
    }
    fang /= 250;
    if (fang / aver > 2) {
      printf("%.0f\n", maxi * 1.04 / 2);
    } else
      printf("%.0f\n", aver);
  }
  return 0;
}
