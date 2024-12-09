#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:255000000")
bool firstout = 1;
template <class T>
T &minn(T &a, T b) {
  if (b < a) a = b;
  return a;
}
template <class T>
T &maxx(T &a, T b) {
  if (a < b) a = b;
  return a;
}
int &madd(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
int &msub(int &a, int b) {
  a -= b;
  if (a < 0) a += 1000000007;
  return a;
}
int &mmult(int &a, int b) { return a = (long long)a * b % 1000000007; }
int mdiv(long long a, long long b, long long m) {
  a = (a % m + m) % m;
  b = (b % m + m) % m;
  if (a % b == 0) return a / b;
  return (a + m * mdiv(-a, m, b)) / b;
}
int n, m, q;
int A[1012];
int I[1012], II[1012];
int B[1012];
void make(int *A, int n) {
  int i, j, k, d;
  for (i = (0); i < (n); ++i) A[i] = 1;
  for (i = (0); i < (n); ++i) I[i] = i;
  int m = n;
  for (; m > 3;) {
    d = 1;
    int mm = 0;
    II[mm++] = 0;
    k = 0;
    vector<int> v;
    for (j = (11) - 1; j >= (1); --j) {
      for (; j * j <= m; m -= j * j) {
        d *= j;
        v.push_back(j);
        II[mm++] = I[k + j * j];
        k += j * j;
      }
    }
    m = --mm;
    for (i = (0); i < (m); ++i) I[i] = II[i];
    for (i = (0); i < (m); ++i)
      for (j = (I[i]); j < (i + 1 < m ? I[i + 1] : n); ++j) A[j] *= d / v[i];
  }
  if (m == 2) {
    for (i = (0); i < (I[1]); ++i) A[i] *= 3;
    for (i = (I[1]); i < (n); ++i) A[i] *= 4;
  }
  if (m == 3) {
    for (i = (0); i < (I[2]); ++i) A[i] *= 2;
  }
}
int main() {
  int i, j, k;
  char c;
  int a, d;
  int ts;
  for (ts = 1; scanf("%"
                     "d",
                     &(n)) > 0;
       ++ts) {
    scanf(
        "%"
        "d",
        &(m));
    make(A, n);
    make(B, m);
    for (i = (0); i < (n); ++i) {
      for (j = (0); j < (m); ++j)
        printf((firstout) ? "%"
                            "d"
                          : " %"
                            "d",
               (A[i] * B[j])),
            firstout = 0;
      printf("\n"), firstout = 1;
    }
  }
  return 0;
}
