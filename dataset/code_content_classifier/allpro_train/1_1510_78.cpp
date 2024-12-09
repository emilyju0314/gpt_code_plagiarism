#include <bits/stdc++.h>
using namespace std;
int s[30010];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
    int sum = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (s[i] > s[j]) ++sum;
    if (sum % 2 == 1)
      sum += sum - 1;
    else
      sum *= 2;
    double v = sum;
    printf("%.6lf\n", v);
  }
  return 0;
}
