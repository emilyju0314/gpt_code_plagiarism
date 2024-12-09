#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=998244353;
int par[300002];
int rk[300002];
void init(int n){
	for(int i=0; i<n; i++){
		par[i]=i;
		rk[i]=0;
	}
}
int find(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}
void unite(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rk[x]<rk[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rk[x]==rk[y]) rk[x]++;
	}
}
bool same(int x, int y){
	return find(x)==find(y);
}
int main()
{
	int n;
	cin>>n;
	int a[600001];
	bool all1=1;
	ll ct[300001]={};
	for(int i=0; i<n; i++){
		cin>>a[i];
		ct[a[i]]++;
		if(a[i]>1) all1=0;
		a[i+n]=a[i];
	}
	if(all1){
		ll ans=1;
		for(ll i=1; i<=n; i++) ans=ans*i%MOD;
		cout<<ans<<endl;
		return 0;
	}
	int mn[300001], mx[300001];
	fill(mn, mn+n+1, -1);
	int i0=0;
	for(int i=1; i<n; i++){
		if(a[i]!=a[0]){
			i0=i;
			break;
		}
	}
	int p=-1;
	for(int i=i0; i<n+i0; i++){
		if(p!=a[i]){
			if(p!=-1) mx[p]=i-1;
			p=a[i];
			if(mn[p]>0){
				cout<<0<<endl;
				return 0;
			}
			mn[p]=i;
		}
	}
	mx[p]=n+i0-1;
	if(mn[1]==-1){
		cout<<0<<endl;
		return 0;
	}
	int d=mx[1]-mn[1]+1;
	for(int i=2; i<=n; i++){
		if(mn[i]>0 && mx[i]-mn[i]+1>d){
			cout<<0<<endl;
			return 0;
		}
	}
	for(int i=1; i<=n; i++){
		ct[i]+=ct[i-1];
	}
	init(n);
	ll e=0;
	ll ans=1;
	for(int i=1; i<=n; i++){
		if(mn[i]>0){
			for(int j=mn[i]; j<=mx[i]; j++){
				if(a[(j+n-1)%n]<=i){
					if(!same((j+n-1)%n, j%n)){
						unite((j+n-1)%n, j%n);
						e++;
					}
				}
				if(a[(j+1)%n]<=i){
					if(!same((j+1)%n, j%n)){
						unite((j+1)%n, j%n);
						e++;
					}
				}
			}
		}
		if(mn[i]>0){
			int i1=(mn[i]-1+n)%n, i2=(mx[i]+1)%n;
			if(mx[i]-mn[i]+1<d && a[i1]>i && a[i2]>i){
				cout<<0<<endl;
				return 0;
			}
			if(a[i1]>i || a[i2]>i) continue;
			ans*=((ll)(mn[i]-mx[i]+d));
			ans%=MOD;
		}else{
			if(e<n-1){
				ans*=(ct[i]-((ll)d-1)*(ct[i]-e)-(ll)i+1);
				ans%=MOD;
			}else{
				ans*=((ll)(n-i+1));
				ans%=MOD;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}