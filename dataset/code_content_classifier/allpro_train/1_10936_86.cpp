#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
const int mlog=18;
const int B=150;
const int S=maxn/B+5;
int n,q,m;
int a[maxn],p[maxn],c[maxn],bl[S],br[S],bu[maxn];

namespace Fenwick{
	int t[maxn];
	void add(int v,int val){
		for(;v<=n;v+=(v&-v))
			t[v]+=val;
	}
	int qry(int k){
		int res=0;
		for(int i=mlog-1;i>=0;i--){
			int cur=res+(1<<i);
			if(cur<=n&&(1<<i)-t[cur]<k)
				k-=(1<<i)-t[cur],res=cur;
		}
		res++;
		return res;
	}
}

void update(int id){
	for(int i=br[id];i>=bl[id];i--){
		p[i]=Fenwick::qry(a[i]);
		Fenwick::add(p[i],1);
	}
	for(int i=bl[id];i<=br[id];i++)
		Fenwick::add(p[i],-1),c[i]=p[i];
	sort(c+bl[id],c+br[id]+1);
}
int query(int id,int k){
	int l=bl[id]-1,r=br[id];
	while(l<r){
		int mid=l+r+1>>1;
		if(c[mid]-(mid-bl[id]+1)<k)l=mid;
		else r=mid-1;
	}
	return k+l-bl[id]+1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]=i-a[i];
	for(int i=1;i<=n;i+=B){
		m++;
		bl[m]=i;
		br[m]=min(n,i+B-1);
		for(int j=bl[m];j<=br[m];j++)bu[j]=m;
		update(m);
	}
	scanf("%d",&q);
	while(q--){
		int op,i;
		scanf("%d%d",&op,&i);
		if(op==1){
			int x;
			scanf("%d",&x);
			a[i]=i-x;
			update(bu[i]);
		}
		else{
			int ans=p[i];
			for(int j=bu[i]+1;j<=m;j++)
				ans=query(j,ans);
			printf("%d\n",ans);
		}
	}
	return 0;
}
