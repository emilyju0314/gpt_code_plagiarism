#include <bits/stdc++.h>
using namespace std;
void p(vector<int> a) {
  int x = 0;
  for (int y : a) {
    if (x) printf(" ");
    printf("%d", y);
    x = 1;
  }
  puts("");
}
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) return !printf("-1\n");
  vector<int> a, b, c;
  for (int i = 0; i < n; ++i) a.emplace_back(i), b.emplace_back(i);
  for (int i = 0; i < n; ++i) c.emplace_back((a[i] + b[i]) % n);
  p(a);
  p(b);
  p(c);
}
