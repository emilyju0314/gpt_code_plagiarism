#include<stdio.h>
int main(){
  double l,r;
  int a[4][2]={};
  while(scanf("%lf %lf",&l,&r) != EOF){
    if(l >= 1.1) a[0][0]++;
    else if(l >= 0.6) a[1][0]++;
    else if(l >= 0.2) a[2][0]++;
    else a[3][0]++;
    if(r >= 1.1) a[0][1]++;
    else if(r >= 0.6) a[1][1]++;
    else if(r >= 0.2) a[2][1]++;
    else a[3][1]++;
  }
  for(int i=0;i<4;i++){
    printf("%d %d\n",a[i][0],a[i][1]);
  }
  return (0);
}