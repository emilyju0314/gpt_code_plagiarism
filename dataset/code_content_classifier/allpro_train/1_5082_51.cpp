#include<stdio.h>
inline int GCD(int a,int b){return !b?a:GCD(b,a%b);}
signed main(void){int X;if(scanf("%d",&X)==1)return printf("%d\n",360/GCD(X,360)),0;}