#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ans,a[500010],mn;
int pd(int mid){
	int i,j;
	for(i=mid*2+1,j=n*2;i<=n*2;i++,j--)if(a[i]+a[j]<m)return 0;
	return 1;
}
int main(){
	int i,j,l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n*2;i++)scanf("%d",&a[i]);
	sort(a+1,a+n*2+1);
	l=0;r=n;mn=n;
	while(l<=r){
		mid=(l+r)/2;
		if(pd(mid))mn=mid,r=mid-1;
		 else l=mid+1;
	}
	//printf("%d\n",mn);
	for(i=1;i<=mn;i++)ans=max(ans,a[i]+a[mn*2-i+1]);
	for(i=mn*2+1,j=n*2;i<=n*2;i++,j--)ans=max(ans,a[i]+a[j]-m);
	printf("%d",ans);
}