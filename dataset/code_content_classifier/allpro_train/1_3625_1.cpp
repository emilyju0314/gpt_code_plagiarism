#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>0;--i)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define Vi vector<int>
#define pb push_back
#define i197 1000000007
#define MAX_N 200002
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<Pii,int> Piii;
typedef pair<ll,int> Pli;
typedef pair<string,string> Pss;
const int inf=1000000000;
struct edge{
	int myc,to,c,cost;
};
struct pos{
	int to,cost,color;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int th[3001][3001]={};
int main() {
	int n,m;
	cin>>n>>m;
	Vi v,h;
	int vt=0;
	Vi dp(n+1,0);
	v.push_back(0);
	h.push_back(0);
	rep(i,n){
		int v1,h1;
		cin>>v1>>h1;
		vt+=v1;
		v.push_back(vt);
		h.push_back(h1);
	}
	rep(i,n){
		th[i+1][i+1]=h[i+1];
		for(int j=i+2;j<n+1;++j){
			th[i+1][j]=th[i+1][j-1]+h[j]+abs(h[j]-h[j-1]);
		}
	}
	int t1,s1;
	cin>>t1>>s1;
	rrep(j,n+1){
		if(v[j]>t1)continue;
		dp[j]=th[1][j];
		if(dp[j]<s1)dp[j]=-1;
	}
	dp[0]=-1;

	for(int i=1;i<m;++i){
		cin>>t1>>s1;
		rrep(j,n+1){
			if(v[j]>t1)continue;

			if(dp[j]==0){
				rep(k,j){
					if(dp[k]==-1)continue;
					dp[j]=max(dp[j],dp[k]+th[k+1][j]);
				}
			}
			if(dp[j]<s1)dp[j]=-1;
		}
//		cout<<i<<endl;
//		rep(j,n+1)cout<<dp[j]<<endl;
	}
	bool flg=false;
	int res=-1;
	rrep(i,n+1){
		if(dp[i]>0){
			flg=true;
			res=max(res,t1-v[i]);
		}
	}
	if(flg){
		cout<<res<<endl;
	}else{
		cout<<"-1"<<endl;
	}
	return 0;
}

