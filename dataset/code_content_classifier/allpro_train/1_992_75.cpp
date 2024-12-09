#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> A[100000 + 1];
pair<long long, long long> B[100000 + 1];
pair<long long, long long> C[100000 + 1];
int Q[100000 + 1];
int N, sf;
inline long long Dist(pair<long long, long long> A,
                      pair<long long, long long> B) {
  return (A.first - B.first) * (A.first - B.first) +
         (A.second - B.second) * (A.second - B.second);
}
bool cmp(const pair<long long, long long> A,
         const pair<long long, long long> B) {
  if (A.second == B.second) return A.first < B.first;
  return A.second < B.second;
}
long long Compute(int st, int dr) {
  if (st >= dr) return 1LL << 62;
  if (dr - st == 1) {
    if (B[st].second > B[dr].second) swap(B[st], B[dr]);
    return Dist(B[st], B[dr]);
  }
  int i, j, mid = (st + dr) / 2;
  long long best = min(Compute(st, mid), Compute(mid + 1, dr));
  sf = 0;
  merge(B + st, B + mid + 1, B + mid + 1, B + dr + 1, C, cmp);
  for (i = st; i <= dr; ++i) B[i] = C[i - st];
  for (i = st; i <= dr; ++i)
    if (fabs(B[i].first - A[mid].first) <= best) Q[++sf] = i;
  for (i = 1; i < sf; ++i)
    for (j = 1; i + j <= sf && j < 8; ++j)
      best = min(best, Dist(B[Q[i]], B[Q[i + j]]));
  return best;
}
int main() {
  int i, first;
  long long sum = 0;
  scanf("%d", &N);
  for (i = 1; i <= N; ++i) {
    scanf("%d", &first);
    sum += first;
    A[i] = {i, sum};
  }
  sort(A + 1, A + N + 1);
  for (i = 1; i <= N; ++i) B[i] = A[i];
  printf("%I64d\n", Compute(1, N));
  return 0;
}
