#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

void pairsort(int n,int *a,int *b){
	pair<int,int> c[1000];
	rep(i,n) c[i]=make_pair(a[i],b[i]);
	sort(c,c+n);
	rep(i,n) a[i]=c[i].first, b[i]=c[i].second;
}

int n,m;
int x[1000],num[1000],esa[1000];

int sum[1001];
int count_cat(int l,int r){ // [l, r] にいるねこの数
	int i=lower_bound(x,x+n,l)-x;
	int j=upper_bound(x,x+n,r)-x;
	return sum[j]-sum[i];
}

bool check(int ub){
	// dp[i] := ( esa[i] にごはんを置いたときに右から来るねこの最小数 )
	int dp[1000];
	dp[m-1]=count_cat(esa[m-1]+1,20000);
	for(int i=m-2;i>=0;i--){
		dp[i]=INF;
		for(int j=i+1;j<m;j++){
			int a=count_cat(esa[i]+1,(esa[i]+esa[j])/2); // (esa[i], (esa[i]+esa[j])/2] にいるねこの数
			int b=count_cat((esa[i]+esa[j])/2+1,esa[j]); // ((esa[i]+esa[j])/2, esa[j]] にいるねこの数
			if(b+dp[j]<=ub){
				dp[i]=min(dp[i],a);
			}
		}
	}

	rep(i,m){
		if(dp[i]+count_cat(0,esa[i])<=ub) return true;
	}
	return false;
}

int main(){
	while(scanf("%d%d",&n,&m),m){
		rep(i,n) scanf("%d%*d%d",x+i,num+i), x[i]+=10000;
		rep(i,m) scanf("%d",esa+i), esa[i]+=10000; // あとで /2 するとき 0 方向へ丸められるのがイヤなので >=0 にしておく

		pairsort(n,x,num);
		sort(esa,esa+m);

		rep(i,n) sum[i+1]=sum[i]+num[i];

		int lo=0,hi=100000000;
		while(lo<hi){
			int mi=(lo+hi)/2;
			if(check(mi)) hi=mi; else lo=mi+1;
		}
		printf("%d\n",lo);
	}

	return 0;
}