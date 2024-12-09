#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 100010;
long long minimise(int b, int k) {
  long long t = b / k;
  long long c = b % k;
  long long ret = (1LL * ((t + 1) * (t + 1) * c)) + 1LL * t * t * (k - c);
  assert(ret > 0);
  return ret;
}
long long maximise(int a, int k) {
  long long ret = 1LL * (a - k + 1) * (a - k + 1);
  ret += (k - 1);
  assert(ret > 0);
  return ret;
}
int main() {
  int a, b, k = 0;
  scanf("%d %d", &a, &b);
  long long ans = 1LL * a * a - 1LL * b * b;
  for (int i = 1; i < min(b, a + 1); i++) {
    long long temp = maximise(a, i);
    temp -= minimise(b, i + 1);
    if (ans < temp) {
      ans = temp;
      k = i;
    }
  }
  printf("%lld\n", ans);
  if (k == 0) {
    while (b--) {
      printf("x");
    }
    while (a--) {
      printf("o");
    }
    return 0;
  }
  __f("k", k);
  int t = b / (k + 1);
  int c = b % (k + 1);
  int m = 0;
  while (c--) {
    int d = t + 1;
    while (d--) {
      printf("x");
    }
    if (m == k - 1) {
      while (a > 0) {
        printf("o");
        a -= 1;
      }
      continue;
    }
    printf("o");
    a -= 1;
    m += 1;
  }
  c = k + 1 - (b % (k + 1));
  while (c--) {
    int d = t;
    while (d--) {
      printf("x");
    }
    if (m == k - 1) {
      while (a > 0) {
        printf("o");
        a -= 1;
      }
      continue;
    }
    printf("o");
    a -= 1;
    m += 1;
  }
  return 0;
}
