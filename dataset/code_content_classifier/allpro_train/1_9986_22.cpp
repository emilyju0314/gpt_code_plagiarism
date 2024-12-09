using namespace std;
#include <bits/stdc++.h>
#define N 25005
#define M 100005
int n,m;
int a[N];
int lmin[N],rmax[N];
int suc[N][2],pre[N][2];
int ans;
void work(int l,int r){
	for (int i=l;i<=r;++i){
		for (int &j=rmax[i];j<=r;++j)
			if (a[j]>a[i] && a[j]<a[suc[i][0]]){
				ans-=(pre[suc[i][0]][1]==i);
				suc[i][0]=j;
				ans+=(pre[suc[i][0]][1]==i);
			}
			else if (a[j]<a[i] && a[j]>a[pre[i][0]]){
				ans-=(suc[pre[i][0]][1]==i);
				pre[i][0]=j;
				ans+=(suc[pre[i][0]][1]==i);
			}
		for (int &j=lmin[i];j>=l;--j)
			if (a[j]>a[i] && a[j]<a[suc[i][1]]){
				ans-=(pre[suc[i][1]][0]==i);
				suc[i][1]=j;
				ans+=(pre[suc[i][1]][0]==i);
			}
			else if (a[j]<a[i] && a[j]>a[pre[i][1]]){
				ans-=(suc[pre[i][1]][0]==i);
				pre[i][1]=j;
				ans+=(suc[pre[i][1]][0]==i);
			}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	a[0]=n+1,a[n+1]=0;
	for (int i=1;i<=n;++i){
		lmin[i]=i-1,rmax[i]=i+1;
		suc[i][0]=suc[i][0]=0;
		pre[i][0]=pre[i][1]=n+1;
	}
	for (int i=1;i<=m;++i){
		int l,r;
		scanf("%d%d",&l,&r);
		work(l,r);
		printf("%d\n",ans);
	}
	return 0;
}
