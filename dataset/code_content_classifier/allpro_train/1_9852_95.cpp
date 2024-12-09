#include <stdio.h>
long long x,a=100,ans;
int main(){
    scanf("%lld",&x);while(a<x) a+=a/100,ans++;printf("%lld\n",ans);return 0;
}