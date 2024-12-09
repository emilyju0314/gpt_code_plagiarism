#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)

using namespace std;

const int N=310,mod=998244353;
int n,m,r,sum,all,vis[N]; bitset<N> b[N];

int insert(bitset<N> x){
	rep (i,0,m-1)
		if (x.test(i))
			if (!vis[i]){vis[i]=1,b[i]=x; return 1;}
			else x^=b[i];
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	rep (i,1,n){
		bitset<N> a;
		rep (j,1,m){
			int x; scanf("%d",&x);
			if (x) a.set(j-1);
		}
		r+=insert(a);
	}
	all=1;
	rep (i,1,n) all=(all+all)%mod;
	sum=1;
	rep (i,1,n-r) sum=(sum+sum)%mod;
	all=(all+mod-sum)%mod;
	rep (i,1,m-1) all=(all+all)%mod;
	printf("%d\n",all);
	return 0;
}