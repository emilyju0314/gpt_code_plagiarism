#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,ll>P;

namespace seg{
int N;
P dat[400000];

void init(int n){
	N=1;while(N<n)N<<=1;
}
P merge(P a,P b){
	if(a.first)b.second*=-1;
	return P(a.first^b.first,a.second+b.second);
}
void update(int k,P x){
	k+=N;
	dat[k]=x;
	while(k>1){
		k>>=1;
		dat[k]=merge(dat[k*2],dat[k*2+1]);
	}
}
P query(int l,int r){
	P resl(0,0),resr(0,0);
	for(l+=N,r+=N;l<r;l>>=1,r>>=1){
		if(l&1)resl=merge(resl,dat[l++]);
		if(r&1)resr=merge(dat[--r],resr);
	}
	return merge(resl,resr);
}
};

int a[200000];
int main(){
	int K,n,q;cin>>K>>n>>q;
	rep(i,n){
		scanf("%d",&a[i]);a[i]*=-1;
	}
	seg::init(n);
	rep(i,n){
		seg::update(i,P(!a[i],a[i]));
	}
	rep(i,q){
		int l,r;scanf("%d%d",&l,&r);l--;r--;
		swap(a[l],a[r]);
		seg::update(l,P(!a[l],a[l]));
		seg::update(r,P(!a[r],a[r]));
		auto p=seg::query(0,n);
		ll sum=((p.second%K)+K)%K;
		sum=(sum+K)%K;
		int ans=sum+1;
		if(p.first)ans=-ans;
		printf("%d\n",ans);
	}
}
