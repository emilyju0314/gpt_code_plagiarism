#include <stdio.h>
#include <math.h>
int main(){
float D,d,a,b,x,y;
while(scanf("%f%f%f%f%f",&D,&a,&b,&x,&y),D){
d=hypot(a,b);if(a*x+b*y>0)d=2-d;fabs(a*y-b*x)>1e-7||D<d?puts("impossible"):printf("%.8f\n",d);}
}