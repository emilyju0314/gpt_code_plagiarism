#include<bits/stdc++.h>
long long n,m,a[233],sum;
int main(){
	scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum+=a[i];
    std::sort(a+1,a+n+1,std::greater<long long>());
	puts(a[m]*4*m>=sum?"Yes":"No");
}