#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef complex<double> pt;
typedef pair<pt,pt> L;
typedef vector<P> poly;
const double EPS = 1e-9;
#define x real()
#define y imag()
bool eq(double a,double b){
  return (-EPS < a-b && a-b < EPS);
}
double dot(pt a,pt b){
	return (conj(a)*b).x;
}
double cross(pt a,pt b){
	return (conj(a)*b).y;
}
int ccw(pt a,pt b,pt c){
	b -= a; c -= a;
	if(cross(b,c) > EPS) return 1; // counter clockwise
	if(cross(b,c) < -EPS) return -1; // clockwise
	if(dot(b,c) < -EPS) return 2; //c-a-b
	if(norm(b) < norm(c)) return -2; //a-b-c
	return 0; //a-c-b
}
bool cmp(const pt& a,const pt& b){
	if(-EPS < a.x-b.x && a.x-b.x < EPS) return a.y < b.y;
	else return a.x < b.x;
}
bool on_segment(pair<pt,pt> a,pt p){
  return eq(abs(a.first-a.second)-abs(a.first-p)-abs(a.second-p),0);
}
vector<pt>convex_hull(vector<pt>ps){
	sort(ps.begin(),ps.end(),cmp);
	int k=0,n = ps.size();
	vector<pt>qs(n*2);
	for(int i=0;i<n;i++)
	{
		while(k>1 && ccw(qs[k-2],qs[k-1],ps[i]) == -1) k--;
		qs[k++] = ps[i];
	}
	for(int i=n-2,t=k;i>=0;i--)
	{
		while(k>t && ccw(qs[k-2],qs[k-1],ps[i]) == -1) k--;
		qs[k++] = ps[i];
	}
	qs.resize(k-1);
	return qs;
}
bool contain_point(vector<pt>ps,pt p){
	double sum = 0;
	//arg no sum wo keisan
	for(int i=0;i<ps.size();i++){
		if(on_segment(mp(ps[i],ps[ (i+1)%ps.size() ]),p)) return 1;
		sum += arg( (ps[ (i+1)%ps.size() ]-p) / (ps[i]-p) );
	}
	return (abs(sum) > 1);
}
bool intersect(pt a,pt b,pt c,pt d){
	return (ccw(a,b,c)*ccw(a,b,d) <= 0 && ccw(c,d,a)*ccw(c,d,b) <= 0);
}
int n,m;
int main(){
	while(1){
		cin >> n >> m; if(!n) return 0;
		vector<pt>A,B;
		for(int i=0;i<n;i++){
			double xx,yy; scanf("%lf%lf",&xx,&yy);
			A.pb(pt(xx,yy));
		}
		for(int i=0;i<m;i++){
			double xx,yy; scanf("%lf%lf",&xx,&yy);
			B.pb(pt(xx,yy));
		}
		if(A.size() >= 3) A = convex_hull(A);
		if(B.size() >= 3) B = convex_hull(B);
		bool ok = 1;
		rep(i,A.size()){
			if(contain_point(B,A[i])) ok = 0;
		}
		rep(i,B.size()){
			if(contain_point(A,B[i])) ok = 0;
		}
		if(A.size()>=2 && B.size()>=2){
    		rep(i,A.size()){
    		    rep(j,B.size()){
    		        if(intersect(A[i],A[(i+1)%A.size()],B[j],B[(j+1)%B.size()])) ok = 0;
    		    }
    		}
		}
		puts(ok?"YES":"NO");
	}
}