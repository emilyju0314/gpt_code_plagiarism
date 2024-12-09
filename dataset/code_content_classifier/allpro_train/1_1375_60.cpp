#include <cstdio>

int main(){
  int N, D1, X; scanf("%d%d%d", &N, &D1, &X);

  double d1v = 1;
  for(int i = 2; i <= N; i++) d1v = d1v * (i + 1) / i + 1;

  double xv = d1v * (2 * N - 1) / 2;

  printf("%.20lf\n", D1 * d1v + X * xv);
  return 0;
}