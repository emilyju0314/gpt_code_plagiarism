#include <bits/stdc++.h>
#define MOD 1000000007LL
#define EPS 1e-10
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<long double,int> DP;

long double add(long double a,long double b){
	if(abs(a+b)<EPS*(abs(a)+abs(b)))return 0.0;
	return a+b;
}

class Point{
public:
	long double x,y;
	Point(){}
	Point(long double xx,long double yy){
		x=xx;
		y=yy;
	}
	Point operator +(Point p){
		return Point(x+p.x,y+p.y);
	}
	Point operator -(Point p){
		return Point(x-p.x,y-p.y);
	}
	Point operator *(long double a){
		return Point(a*x,a*y);
	}
	Point operator /(long double a){
		return Point(x/a,y/a);
	}
	long double abs(){
		return sqrt(norm());
	}

	long double norm(){
		return x*x+y*y;
	}
};

typedef Point Vector;
struct Segment{
	Point p1,p2;
	Segment(){}
	Segment(Point pp1,Point pp2){
		p1=pp1;
		p2=pp2;
	}
};

typedef Segment Line;

long double norm(Vector v){
	return v.x*v.x+v.y*v.y;
}

long double abs(Vector v){
	return sqrt(norm(v));
}

long double dot(Vector a,Vector b){
	return a.x*b.x+a.y*b.y;
}

long double cross(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;
}

long double getDistance(Point a,Point b){
	return abs(a-b);
}

long double getDistanceLP(Line l,Point p){
	return abs(cross(l.p2-l.p1,p-l.p1))/abs(l.p2-l.p1);
}

long double getDistanceSP(Segment s,Point p){
	if(dot(s.p2-s.p1,p-s.p1)<0.0)return abs(p-s.p1);
	if(dot(s.p1-s.p2,p-s.p2)<0.0)return abs(p-s.p2);
	return getDistanceLP(s,p);
}

int n;
Point s,e;
vector<int> G[105];
long double r[105];
int siz[105];
vector<Point> vp[105];
bool used[105];

void dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		int nv=G[v][i];
		if(!used[nv])dfs(nv);
	}
}

long double C(long double sec,Vector a,Vector d){
	a=a+d*sec;
	return abs(a);
}

bool check(int a,int b){
	long double lena=0;
	long double lenb=0;
	for(int i=0;i<siz[a];i++){
		lena+=abs(vp[a][i]-vp[a][(i+1)%siz[a]]);
	}
	for(int i=0;i<siz[b];i++){
		lenb+=abs(vp[b][i]-vp[b][(i+1)%siz[b]]);
	}
	vector<DP> ch;
	Point diff=vp[a][0]-vp[b][0];
	if(abs(diff)<=r[a]+r[b])return true;
	long double cur=0;
	for(int i=0;i<siz[a];i++){
		cur+=abs(vp[a][i]-vp[a][(i+1)%siz[a]]);
		ch.push_back(DP(cur/lena,0));
	}
	cur=0;
	for(int i=0;i<siz[b];i++){
		cur+=abs(vp[b][i]-vp[b][(i+1)%siz[b]]);
		ch.push_back(DP(cur/lenb,1));
	}
	sort(ch.begin(),ch.end());
	int pa=0,pb=0;
	long double prev=0.0;
	for(int i=0;i<ch.size();i++){
		Vector di=(vp[a][(pa+1)%siz[a]]-vp[a][pa])/abs(vp[a][pa]-vp[a][(pa+1)%siz[a]])*lena;
		di=di-(vp[b][(pb+1)%siz[b]]-vp[b][pb])/abs(vp[b][pb]-vp[b][(pb+1)%siz[b]])*lenb;
		long double vl=0.0;
		long double vr=ch[i].first-prev;
		for(int k=0;k<100;k++){
			long double midl=(vl*2.0+vr)/3;
			long double midr=(vl+vr*2.0)/3;
			if(C(midl,diff,di)<C(midr,diff,di)){
				vr=midr;
			}else{
				vl=midl;
			}
		}
		if(C(vl,diff,di)<=r[a]+r[b])return true;
		if(abs(di*(ch[i].first-prev))>EPS)diff=diff+di*(ch[i].first-prev);
		if(ch[i].second==0){
			pa=(pa+1)%siz[a];
		}else{
			pb=(pb+1)%siz[b];
		}
		prev=ch[i].first;
	}
	return false;
}

int main(void){
	double aa,bb,cc,dd;
	scanf("%d%lf%lf%lf%lf",&n,&aa,&bb,&cc,&dd);
	s.x=aa;
	s.y=bb;
	e.x=cc;
	e.y=dd;
	for(int i=0;i<n;i++){
		scanf("%lf%d",&aa,&siz[i]);
		r[i]=aa;
		for(int j=0;j<siz[i];j++){
			Point p;
			scanf("%lf%lf",&aa,&bb);
			p.x=aa;
			p.y=bb;
			vp[i].push_back(p);
		}
	}
	for(int i=0;i<n;i++){
		bool flag=false;
		for(int j=0;j<siz[i];j++){
			if(getDistanceSP(Segment(vp[i][j],vp[i][(j+1)%siz[i]]),s)<=r[i])flag=true;
		}
		if(flag)G[n].push_back(i);
	}
	for(int i=0;i<n;i++){
		bool flag=false;
		for(int j=0;j<siz[i];j++){
			if(getDistanceSP(Segment(vp[i][j],vp[i][(j+1)%siz[i]]),e)<=r[i])flag=true;
		}
		if(flag)G[i].push_back(n+1);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(check(i,j)){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	dfs(n);
	printf("%s\n",used[n+1]?"Yes":"No");
	return 0;
} 

