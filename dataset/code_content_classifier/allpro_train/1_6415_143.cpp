#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  int remain = n - m;
  int divide = max(m, 1);
  printf("%d\n", min(remain, divide));
}
