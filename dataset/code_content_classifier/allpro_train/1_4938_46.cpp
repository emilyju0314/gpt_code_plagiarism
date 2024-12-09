#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  getchar();
  char a[n + 1];
  scanf("%s", &a);
  for (int i = 0; i < n - 1; i++)
    if (a[i] != a[i + 1]) return printf("Yes\n%c%c", a[i], a[i + 1]), 0;
  return printf("No"), 0;
}
