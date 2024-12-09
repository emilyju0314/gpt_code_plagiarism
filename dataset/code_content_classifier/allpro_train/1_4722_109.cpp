#include <bits/stdc++.h>
using namespace std;
const int maxN(1e5 + 11);
typedef int i_N[maxN];
int N, lim, p, q;
long long M, S[maxN];
pair<int, int> A[maxN];
i_N B;
int main() {
  scanf("%d %d %d %d %I64d\n", &N, &lim, &p, &q, &M);
  for (int i = 1; i <= N; i++) {
    int x;
    scanf("%d", &x);
    A[i] = pair<int, int>(x, i);
  }
  sort(A + 1, A + N + 1);
  A[N + 1] = pair<int, int>(lim, N + 1);
  for (int i = 1; i <= N + 1; i++) S[i] = S[i - 1] + A[i].first;
  long long ans = -1, ansi, ansl;
  for (int i = N + 1; i; i--) {
    M -= lim - A[i].first;
    if (M < 0) break;
    int l = 0, r = lim;
    do {
      int mid = (l + r) / 2 + 1;
      int j = lower_bound(A + 1, A + N + 2, pair<int, int>(mid, 0)) - A;
      j = min(j, i);
      if ((long long)mid * (j - 1) - S[j - 1] <= M)
        l = mid;
      else
        r = mid - 1;
    } while (l < r);
    if (ans < (long long)p * (N - i + 1) + (long long)q * l) {
      ans = (long long)p * (N - i + 1) + (long long)q * l;
      ansi = i;
      ansl = l;
    }
  }
  printf("%I64d\n", ans);
  for (int i = ansi; i <= N; i++) B[A[i].second] = lim;
  for (int i = 1; i < ansi; i++)
    B[A[i].second] = A[i].first < ansl ? ansl : A[i].first;
  for (int i = 1; i <= N; i++) printf("%d ", B[i]);
}
