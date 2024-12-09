#include "bits/stdc++.h"
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define vi vector<int>
#define pb push_back
#define INF (1LL<<59)

ll d[20][100][100];
vector<int> q[20];
vector<int> r[20];

ll f(ll dist,int c){
	if(dist==INF)return INF;
	ll ret=0;
	for(int i=1;;i++){
		if(q[c][i]<dist){
			ret+=(q[c][i]-q[c][i-1])*r[c][i-1];
		}
		else return ret+(dist-q[c][i-1])*r[c][i-1];
	}
}


int main(){
	int n,m,c,s,g;
	while(cin>>n>>m>>c>>s>>g&&(n||m||c||s||g)){
		rep(i,20)rep(j,100)rep(k,100)d[i][j][k]=INF;
		rep(i,m){
			int x,y,di,cam;
			cin>>x>>y>>di>>cam;
			x--,y--,cam--;
			d[cam][x][y]=min<ll>(di,d[cam][x][y]);
			d[cam][y][x]=min<ll>(di,d[cam][y][x]);
		}
		
		vector<int> b(c);
		rep(i,c)cin>>b[i];
		rep(i,c){
			q[i].resize(b[i]+1);
			q[i][0]=0, q[i][b[i]]=200000000;
			r[i].resize(b[i]);
			rep(j,b[i]-1)cin>>q[i][j+1];
			rep(j,b[i])cin>>r[i][j];
		}

		
		rep(p,20) rep(wk,n) rep(wi,n) rep(wj,n) d[p][wi][wj] = min(d[p][wi][wk]+d[p][wk][wj],d[p][wi][wj]);
		rep(p,20) rep(wi,n) rep(wj,n) d[p][wi][wj] = f(d[p][wi][wj],p);
		
		ll pass[100][100];
		rep(i,100)rep(j,100)pass[i][j]=INF;
		rep(wi,n) rep(wj,n) rep(p,20) pass[wi][wj] = min(pass[wi][wj],d[p][wi][wj]);
		
		rep(wk,n) rep(wi,n) rep(wj,n) pass[wi][wj] = min(pass[wi][wk]+pass[wk][wj],pass[wi][wj]);
		
		if(pass[s-1][g-1]==INF)cout<<-1<<endl;
		else cout<<pass[s-1][g-1]<<endl;
	}
}