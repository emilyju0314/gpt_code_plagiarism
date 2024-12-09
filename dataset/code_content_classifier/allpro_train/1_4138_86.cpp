#include<bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
const int maxn=210;
long long fac[maxn],inv[maxn];
long long powd(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1) res=res*x%md;
		x=x*x%md;
		y>>=1;
	}
	return res;
}
char str[maxn];
int stk[maxn],top;
int n,m;
bool check(int x){
	static bool vis[maxn];
	static int ps[maxn];
	for(int i=1;i<=m;i++)
		vis[i]=0;
	int p=0,cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt>=top) break;
		if(str[i]=='r'){
			if(p<i) p=i;
			while(p<=m&&(vis[p]||str[p]=='r'))
				p++;
			if(p>m) return 0;
			cnt++;
			ps[cnt]=p;
			vis[i]=vis[p]=1;
		}
	}
	if(cnt!=top) return 0;
	cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt>=x) break;
		if(str[i]=='r'&&!vis[i]){
			vis[i]=1;
			cnt++;
		}
	}
	if(cnt!=x) return 0;
	p=m;
	for(int i=top;i>=1;i--){
		cnt=0;
		while(p>=ps[i]&&cnt<stk[i]/2){
			if(!vis[p]) cnt++;
			p--;
		}
		if(cnt!=stk[i]/2) return 0;
	}
	return 1;
}
long long sum[maxn][maxn];
void solve(int res,long long val,int num){
	long long fas;
	int tot=0;
	for(int i=1;i<=top;i++) tot+=stk[i];
	for(int i=0;i<=res;i++){
		if(tot+top+i*2>n+1) break;
		if(!check(i)) break;
		fas=fac[num+i]*val%md*inv[i]%md;
		(sum[tot+top+i*2][top]+=fas)%=md;
//		printf("%d %d\n",tot+top+i*2,top);
	}
}
void dfs(int res,int las,long long val,int num){
	solve(res,val,num);
	res--;
	int ttp;
	for(int i=1;i<=res&&i<=las;i+=2){
		ttp=top;
		for(int j=1;res-i*j>=0;j++){
			stk[++top]=i;
			dfs(res-i*j,i-1,val*inv[j]%md,num+j);
		}
		top=ttp;
	}
}
long long C[maxn][maxn];
int main(){
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=100;i++)
		fac[i]=fac[i-1]*i%md;
	inv[100]=powd(fac[100],md-2);
	for(int i=100;i>=1;i--)
		inv[i-1]=inv[i]*i%md;
	C[0][0]=C[1][0]=C[1][1]=1;
	for(int i=2;i<=100;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%md;
	}

	scanf("%d%d",&n,&m);
	scanf("%s",str+1);
	dfs(n+1,n,1,0);
	long long ans=0,st=0;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			if(!sum[i][j]) continue;
			st=0;
			for(int k=0;k<=j*2;k++){
				if(i+k<=n+1){
					ans=(ans+C[n+1][i+k]*C[j*2][k]%md*sum[i][j])%md;
					st+=C[n+1][i+k]*C[j*2][k]%md*sum[i][j];
				}
				else break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
