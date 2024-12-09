#include <bits/stdc++.h>
using namespace std;
int c[10], A[20];
long long ans = 0;
int check(int k) {
  long long x = 0;
  for (int i = 0; i <= 9; i++)
    for (int j = 1; j <= c[i]; j++) x = x * 10 + i;
  long long y = 0;
  for (int i = k; i >= 1; i--) y = y * 10 + A[i];
  if (x <= y) return 1;
  return 0;
}
void DFS(int x, long long now, int f) {
  if (x < 1) {
    ans = now;
    return;
  }
  for (int j = 9; j >= 0; j--) {
    if (c[j] && (j <= A[x] || f)) {
      c[j]--;
      f = (j < A[x]) | f;
      if (check(x - 1) || f) DFS(x - 1, now * 10 + j, f);
      if (ans) return;
      c[j]++;
    }
  }
}
int main() {
  long long a, b;
  cin >> a >> b;
  int wa = 0, wb = 0;
  while (a) {
    c[a % 10]++;
    a /= 10;
    wa++;
  }
  int top = 0;
  while (b) {
    A[++top] = b % 10;
    b /= 10;
    wb++;
  }
  if (wa < wb) {
    for (int i = 9; i >= 0; i--)
      for (int j = 1; j <= c[i]; j++) printf("%d", i);
    puts("");
    return 0;
  }
  DFS(top, 0, 0);
  cout << ans << endl;
  return 0;
}
