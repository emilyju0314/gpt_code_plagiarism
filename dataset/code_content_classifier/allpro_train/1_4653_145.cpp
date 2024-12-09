#include <cstdio>
int main(){
  int N; scanf("%d", &N);
  double ans=0;
  for(int i=0; i<N; i++){
    double a; scanf("%lf", &a);
    a = 1/a;
    ans += a;
  }
  printf("%lf\n", 1/ans);
}