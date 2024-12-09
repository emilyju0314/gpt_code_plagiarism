#include <bits/stdc++.h>
using namespace std;
int n;
int solve(int k) {
  if (k > n) return 0;
  return 1 + solve(k * 10) + solve(k * 10 + 1);
}
int main() {
  scanf("%d", &n);
  printf("%d\n", solve(1));
}
