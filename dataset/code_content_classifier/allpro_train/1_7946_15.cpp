#include<bits/stdc++.h>
#define ll long long
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;
const int mo=1000000007;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int calc(int y){
	return 1ll*(power(10,y)-1)*power(9,mo-2)%mo;
}
int n,Q,v[35];
int f[33333][10];
pii q[35];
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		q[i]=pii(x-1,i);
		q[i+Q]=pii(y,i);
	}
	sort(q+1,q+2*Q+1);
	For(i,1,2*Q-1) v[i]=calc(q[i+1].fi-q[i].fi);
	f[0][0]=1;
	For(i,0,(1<<Q)-1){
		for (int to=1;to<1<<Q;){
			if (to^(i&to)){
				to+=to^(i&to);
				continue;
			}
			int val=1;
			For(j,1,2*Q-1){
				int s1=0,s2=0;
				if (to&(1<<(q[j].se-1))) s1=2;
				else if (i&(1<<(q[j].se-1))) s1=1;
				if (to&(1<<(q[j+1].se-1))) s2=2;
				else if (i&(1<<(q[j+1].se-1))) s2=1;
				if (s1+s2==4) val=1ll*val*(v[j]+1)%mo;
				else if (s1+s2==3) val=1ll*val*v[j]%mo;
			}
			For(j,0,8)
				f[i][j+1]=(f[i][j+1]+1ll*val*f[i-to][j])%mo;
			++to;
		}
		For(j,0,8)
			f[i][j+1]=(f[i][j+1]+f[i][j])%mo;
	}
	int ans=1ll*f[(1<<Q)-1][9]*power(9,mo-2)%mo;
	int cnt=n-q[2*Q].fi+q[1].fi;
	printf("%d\n",1ll*ans*power(10,cnt)%mo);
}