#include<stdio.h>

int main(void){
  long long a[100];
  int i,n;

  a[0]=2;
  a[1]=1;

  scanf("%d",&n);

  for(i=2;i<=n;i++)
    a[i]=a[i-1]+a[i-2];

  printf("%lld\n",a[n]);

  return 0;
}
