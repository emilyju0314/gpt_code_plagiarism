#include<stdio.h>
const int MOD=1e9+7;
static inline int IN(void)
{
  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}
  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;
}
static inline void OUT(int x){if(x<0)putchar('-'),x=-x;if(x>=10)OUT(x/10);putchar(x%10+48);}
int main(void)
{
  int N=IN(),M=IN(),a=1,i=0,p=1,q=0,temp;
  while(i<N){a=(1l*a*(M-i++))%MOD;temp=q;q=1l*(p+temp)*(N-i)%MOD;p=(1l*p*(M-N)%MOD+1l*temp*(M-N+1)%MOD)%MOD;}
  return OUT(1l*a*p%MOD),0;
}