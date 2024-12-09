#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T t) {
  return t < 0 ? -t : t;
}
const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }
int a[100009], b[100009];
int main() {
  int i, n, m;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > 0)
      b[a[i]]++, b[a[i] + 1]--;
    else {
      b[0]++;
      b[-a[i]]--;
      b[-a[i] + 1]++;
    }
  }
  int pos = 0;
  for (i = 1; i <= n; i++) {
    b[i] += b[i - 1];
    if (b[i] == m) pos++;
  }
  for (i = 0; i < n; i++) {
    if (a[i] > 0) {
      if (b[a[i]] == m && pos == 1)
        puts("Truth");
      else if (b[a[i]] == m)
        puts("Not defined");
      else
        puts("Lie");
    } else {
      if (b[-a[i]] == m && pos == 1)
        puts("Lie");
      else if (b[-a[i]] == m)
        puts("Not defined");
      else
        puts("Truth");
    }
  }
}
