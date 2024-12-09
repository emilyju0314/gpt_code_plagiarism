#include<bits/stdc++.h>
#define maxn 200100
#define inf 1000000007
using namespace std;
typedef pair<int,int> par;
struct data{
	int lc,rc,atg;
	par p;
}s[maxn*60];
int n,a[maxn],ptr,rt;
par qry(int& o,int l,int r,int ql,int qr){
	if(!o)s[o=++ptr].p=par(l,l);
	if(ql<=l&&r<=qr)
		return s[o].p;
	int mid=l+r>>1;
	par ans(inf,inf);
	if(ql<=mid)ans=min(ans,qry(s[o].lc,l,mid,ql,qr));
	if(qr>mid)ans=min(ans,qry(s[o].rc,mid+1,r,ql,qr));
	return par(ans.first+s[o].atg,ans.second);
}
void mdy(int &o,int l,int r,int ql,int qr){
	if(ql>qr)return ;
	if(!o)s[o=++ptr].p=par(l,l);
	if(ql<=l&&r<=qr){
		s[o].atg++;
		s[o].p.first++;
		return ;
	}
	int mid=l+r>>1;
	if(ql<=mid)mdy(s[o].lc,l,mid,ql,qr);
	if(qr>mid)mdy(s[o].rc,mid+1,r,ql,qr);
	s[o].p=min(s[o].lc?s[s[o].lc].p:par(inf,inf),s[o].rc?s[s[o].rc].p:par(inf,inf));
	s[o].p=par(s[o].p.first+s[o].atg,s[o].p.second);
}
int main(){
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		par x=qry(rt,1,inf,a[i],inf);
		ans+=x.first-a[i],mdy(rt,1,inf,1,x.second-1);
	}
	printf("%lld",ans);
}