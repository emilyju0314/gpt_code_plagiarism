#include<stdio.h>
int main(){
  int n, x, t;
  scanf("%d%d%d", &n, &x, &t);
  printf("%d\n", (n/x + ( n%x ==0 ? 0 : 1))*t);
  return 0;
}