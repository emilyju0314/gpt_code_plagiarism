#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[110];
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1,d;i<=k;++i){
		scanf("%d",&d);
		while(d--){
			int x;
			scanf("%d",&x);
			a[x]=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(!a[i]) ++ans;
	}
	printf("%d\n",ans);
}