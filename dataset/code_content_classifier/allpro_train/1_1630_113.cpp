#include <algorithm>
#include <cstdio>

const int N=500005;
int a[N],d[N];
long long b[N];
int main(){
	int n,q;
	scanf("%d%d\n",&n,&a[0]);
	for (int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		a[i]=std::min(a[i-1],abs(a[i-1]-d[i]));
	}
	for (int i=n;i>=1;i--)
		b[i]=(b[i+1]>=d[i]/2)*d[i]+b[i+1];
	scanf("%d\n",&q);
	for (int i=1;i<=q;i++){
		int x;
		scanf("%d",&x);
		if (b[x+1]>=a[x-1]) printf("NO\n");
			else printf("YES\n");
	}
}