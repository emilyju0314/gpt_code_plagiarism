#include <bits/stdc++.h>
using namespace std;
long n, d;
long s[200001], p[200001];
void inp() {
  scanf("%ld%ld", &n, &d);
  long i;
  for (i = 0; i < n; i++) scanf("%ld", s + i);
  for (i = 0; i < n; i++) scanf("%ld", p + i);
}
bool comp(long a, long b) { return a > b; }
void solve() {
  long i = 0, temp, j = n - 1;
  d--;
  temp = s[d] + p[0];
  s[d] = temp;
  while (i < n && j > 0) {
    if (i == d || s[i] > temp) {
      i++;
      continue;
    }
    s[i] += p[j];
    i++;
    j--;
  }
  sort(s, s + n, comp);
  i = 0;
  while (s[i] != temp) i++;
  printf("%ld", i + 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  inp();
  solve();
  return 0;
}
