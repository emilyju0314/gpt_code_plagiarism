#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define reps(i,s,n) for(int i=s;i<n+s;i++)
#define ireps(i,s,n) for(int i=s+n-1;i>=s;i--)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
inline bool B(int t,int i){return (t>>i)&1;}
typedef double D;
int N,K,Y,s[3],t[3],x[102],y[102],oid[102];
vector<int> ys;
vector<int> y2id[102];			//ashed y -> ids
D R,e[102][102],inf=1e9,eps=1e-8;
void changeid(){
	int iv[102];
	rep(i,N) iv[oid[i]]=i;
	rep(i,K) s[i]=iv[s[i]],t[i]=iv[t[i]];
}
bool kon(int i,int j,int k){
	if(i>j) swap(i,j);
	if(k<i||j<k) return 0;
	int c=(y[k]-y[i])*(x[j]-x[i]) - (x[k]-x[i])*(y[j]-y[i]);
	return c==0;
}
D dp[102][102][102],ndp[102][102][102],tmp3[102][102][102],tmp2[102][102],tmp1[102];
int t3[8][3]={
	{2,1,0},
	{2,1,0},
	{2,1,0},
	{1,2,0},
	{0,2,1},
	{0,1,2},
	{0,1,2},
	{0,1,2}
};
D changeith(int a,int b,int c,int& na,int& nb,int& nc,int i,int ad,int o,int S){
	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);
	int x=0;
	if(i==0) x=a;
	if(i==1) x=b;
	if(i==2) x=c;
	int nx=x+ad;
	if(nx==o-1||nx==o+S) return inf;
	D ret=e[x][nx];
	if(x==na) na+=ad;
	if(x==nb) nb+=ad;
	if(x==nc) nc+=ad;
	if(na==nb||nb==nc||nc==na) return inf;
	return ret;
}
void dothree(int y){
//	printf("dothree %d\n",y);
	vector<int> vc=y2id[y];
	int S=vc.size(),o=vc[0];
	rep(t,8){
		reps(i,o,S) reps(j,o,S) reps(k,o,S) tmp3[i][j][k]=dp[i][j][k];
		rep(i_,3){
			int i=t3[t][i_];			//i-th leftest move
			if(B(t,2-i)){		//right
				reps(a,o,S) reps(b,o,S) reps(c,o,S) if(a!=b&&b!=c&&a!=c){
					int na=a,nb=b,nc=c;
					D cost=changeith(a,b,c,na,nb,nc,i,1,o,S);
					chmin(tmp3[na][nb][nc],tmp3[a][b][c]+cost);
				}
			}else{			//left
				ireps(a,o,S) ireps(b,o,S) ireps(c,o,S) if(a!=b&&b!=c&&a!=c){
					int na=a,nb=b,nc=c;
					D cost=changeith(a,b,c,na,nb,nc,i,-1,o,S);
					chmin(tmp3[na][nb][nc],tmp3[a][b][c]+cost);
				}
			}
		}
		reps(i,o,S) reps(j,o,S) reps(k,o,S) chmin(ndp[i][j][k],tmp3[i][j][k]);
	}
}
int t2[4][2]={
	{1,0},
	{1,0},
	{1,0},
	{0,1}
};
D changeith2(int a,int b,int& na,int &nb,int i,int ad,int o,int S){
	if(a>b) swap(a,b);
	int x=0;
	if(i==0) x=a;
	if(i==1) x=b;
	int nx=x+ad;
	if(nx==o-1||nx==o+S) return inf;
	D ret=e[x][nx];
	if(x==na) na+=ad;
	if(x==nb) nb+=ad;
	if(na==nb) return inf;
	return ret;
}
void dotwo(int y){
//	printf("dotwo %d\n",y);
	vector<int> vc=y2id[y];
	int S=vc.size(),o=vc[0];
	{				//a: not y
		rep(t,4){
			rep(a,N){
				if(o<=a&&a<o+S) continue;
				reps(j,o,S) reps(k,o,S) tmp2[j][k]=dp[a][j][k];
				rep(i_,2){
					int i=t2[t][i_];			//i-th leftest move
					if(B(t,1-i)){		//right
						reps(b,o,S) reps(c,o,S) if(b!=c){
							int nb=b,nc=c;
							D cost=changeith2(b,c,nb,nc,i,1,o,S);
							chmin(tmp2[nb][nc],tmp2[b][c]+cost);
						}
					}else{			//left
						ireps(b,o,S) ireps(c,o,S) if(b!=c){
							int nb=b,nc=c;
							D cost=changeith2(b,c,nb,nc,i,-1,o,S);
							chmin(tmp2[nb][nc],tmp2[b][c]+cost);
						}
					}
				}
				reps(j,o,S) reps(k,o,S) chmin(ndp[a][j][k],tmp2[j][k]);
			}
		}
	}
	{				//b: not y
		rep(t,4){
			rep(b,N){
				if(o<=b&&b<o+S) continue;
				reps(j,o,S) reps(k,o,S) tmp2[j][k]=dp[j][b][k];
				rep(i_,2){
					int i=t2[t][i_];			//i-th leftest move
					if(B(t,1-i)){		//right
						reps(a,o,S) reps(c,o,S) if(a!=c){
							int na=a,nc=c;
							D cost=changeith2(a,c,na,nc,i,1,o,S);
							chmin(tmp2[na][nc],tmp2[a][c]+cost);
						}
					}else{			//left
						ireps(a,o,S) ireps(c,o,S) if(a!=c){
							int na=a,nc=c;
							D cost=changeith2(a,c,na,nc,i,-1,o,S);
							chmin(tmp2[na][nc],tmp2[a][c]+cost);
						}
					}
				}
				reps(j,o,S) reps(k,o,S) chmin(ndp[j][b][k],tmp2[j][k]);
			}
		}
	}
	{				//c: not y
		rep(t,4){
			rep(c,N){
				if(o<=c&&c<o+S) continue;
				reps(j,o,S) reps(k,o,S) tmp2[j][k]=dp[j][k][c];
				rep(i_,2){
					int i=t2[t][i_];			//i-th leftest move
					if(B(t,1-i)){		//right
						reps(a,o,S) reps(b,o,S) if(a!=b){
							int na=a,nb=b;
							D cost=changeith2(a,b,na,nb,i,1,o,S);
							chmin(tmp2[na][nb],tmp2[a][b]+cost);
						}
					}else{			//left
						ireps(a,o,S) ireps(b,o,S) if(a!=b){
							int na=a,nb=b;
							D cost=changeith2(a,b,na,nb,i,-1,o,S);
							chmin(tmp2[na][nb],tmp2[a][b]+cost);
						}
					}
				}
				reps(j,o,S) reps(k,o,S) chmin(ndp[j][k][c],tmp2[j][k]);
			}
		}
	}
}
void doone(int y){
	vector<int> vc=y2id[y];
	int S=vc.size(),o=vc[0];
	{
		rep(b,N) rep(c,N){
			if(o<=b&&b<o+S) continue;
			if(o<=c&&c<o+S) continue;
			reps(a,o,S) tmp1[a]=dp[a][b][c];
			reps(a,o,S) if(a+1!=o+S) chmin(tmp1[a+1],tmp1[a]+e[a][a+1]);
			ireps(a,o,S) if(a-1!=o-1) chmin(tmp1[a-1],tmp1[a]+e[a][a-1]);
			reps(a,o,S) chmin(ndp[a][b][c],tmp1[a]);
		}
	}
	{
		rep(a,N) rep(c,N){
			if(o<=a&&a<o+S) continue;
			if(o<=c&&c<o+S) continue;
			reps(b,o,S) tmp1[b]=dp[a][b][c];
			reps(b,o,S) if(b+1!=o+S) chmin(tmp1[b+1],tmp1[b]+e[b][b+1]);
			ireps(b,o,S) if(b-1!=o-1) chmin(tmp1[b-1],tmp1[b]+e[b][b-1]);
			reps(b,o,S) chmin(ndp[a][b][c],tmp1[b]);
		}
	}
	{
		rep(a,N) rep(b,N){
			if(o<=a&&a<o+S) continue;
			if(o<=b&&b<o+S) continue;
			reps(c,o,S) tmp1[c]=dp[a][b][c];
			reps(c,o,S) if(c+1!=o+S) chmin(tmp1[c+1],tmp1[c]+e[c][c+1]);
			ireps(c,o,S) if(c-1!=o-1) chmin(tmp1[c-1],tmp1[c]+e[c][c-1]);
			reps(c,o,S) chmin(ndp[a][b][c],tmp1[c]);
		}
	}
}
int main(){
	cin>>N>>K>>R;
	rep(i,K) cin>>s[i],s[i]--;
	rep(i,K) cin>>t[i],t[i]--;
	rep(i,N) cin>>x[i]>>y[i];
	while(K<3){
		x[N]=N,y[N]=10001;
		s[K]=N,t[K]=N;
		N++;
		K++;
	}
	rep(i,N) oid[i]=i;
	rep(i,N-1) rep(j,N-1) if( y[j]>y[j+1] || (y[j]==y[j+1]&&x[j]>x[j+1]) ) swap(x[j],x[j+1]),swap(y[j],y[j+1]),swap(oid[j],oid[j+1]);
	changeid();
//	rep(i,K) printf("s[%d],t[%d]=%d,%d\n",i,i,s[i],t[i]);
	rep(i,N) rep(j,N) if(i!=j){
		e[i][j]=sqrt( (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) );
		if(e[i][j]>R+eps) e[i][j]=inf;
		rep(k,N) if(k!=i&&k!=j){
			if(kon(i,j,k)) e[i][j]=inf;
		}
	}
	rep(i,N) ys.pb(y[i]);
	sort(all(ys));
	ys.erase(unique(ys.begin(),ys.end()),ys.end());
	rep(i,N) y2id[ lower_bound(all(ys),y[i])-ys.begin() ].pb(i);
	Y=ys.size();
	rep(i,N) rep(j,N) rep(k,N) dp[i][j][k]=inf;
	dp[s[0]][s[1]][s[2]]=0;
	rep(yid,Y){
		rep(a,N) rep(b,N) rep(c,N) if(dp[a][b][c]<inf){			// a:<y -> y
			if(y[a]<ys[yid]){
				for(int n:y2id[yid]) if(n!=b&&n!=c) chmin(dp[n][b][c],dp[a][b][c]+e[a][n]);
			}
		}
		rep(a,N) rep(b,N) rep(c,N) if(dp[a][b][c]<inf){			// b:<y -> y
			if(y[b]<ys[yid]){
				for(int n:y2id[yid]) if(n!=a&&n!=c) chmin(dp[a][n][c],dp[a][b][c]+e[b][n]);
			}
		}
		rep(a,N) rep(b,N) rep(c,N) if(dp[a][b][c]<inf){			// c:<y -> y
			if(y[c]<ys[yid]){
				for(int n:y2id[yid]) if(n!=a&&n!=b) chmin(dp[a][b][n],dp[a][b][c]+e[c][n]);
			}
		}
		rep(a,N) rep(b,N) rep(c,N) ndp[a][b][c]=dp[a][b][c];
		dothree(yid);
		dotwo(yid);
		doone(yid);
		rep(a,N) rep(b,N) rep(c,N) dp[a][b][c]=ndp[a][b][c];
	}
	// rep(i,N) rep(j,N){
	// 	printf("e[%d][%d]=%lf\n",i,j,e[i][j]);
	// }
	// rep(i,N) rep(j,N) rep(k,N) if(dp[i][j][k]!=inf){
	// 	printf("dp[%d][%d][%d]=%f\n",i,j,k,dp[i][j][k]);
	// }
	D ans=dp[t[0]][t[1]][t[2]];
	if(ans==inf) ans=-1;
	printf("%.12f\n",ans);
}