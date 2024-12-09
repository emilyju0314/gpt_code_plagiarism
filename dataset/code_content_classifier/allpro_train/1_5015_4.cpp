#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define fr(i,c) for(__typeof(c.begin()) i=c.begin();i!=c.end();i++)
#define pb push_back
#define mp make_pair
#define all(c) c.begin(),c.end()
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
const int inf=(int)1e9;
const double EPS=1e-9, INF=1e12;

const int mod=(int)1e9+7;
int n,c,s,t;
ll C[2002][2002];
int m,in[2002];
vector<vi> e;

bool v[2002];
void rec(int c){
	v[c]=1;
	rep(i,e[c].size())if(!v[e[c][i]])rec(e[c][i]);
}
bool hasloop(){
	rep(i,n)if(in[i]==0&&!v[i])rec(i);
	rep(i,n)if(!v[i])return 1;
	return 0;
}

int cld[2002];
int reccld(int c){
	if(cld[c]>=0)return cld[c];
	cld[c]=1;
	rep(i,e[c].size())cld[c]+=reccld(e[c][i]);
	return cld[c];
}
ll T[2002];
ll recT(int c){
	ll &res=T[c];
	if(res>=0)return res;
	res=1;
	int n=cld[c]-1;
	rep(i,e[c].size()){
		res=res*recT(e[c][i])%mod;
		res=res*C[n][cld[e[c][i]]]%mod;
		n-=cld[e[c][i]];
	}
	return res;
}
ll dp[2002][2002],sum[2002][2002];

int main(){
	rep(i,2002)rep(j,i+1)C[i][j]=i==0||i==j?1ll:(C[i-1][j-1]+C[i-1][j])%mod;
	
	cin>>n>>c>>s>>t;
	e.resize(++n);
	rep(i,c){
		int a,b; cin>>a>>b;
		e[b].pb(a);
		in[a]++;
	}
	if(hasloop()){
		cout<<0<<endl; return 0;
	}
	for(int i=1;i<n;i++)if(in[i]==0)e[0].pb(i);
	t=n-t;
	
	static int prev[2002];
	rep(i,n)prev[i]=-1;
	queue<int> q; q.push(0);
	while(!q.empty()){
		int c=q.front(); q.pop();
		if(c==s)break;
		rep(i,e[c].size())q.push(e[c][i]), prev[e[c][i]]=c;
	}
	vi path;
	for(int c=s;c>=0;c=prev[c])path.pb(c);
	reverse(all(path));
	m=path.size();
	path.pb(n+1); T[n+1]=1;
	
	rep(i,n)cld[i]=T[i]=-1;
	rep(i,n)if(cld[i]<0)reccld(i);
	rep(i,n)if(T[i]<0)recT(i);
	
	rep(i,m){
		ll mul=1; int x=cld[path[i]]-cld[path[i+1]]-1;
		rep(j,e[path[i]].size())if(e[path[i]][j]!=path[i+1]){
			mul=mul*T[e[path[i]][j]]%mod*C[x][cld[e[path[i]][j]]]%mod;
			x-=cld[e[path[i]][j]];
		}
		rep(j,n+1)if(j>=i&&n-cld[path[i+1]]-1-j>=0){
			ll tmp=i&&j?sum[i-1][j-1]:1;
			tmp=tmp*C[n-cld[path[i+1]]-1-j][cld[path[i]]-cld[path[i+1]]-1]%mod;
			tmp=tmp*mul%mod;
			dp[i][j]=tmp;
			sum[i][j]=((j?sum[i][j-1]:0)+dp[i][j])%mod;
		}
	}
	cout<<dp[m-1][t]<<endl;
	
	return 0;
}