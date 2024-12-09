#include <cstdio>
typedef long long ll;
int n;
ll a[100001];

int main(void){
	scanf("%d",&n);
	scanf("%lld",&a[0]);
	ll res=a[0]-1LL,now=2;
	for(int i=1;i<n;i++){
		scanf("%lld",&a[i]);
		ll cnt=a[i]/now;
		if(a[i]==cnt*now){
			if(cnt==1)now++;
			cnt--;
		}
		res+=cnt;
	}
	printf("%lld\n",res);
	return 0;
}
