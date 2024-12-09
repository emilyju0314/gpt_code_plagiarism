#include <bits/stdc++.h>
using namespace std;
int N, K;
int a[210000], I[210000];
long long d[210000];
int id[210000], cnt;
int vst[210000], rid;
bool cmp(int u, int v) { return a[u] < a[v]; }
int main() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
  int n = 0;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    d[i] = sum - (long long)n * (N - i - 1) * a[i];
    if (d[i] < K) {
      printf("%d\n", i + 1);
    } else {
      sum += (long long)n * a[i];
      n++;
    }
  }
  return 0;
}
