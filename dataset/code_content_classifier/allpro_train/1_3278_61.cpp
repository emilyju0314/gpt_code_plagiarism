#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define print(n) cout<<n<<endl
const int M=100111;
const int inf=1000000007;
const long long INF=1000000000000000007;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ddx[8]={1,-1,0,0,1,-1,-1,1},ddy[8]={0,0,1,-1,1,-1,1,-1};

int main(){
	int n,r,x1,x2,h;
	while(1){
		cin>>r>>n;
		if(r==0&&n==0)break;
		map<int,int> mp;
		rep(i,0,n){
			cin>>x1>>x2>>h;
			rep(x,x1,x2){
				mp[x]=max(mp[x],h);
			}
		}

		double ans=inf;
		rep(x,-r,r){
			double p=(x<0?x+1:x);
			ans=min(ans,mp[x]+r-sqrt(r*r-p*p));
		}
		print(setprecision(15)<<ans);
	}
}
