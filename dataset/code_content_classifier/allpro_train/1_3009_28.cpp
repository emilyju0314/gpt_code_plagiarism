#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
const int N=105,mod=1e9+7,inv2=(mod+1)/2;
int xx[N],yy[N],x[N],y[N],w[N][N],d[N][N],q[N*N][2];
int H,W,n,m,cnt,ans;

int S2(int n){
	return (ll)n*(n+1)/2%mod;
}

int main(){
	read(H),read(W),read(cnt);
	xx[++n]=1,xx[++n]=H+1,yy[++m]=1,yy[++m]=W+1;
	rep(i,1,cnt){
		read(x[i]),read(y[i]),x[i]++,y[i]++;
		xx[++n]=x[i],xx[++n]=x[i]+1;
		yy[++m]=y[i],yy[++m]=y[i]+1;
	}
	sort(xx+1,xx+n+1),n=unique(xx+1,xx+n+1)-xx-1;
	sort(yy+1,yy+m+1),m=unique(yy+1,yy+m+1)-yy-1;
	rep(i,1,n-1) rep(j,1,m-1){
		w[i][j]=(ll)(xx[i+1]-xx[i])*(yy[j+1]-yy[j])%mod;
	}
	rep(i,1,cnt){
		x[i]=lower_bound(xx+1,xx+n+1,x[i])-xx;
		y[i]=lower_bound(yy+1,yy+m+1,y[i])-yy;
		w[x[i]][y[i]]=0;
	}
	rep(k,1,n-1) if(xx[k+1]-xx[k]>=2){
		int up=0,down=0;
		rep(i,1,n-1) rep(j,1,m-1){
			if(i<k) up=(up+w[i][j])%mod;
			if(i>k) down=(down+w[i][j])%mod;
		}
		ans=(ans+(ll)up*down%mod*(xx[k+1]-xx[k]-1))%mod;
		ans=(ans+(ll)(up+down)*W%mod*S2(xx[k+1]-xx[k]-1))%mod;
		int sum=0;
		rep(i,1,xx[k+1]-xx[k]-1) sum=(sum+(ll)i*(xx[k+1]-xx[k]-i))%mod;
		ans=(ans+(ll)W*W%mod*sum)%mod;
	}
	rep(k,1,m-1) if(yy[k+1]-yy[k]>=2){
		int le=0,ri=0;
		rep(i,1,n-1) rep(j,1,m-1){
			if(j<k) le=(le+w[i][j])%mod;
			if(j>k) ri=(ri+w[i][j])%mod;
		}
		ans=(ans+(ll)le*ri%mod*(yy[k+1]-yy[k]-1))%mod;
		ans=(ans+(ll)(le+ri)*H%mod*S2(yy[k+1]-yy[k]-1))%mod;
		int sum=0;
		rep(i,1,yy[k+1]-yy[k]-1) sum=(sum+(ll)i*(yy[k+1]-yy[k]-i))%mod;
		ans=(ans+(ll)H*H%mod*sum)%mod;
	}
	rep(i,1,n-1) rep(j,1,m-1) if(w[i][j]){
		int r=0;
		memset(d,-1,sizeof d);
		q[++r][0]=i,q[r][1]=j,d[i][j]=0;
		rep(l,1,r){
			int x=q[l][0],y=q[l][1];
			REP(dir,4){
				int xx=x+dx[dir],yy=y+dy[dir];
				if(!w[xx][yy]||d[xx][yy]>=0) continue;
				d[xx][yy]=d[x][y]+1;
				q[++r][0]=xx,q[r][1]=yy;
			}
		}
		rep(x,1,n-1) rep(y,1,m-1) if(w[x][y])
			ans=(ans+(ll)w[i][j]*w[x][y]%mod*d[x][y]%mod*inv2)%mod;
	}
	cout<<ans<<endl;
	return 0;
}