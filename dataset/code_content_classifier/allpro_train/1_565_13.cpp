#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 1e5 + 7;
const double pi = acos(-1.0);
const double eps = 0.0000000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline void add(int &A, int B) {
  A += B;
  (A >= M) && (A -= M);
}
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline T powMM(T a, T b) {
  T ret = 1;
  for (; b; b >>= 1ll, a = (long long)a * a % M)
    if (b & 1) ret = (long long)ret * a % M;
  return ret;
}
const int MAX = 1 << 19;
long long number[77][77];
int n, m;
char A[maxn];
int F[77][MAX + 7];
int TaskA() {
  int i, j, k;
  scanf("%d%s", &n, A + 1);
  for (i = 1; i <= n; i++)
    for (j = i; j <= n; j++)
      number[i][j] = min(250ll, number[i][j - 1] * 2 + A[j] - '0');
  int ans = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++)
      if (number[j][i] > 0 && number[j][i] < 20) {
        number[j][i]--;
        for (k = 1; k <= MAX; k++)
          add(F[i][k | (1 << number[j][i])], F[j - 1][k]);
        F[i][(1 << number[j][i])]++;
      }
    int now = 0;
    for (j = 0; j < 19; j++) now |= 1 << j, add(ans, F[i][now]);
  }
  printf("%d\n", ans);
  return 0;
}
void initialize() {}
void Task_one() { TaskA(); }
void Task_T() {
  int T;
  scanf("%d", &T);
  while (T--) TaskA();
}
void Task_more_n() {
  while (~scanf("%d", &n)) TaskA();
}
void Task_more_n_m() {
  while (~scanf("%d%d", &n, &m)) TaskA();
}
int main() {
  int startTime = clock();
  initialize();
  fprintf(stderr, "/--- initializeTime: %ld milliseconds ---/\n",
          clock() - startTime);
  Task_one();
}
