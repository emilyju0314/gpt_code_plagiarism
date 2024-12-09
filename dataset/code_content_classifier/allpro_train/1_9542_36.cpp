#include <bits/stdc++.h>
using namespace std;
const long long MAX = 10 + (long long)1E18;
vector<long long> A;
void init(long long crr) {
  if (crr > MAX) return;
  if (crr != 0) A.push_back(crr);
  if (crr * 10.0 + 4 < MAX) init(crr * 10 + 4);
  if (crr * 10.0 + 7 < MAX) init(crr * 10 + 7);
}
int N;
long long K;
long long L[100010], R[100010];
long long readll() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
long long Lcost[1000010];
long long llmul(long long a, long long b) {
  if (double(a) * double(b) > MAX)
    return MAX;
  else
    return a * b;
}
int main() {
  N = readll();
  K = readll();
  init(0);
  sort((A).begin(), (A).end());
  long long min_len = (long long)1E18;
  for (int i = 0; i < (int)(N); i++) {
    L[i] = readll();
    R[i] = readll();
    min_len = min(min_len, R[i] - L[i] + 1);
  }
  sort(L, L + N);
  sort(R, R + N);
  {
    long long sum = 0, cnt = 0, prv_p = 0;
    int i = N - 1;
    for (int j = A.size() - 1; j >= 0; --j) {
      long long p = A[j];
      sum += llmul(cnt, prv_p - p);
      sum = min(sum, MAX);
      while (i >= 0 && L[i] > p) {
        sum += L[i] - p;
        sum = min(sum, MAX);
        ++cnt;
        --i;
      }
      Lcost[j] = sum;
      prv_p = p;
    }
  }
  int ans = 0;
  {
    long long sum = 0, cnt = 0, prv_p = 0;
    int i = 0, lj = 0;
    for (int rj = 0; rj < (int)(A.size()); rj++) {
      long long p = A[rj];
      sum += llmul(cnt, p - prv_p);
      sum = min(sum, MAX);
      while (i < N && R[i] < p) {
        sum += p - R[i];
        sum = min(sum, MAX);
        ++cnt;
        ++i;
      }
      while (lj < rj && A[rj] - A[lj] + 1 > min_len) ++lj;
      while (lj < rj && sum + Lcost[lj] > K) ++lj;
      if (sum + Lcost[lj] <= K) {
        ans = max(ans, rj - lj + 1);
      }
      prv_p = p;
    }
  }
  printf("%d\n", ans);
  return 0;
}
