#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
const long double pi = acos(-1.0);
int n;
int m;
char ans[2000100];
int l = 0;
void push_back(char ch) { ans[l++] = ch; }
int main() {
  scanf("%d%d", &n, &m);
  if (n <= m) {
    int k = m - n;
    if (k <= n + 2) {
      int p = min(k, n);
      for (int i = 0; i < p; i++) {
        push_back('1');
        push_back('1');
        push_back('0');
      }
      for (int i = 0; i < n - p; i++) {
        push_back('1');
        push_back('0');
      }
      if (k == n + 1) {
        push_back('1');
      }
      if (k == n + 2) {
        push_back('1');
        push_back('1');
      }
    } else {
      printf("-1\n");
      return 0;
    }
  } else {
    if (n == m + 1) {
      push_back('0');
      for (int i = 0; i < m; i++) {
        push_back('1');
        push_back('0');
      }
    } else {
      printf("-1\n");
      return 0;
    }
  }
  puts(&ans[0]);
  return 0;
}
