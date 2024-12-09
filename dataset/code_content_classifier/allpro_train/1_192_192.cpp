#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
void dfs(long long a, long long b, int f) {
  if (b > a) swap(a, b);
  if (a == 0 || b == 0) {
    if (f == 1)
      printf("Second\n");
    else
      printf("First\n");
    return;
  }
  if (a % b == 0) {
    if (f == 1)
      printf("First\n");
    else
      printf("Second\n");
    return;
  }
  if ((a / b % (b + 1)) % 2 == 0) {
    if (f == 1)
      printf("First\n");
    else
      printf("Second\n");
    return;
  }
  dfs(a % b, b, 1 - f);
}
void slove(long long a, long long b) { dfs(a, b, 1); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    slove(a, b);
  }
  return 0;
}
