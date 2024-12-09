#include <cmath>
#include <queue>
#include <cstdio>
#include <cassert>
#include <algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;
const double PI=acos(-1);

struct point{
	double x,y;
	point():x(0),y(0){}
	point(double x,double y):x(x),y(y){}
	point &operator+=(const point &a){ x+=a.x; y+=a.y; return *this; }
	point &operator-=(const point &a){ x-=a.x; y-=a.y; return *this; }
	point &operator*=(double c){ x*=c; y*=c; return *this; }
	point &operator/=(double c){ x/=c; y/=c; return *this; }
	point operator+(const point &a)const{ return point(x+a.x,y+a.y); }
	point operator-(const point &a)const{ return point(x-a.x,y-a.y); }
	point operator/(double c)const{ return point(x/c,y/c); }
	point operator-()const{ return point(-x,-y); }
	bool operator< (const point &a)const{ return x+EPS<a.x || (abs(x-a.x)<EPS && y+EPS<a.y); }
	bool operator==(const point &a)const{ return abs(x-a.x)<EPS && abs(y-a.y)<EPS; }
	bool operator!=(const point &a)const{ return abs(x-a.x)>EPS || abs(y-a.y)>EPS; }
};

double cross(const point &a,const point &b){ return a.x*b.y-a.y*b.x; }

double arg(const point &a){ double t=atan2(a.y,a.x); return t<0?t+2*PI:t; }

typedef vector<point> polygon;

bool is_ccw(const polygon &F){
	int n=F.size();
	double A=0;
	rep(i,n) A+=cross(F[i],F[(i+1)%n]);
	return A>-EPS;
}

// trace the frame of a polygon
vector<int> trace(const vector<int> *G,int u0,int i0){
	vector<int> F;
	int u=u0,i=i0;
	do{
		F.push_back(u);
		int v=G[u][i];
		int k=G[v].size();
		rep(j,k) if(G[v][j]==u) i=(j-1+k)%k;
		u=v;
	}while(u!=u0 || i!=i0);
	return F;
}

// normalize the list of vertices
vector<int> reg(vector<int> a){
	int k=min_element(a.begin(),a.end())-a.begin();
	rep(i,k){
		a.push_back(a[0]);
		a.erase(a.begin());
	}
	return a;
}

int main(){
	for(int n,m;scanf("%d%d",&n,&m),n;){
		point P[100];
		rep(u,n) scanf("%lf%lf",&P[u].x,&P[u].y);

		vector<int> G[100];
		rep(i,m){
			int u,v; scanf("%d%d",&u,&v); u--; v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		// angle sort
		rep(u,n){
			int k=G[u].size();
			pair<double,int> A[100];
			rep(i,k){
				int v=G[u][i];
				A[i]=make_pair(arg(P[v]-P[u]),v);
			}
			sort(A,A+k);
			rep(i,k) G[u][i]=A[i].second;
		}

		// decompose to polygons
		vector< vector<int> > F; // set of polygons
		rep(u,n) rep(i,G[u].size()) F.push_back(reg(trace(G,u,i)));
		sort(F.begin(),F.end());
		F.erase(unique(F.begin(),F.end()),F.end());

		// find the outside boundary
		int n2=F.size(),u0=-1;
		rep(u,n2){
			int k=F[u].size();
			polygon H(k);
			rep(i,k) H[i]=P[F[u][i]];
			if(!is_ccw(H)){
				assert(u0==-1);
				u0=u;
			}
		}
		assert(u0!=-1);

		// build the dual graph
		vector<int> G2[300];
		rep(u,n2) rep(v,u) {
			bool ok=false;
			int nu=F[u].size(),nv=F[v].size();
			rep(i,nu) rep(j,nv) if(F[u][i]==F[v][(j+1)%nv] && F[u][(i+1)%nu]==F[v][j]) ok=true;
			if(ok){
				G2[u].push_back(v);
				G2[v].push_back(u);
			}
		}

		// BFS
		int d[300];
		rep(u,n2) d[u]=(u==u0?0:-1);
		queue<int> Q;
		Q.push(u0);
		while(!Q.empty()){
			int u=Q.front(); Q.pop();
			rep(i,G2[u].size()){
				int v=G2[u][i];
				if(d[v]==-1) d[v]=d[u]+1, Q.push(v);
			}
		}

		printf("%d\n",*max_element(d,d+n2));
	}

	return 0;
}