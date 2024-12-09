#include <bits/stdc++.h>
using namespace std;
int a[100005];
vector<int> v1, v2;
int main() {
  int n;
  scanf("%d", &n);
  n++;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    if (a[i] > 1 && a[i - 1] > 1) {
      printf("ambiguous\n");
      int cntp = 0;
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < a[j]; k++) {
          v1.push_back(cntp);
          v2.push_back(cntp);
        }
        if (j == i) v2[v2.size() - 1]++;
        cntp += (j == 0 ? 1 : a[j - 1]);
      }
      int sz = v1.size();
      for (int j = 0; j < sz; j++) printf("%d ", v1[j]);
      printf("\n");
      for (int j = 0; j < sz; j++) printf("%d ", v2[j]);
      return 0;
    }
  }
  printf("perfect");
  return 0;
}
