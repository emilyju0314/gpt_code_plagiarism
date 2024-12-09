#include<stdio.h>
#include<algorithm>
using namespace std;
pair<int,int>b[4100];
long long dp[4100][4100];
int ra[4100];
int sa[4100];
int ss[4100];
long long sum[4100];
int lb[4100];
inline long long calc(int a,int l,int r){
	if(l>r)return 0;
	long long ret=0;
	if(l<lb[a]){
		ret+=(long long)sa[a]*(lb[a]-l)-(sum[lb[a]]-sum[l]);
	}
	if(r+1<lb[a]){
		ret-=(long long)sa[a]*(lb[a]-r-1)-(sum[lb[a]]-sum[r+1]);
	}
	if(r>=lb[a]){
		ret+=(sum[r+1]-sum[lb[a]])-(long long)sa[a]*(r-lb[a]+1);
	}
	if(l>lb[a]){
		ret-=(sum[l]-sum[lb[a]])-(long long)sa[a]*(l-lb[a]);
	}
	//printf("%d %d %d: %lld\n",a,l,r,ret);
	return ret;
}
void solve(int t,int a,int b,int c,int d){
	if(a>=b)return;
	int M=(a+b)/2;
	long long val=999999999999999LL;
	int at=-1;
	for(int i=c;i<d&&i<=M;i++){
		if(M-i>ss[t])continue;
		long long cost=dp[t][i]+calc(t,i,M-1);
		if(val>cost){
			val=cost;at=i;
		}
	}
	dp[t+1][M]=val;
	solve(t,a,M,c,at+1);
	solve(t,M+1,b,at,d);
}
int main(){
	int a;
	while(scanf("%d",&a),a){
		for(int i=0;i<a;i++){
			int p,q;scanf("%d%d",&p,&q);
			b[i]=make_pair(p,q);
		}
		std::sort(b,b+a);
		long long ret=b[a-1].first-b[0].first;
		int R=0;
		int S=0;
		int st=0;
		for(int i=0;i<a;i++){
			int req=2;
			if(i==0||i==a-1)req--;
			if(req<b[i].second){
				sa[S]=b[i].first;
				ss[S++]=b[i].second-req;
			}else if(req>b[i].second){
				ra[R++]=b[i].first;
			}
			st+=b[i].second;
		}
		if(st<2*a-2){
			printf("-1\n");continue;
		}
		for(int i=0;i<=R;i++)sum[i]=0;
		for(int i=0;i<R;i++)sum[i+1]=sum[i]+ra[i];
		for(int i=0;i<S;i++){
			lb[i]=lower_bound(ra,ra+R,sa[i])-ra;
		}
		for(int i=0;i<=S;i++){
			for(int j=0;j<=R;j++)dp[i][j]=99999999999999LL;
		}
		dp[0][0]=0;
		int now=0;
		for(int i=0;i<S;i++){
			solve(i,0,R+1,0,R+1);
		//	now+=ss[i];
		//	if(now>=R)now=R;
		//	for(int j=0;j<=now;j++)printf("%lld ",dp[i+1][j]);
		//	printf("\n");
		}
		ret+=dp[S][R];
		printf("%lld\n",ret);
	}
}