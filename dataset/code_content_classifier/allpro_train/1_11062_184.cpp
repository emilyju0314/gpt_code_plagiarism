#include<bits/stdc++.h>
using namespace std;
#define P 2019
int l,r,i,j,ans,mi;
int main() {
	scanf("%d%d",&l,&r);
	if(r-l>=2018) {
		puts("0");
		return 0;
	}
	ans=P;
	for(i=l; i<r; i++)
		for(j=i+1; j<=r; j++)
			mi=1ll*i*j%P,ans=min(ans,mi);
	printf("%d\n",ans);
	return 0;
}