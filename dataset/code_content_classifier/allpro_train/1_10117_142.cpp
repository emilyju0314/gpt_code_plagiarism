#include <cstdio>
#include <vector>

int main() {
  int N;
  long long K;
  scanf("%d %lld", &N, &K);

  std::vector<long long> A(100010);
  for (int i=0; i<N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    A[a] += b;
  }

  for (int i=1; i<=100000; ++i)
    if ((K -= A[i]) <= 0)
      return !printf("%d\n", i);

  return 0;
}