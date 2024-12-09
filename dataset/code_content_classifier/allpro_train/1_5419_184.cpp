#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (!a && !b)
    printf("NO");
  else
    abs(a - b) <= 1 ? printf("YES") : printf("NO");
  return 0;
}
