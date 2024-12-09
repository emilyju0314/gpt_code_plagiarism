#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
/*
use under a[i][j]!=0 -> abs(i-j)<=B
(??????+-B?????????????????????????????????)
??????????????????swap?????±?????§,-B~+2B?????§???3B+1??????vi??????????????£??????
?????????0????????????B-th value(0-indexed) ???a[i][i]??????????????????????????????
time O(NB^2)
space O(NB)
*/
typedef long long ll;
ll mod=1e9+7;
typedef vector<ll> vi;
typedef vector<vi> bmat;
ll ex(ll x,ll p){
	ll a=1;
	while(p){
		if(p%2) a=a*x%mod;
		x=x*x%mod;
		p/=2;
	}
	return a;
}
ll inv(ll a){
	return ex(a,mod-2);
}
ll det(bmat a){
	int N=a.size();
	if(N==0) return 1;
	int B=a[0].size()/3;
	ll ans=1;
	rep(i,N){
		if(a[i][B]==0){
			for(int j=i+1;j<N;j++){
				if(B-(j-i)<0) break;
				if(a[j][B-(j-i)]!=0){
					int d=j-i;
					for(int k=d;k<=2*B+d;k++){
						swap(a[i][k],a[j][k-d]);
					}
					ans*=-1;
					break;
				}
			}
			if(a[i][B]==0) return 0;
		}
		for(int j=i+1;j<N;j++){
			if(B-(j-i)<0) break;
			int d=j-i;
			ll c=a[j][B-d]*inv(a[i][B])%mod;
			for(int k=B;k<=3*B;k++){
				a[j][k-d]=(a[j][k-d]-c*a[i][k])%mod;
			}
		}
		ans=ans*a[i][B]%mod;
	}
	if(ans<0) ans+=mod;
	return ans;
}
int H,W;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
string s[500];
bool is(int x,int y){
	return 0<=x&&x<H&&0<=y&&y<W&&s[x][y]=='.';
}
int n[500][15];
int main(){
	int tt=0;
	while(true){
		tt++;
		cin>>H>>W;
		if(H==0) break;
		rep(i,H) cin>>s[i];
		int N=0;
		rep(i,H) rep(j,W){
			if(s[i][j]=='#') n[i][j]=-1;
			else n[i][j]=N++;
		}
		bmat a(N-1,vi(3*W+1,0));
		rep(i,H) rep(j,W){
			if(!is(i,j)) continue;
			if(n[i][j]==N-1) break;
			rep(d,4){
				int x=i+dx[d],y=j+dy[d];
				if(!is(x,y)) continue;
				if(n[x][y]!=N-1) a[n[i][j]][n[x][y]-n[i][j]+W]++;
				a[n[i][j]][W]++;
			}
		}
		cout<<"Case "<<tt<<": "<<det(a)<<endl;
	}
}