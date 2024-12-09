#include <cstdio>
#include <map>
using namespace std;
long long n,x,m;
long long a[200005];
map<long long,int>ma;
int l,r;
long long sum,asum;
int main(){
	scanf("%lld%lld%lld",&n,&x,&m);
	a[1]=x;
	for(int i=2;;++i){
		a[i]=a[i-1]*a[i-1]%m;
		if(ma.count(a[i])){
			l=ma[a[i]];
			r=i;
			break;
		}
		ma[a[i]]=i;
	}
	if(n<l){
		for(int i=1;i<=n;++i)sum+=a[i];
		printf("%lld\n",sum);
		return 0;
	}
	for(int i=1;i<l;++i){
		sum+=a[i];
	}
	n-=l;
	++n;
	for(int i=l;i<r;++i)asum+=a[i];
	sum+=asum*(n/(r-l));
	n%=r-l;
	for(int i=l;i<l+n;++i)sum+=a[i];
	printf("%lld\n",sum);
	return 0;
}
