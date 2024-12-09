#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
#define inf 1e9
#define EPS 1e-10

struct point{
	double x,y;
	point(){}
	point(double x,double y) :x(x),y(y){}

	point operator - (point p) {return point(x-p.x,y-p.y); }
	void make() { cin>>x>>y;}
	double norm() { return x*x+y*y; }
};

double dot(point a,point b){return a.x*b.x + a.y*b.y; }
double cross(point a,point b){ return a.x*b.y - a.y*b.x ;}

typedef vector<point> polygon;
int contain(polygon g,point p){
	int n = g.size();
	bool f = false;
	for(int i=0;i<n;i++){
		point a = g[i]-p,b = g[(i+1)%n]-p;
		if( fabs(cross(a,b) ) < EPS && dot(a,b) <EPS)return 1;
		if( a.y > b.y )swap(a,b);
		if( a.y < EPS && EPS < b.y && cross(a,b) >EPS) f = !f;
	}
	return (f?2:0);
// iN 2 ON 1OUT 0
}
static const int CCW_COUNTER_CLOCKWISE = 1;
static const int CCW_CLOCKWISE = -1;
static const int CCW_ONLINE_BACK = 2;
static const int CCW_ONLINE_FRONT = -2;
static const int CCW_ON_SEGMENT = 0;
int ccw(point p0,point p1,point p2){
	point a = p1-p0,b = p2-p0;
	if(cross(a,b) > EPS) return 1;
	if(cross(a,b) < -EPS) return -1;
	if(dot(a,b) < -EPS ) return 2;
	if(a.norm() < b.norm() ) return -2;
	return 0;
}
bool intersect(point a,point b,point c,point d){
	return ( ccw(a,b,c)*ccw(a,b,d) <= 0 && ccw(c,d,a)*ccw(c,d,b) <= 0 );
}
struct  disjointset{
	vector<int> rank,p;
	disjointset(){}
	disjointset(int size){
		rank.resize(size,0);
		p.resize(size,0);
		for(int i=0;i<size;i++)makeSet(i);
	}
	void makeSet(int x){
		p[x] = x;
		rank[x] = 0;
	}
	bool same(int x,int y){
		return findSet(x) == findSet(y);
	}
	void unite(int x,int y){
		link(findSet(x),findSet(y) );
	}
	void link(int x,int y){
		if(rank[x] > rank[y]){
			p[y] = x;
		}else{	
			p[x] = y;
			if(rank[x] == rank[y] ) rank[y]++;
		}
	}
	int findSet(int x){
		if(x!=p[x]) p[x] = findSet(p[x]);
		return p[x];
	}

};

int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0)break;
		for(int k=0;k<n;k++){
		    	int m;
			cin>>m;
			vector<polygon> g(m,vector<point>(4,point(0,0)) );
			for(int i=0;i<m;i++)for(int j=0;j<4;j++) g[i][j].make();
		/*	for(int i=0;i<m;i++){
				for(int j=0;j<4;j++){
					cout<<g[i][j].x<<' '<<g[i][j].y;
				}
				cout<<endl;
			}*/
			disjointset ds = disjointset(m);
			for(int i=0;i<m;i++){
			    	polygon p = g[i];
				for(int j=0;j<m;j++){
				    	bool flag = false;
					for(int k=0;k<4;k++){
						if( contain(g[j],p[k])!=0 ){
							flag = true;
							break;
							//cout<<"ok"<<endl;
						}
					}
					for(int k =0 ;k<4;k++){
						for(int l = 0;l<4;l++){
							if(intersect(p[k],p[(k+1)%4],g[j][l],g[j][(l+1)%4] ) ){
								flag = true;
								break;
							}
						}
					}
					if(flag){
					    ds.unite(i,j);
					}
				}
			}
			int res = 0;
			for(int i=0;i<m;i++) if(ds.p[i] == i) res++;
			cout<<res<<endl;
		}
	}
	return 0;
}

