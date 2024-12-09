#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T checkmin(T &a, T b) {
  return (a < b) ? a : a = b;
}
template <class T>
inline T checkmax(T &a, T b) {
  return (a > b) ? a : a = b;
}
template <class T>
T GCD(T a, T b) {
  if (a < 0) return GCD(-a, b);
  if (b < 0) return GCD(a, -b);
  return (a == 0) ? b : GCD(b % a, a);
}
template <class T>
T LCM(T a, T b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return (a == 0 || b == 0) ? 0 : a / GCD(a, b) * b;
}
template <class T>
inline T sqr(T X) {
  return X * X;
}
namespace Poor {
const int MaxiL = 1000005;
const int MaxiN = 205;
const int MaxiM = 205;
const int MaxiQL = 3005;
int N, L;
char St[MaxiL];
char Rule[MaxiQL];
int SeqX[MaxiM], SeqY[MaxiM];
int Stack[MaxiL];
inline bool Same(const int a, const int b, const int c, const int d) {
  if (b - a != d - c) return 0;
  for (register int i = 0; i < b - a; ++i)
    if (St[a + i] != Rule[c + i]) return 0;
  return 1;
}
void Run() {
  gets(St);
  L = strlen(St);
  scanf("%d\n", &N);
  for (int i = 0; i < N; ++i) {
    gets(Rule);
    int M = 0;
    for (int p = 0; Rule[p] != '\0'; ++p)
      if (isalpha(Rule[p])) {
        int q = p;
        for (; isalpha(Rule[q]); ++q)
          ;
        SeqX[M] = p;
        SeqY[M] = q;
        ++M;
        p = q - 1;
      }
    register int res = 0;
    register int *Top = Stack;
    *Top = 0;
    ++Top;
    for (register int p = 0, q = 0; p < L; p = q + 1) {
      for (q = p; St[q] != '>'; ++q)
        ;
      if (St[p + 1] == '/') {
        --Top;
        continue;
      }
      if (St[q - 1] == '/') {
        if (*(Top - 1) >= M - 1 && Same(p + 1, q - 1, SeqX[M - 1], SeqY[M - 1]))
          ++res;
        continue;
      }
      *Top = *(Top - 1);
      if (*Top < M - 1) {
        if (Same(p + 1, q, SeqX[*Top], SeqY[*Top])) ++*Top;
      } else {
        if (Same(p + 1, q, SeqX[M - 1], SeqY[M - 1])) ++res;
      }
      ++Top;
    }
    printf("%d\n", res);
  }
}
}  // namespace Poor
int main() {
  Poor::Run();
  return 0;
}
