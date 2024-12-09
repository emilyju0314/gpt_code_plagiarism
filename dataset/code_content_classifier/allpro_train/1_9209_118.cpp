#include <bits/stdc++.h>
using namespace std;
inline int ADD(int a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return (int)a;
}
inline void ADDTO(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
inline void SUBTO(int &a, int b) {
  a -= b;
  if (a < 0) a += 1000000007;
}
inline int MUL(int a, int b) { return (int)((long long)a * b % 1000000007); }
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    if (n <= 2)
      puts("-1");
    else {
      printf("3 2 1");
      for (int i = 0; i < (n - 3); ++i) printf(" 1");
      puts("");
    }
  }
}
