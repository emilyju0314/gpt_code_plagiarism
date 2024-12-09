#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,m;
int pr[M],ne[M],t[M<<1];
ll a[M],b[M];
vector<int>e;
int pre(int x){return pr[x]==x?x:pr[x]=pre(pr[x]);}
int nex(int x){return ne[x]==x?x:ne[x]=nex(ne[x]);}
ll v[M];
void push(int x,int y){
	for(t[x+=n-1]=y;x;x>>=1)t[x>>1]=v[t[x]]<v[t[x^1]]?t[x^1]:t[x];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),ne[i]=i,pr[i]=i;
	for(int i=m;i>=1;--i)scanf("%lld",&b[i]);
	for(int i=1;i< n;++i)v[i]=a[i],push(i,i),a[i]+=a[i-1];
	int ans=0;
	for(int i=1;i<=m;++i){
		while(v[t[1]]>b[i]){
			int x=t[1],y=pre(x-1),z=nex(x+1);
			pr[x]=y,ne[x]=z;
			ans=max(ans,z-y-1);
			push(x,0);
			if(z!=n){
				v[z]=(a[z]-a[y]-1)/(z-y)+1;
				push(z,z);
			}
		}
		e.eb(ans);
	}
	for(int i=m-1;i>=0;--i)printf("%d ",e[i]);
	return 0;
} 
/*
5 1
5 2 1 3 7
1
*/