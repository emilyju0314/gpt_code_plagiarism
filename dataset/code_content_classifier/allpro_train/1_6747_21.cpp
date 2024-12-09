#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1);
double ABS(double a){return max(a,-a);}
	int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
	struct Pt {
	   double x, y;
Pt() {}
     Pt(double x, double y) : x(x), y(y) {}
     Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
     Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
     Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
     Pt operator-() const { return Pt(-x, -y); }
     Pt operator*(const double &k) const { return Pt(x * k, y * k); }
     Pt operator/(const double &k) const { return Pt(x / k, y / k); }
     double ABS() const { return sqrt(x * x + y * y); }
     double abs2() const { return x * x + y * y; }
     double arg() const { return atan2(y, x); }
     double dot(const Pt &a) const { return x * a.x + y * a.y; }
     double det(const Pt &a) const { return x * a.y - y * a.x; }
 };
double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }
int iSP(Pt a, Pt b, Pt c) {
    int s = sig((b - a).det(c - a));
    if (s) return s;
    if (sig((b - a).dot(c - a)) < 0) return -2; // c-a-b
    if (sig((a - b).dot(c - b)) < 0) return +2; //   a-b-c
return 0;
}
int iLL(Pt a, Pt b, Pt c, Pt d) {
    if (sig((b - a).det(d - c))) return 1;  // intersect
    if (sig((b - a).det(c - a))) return 0;  // parallel
    return -1;  // correspond
}
bool iLS(Pt a, Pt b, Pt c, Pt d) {
    return (sig(tri(a, b, c)) * sig(tri(a, b, d)) <= 0);
}
bool iSS(Pt a, Pt b, Pt c, Pt d) {
    return (iSP(a, b, c) * iSP(a, b, d) <= 0 && iSP(c, d, a) * iSP(c, d, b) <= 0);
}
bool iSSstrict(Pt a, Pt b, Pt c, Pt d) {
    return (sig(tri(a, b, c)) * sig(tri(a, b, d)) < 0 && sig(tri(c, d, a)) * sig(tri(c, d, b)) < 0);
}
Pt pLL(Pt a, Pt b, Pt c, Pt d) {
    b = b - a; d = d - c; return a + b * (c - a).det(d) / b.det(d);
}
double dLP(Pt a, Pt b, Pt c) {
    return ABS(tri(a, b, c)) / (b - a).ABS();
}
double dSP(Pt a, Pt b, Pt c) {
    if (sig((b - a).dot(c - a)) <= 0) return (c - a).ABS();
    if (sig((a - b).dot(c - b)) <= 0) return (c - b).ABS();
    return ABS(tri(a, b, c)) / (b - a).ABS();
}
double dLL(Pt a, Pt b, Pt c, Pt d) {
    return iLL(a, b, c, d) ? 0 : dLP(a, b, c);
}
double dLS(Pt a, Pt b, Pt c, Pt d) {
    return iLS(a, b, c, d) ? 0 : min(dLP(a, b, c), dLP(a, b, d));
}
double dSS(Pt a, Pt b, Pt c, Pt d) {
    return iSS(a, b, c, d) ? 0 : min(min(dSP(a, b, c), dSP(a, b, d)), min(dSP(c, d, a), dSP(c, d, b)));
}
Pt L[110];
Pt R[110];
Pt vec[110];
double t[110];
int main(){
	int W,H,N;
	double r;
	while(scanf("%d%d%d%lf",&W,&H,&N,&r),W){
		for(int i=0;i<N;i++){
			double X1,X2,Y1,Y2;
			scanf("%lf%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2,t+i);
			L[i]=Pt(X1,Y1);
			R[i]=Pt(X2,Y2);
			vec[i]=(R[i]-L[i])*Pt(0,1);
			vec[i]=vec[i]/(vec[i].ABS())*(t[i]+r);
		}
		vector<Pt> hb;
		hb.push_back(Pt(r,r));
		hb.push_back(Pt(W-r,r));
		hb.push_back(Pt(r,H-r));
		hb.push_back(Pt(W-r,H-r));
		vector<pair<Pt,Pt> > lines;
		for(int i=0;i<N;i++){
			lines.push_back(make_pair(L[i]+vec[i],R[i]+vec[i]));
			lines.push_back(make_pair(L[i]-vec[i],R[i]-vec[i]));
		}
		lines.push_back(make_pair(hb[0],hb[1]));
		lines.push_back(make_pair(hb[0],hb[2]));
		lines.push_back(make_pair(hb[3],hb[1]));
		lines.push_back(make_pair(hb[3],hb[2]));
		for(int i=0;i<lines.size();i++)for(int j=i+1;j<lines.size();j++){
			if(iLL(lines[i].first,lines[i].second,lines[j].first,lines[j].second)!=1)continue;
			Pt p=pLL(lines[i].first,lines[i].second,lines[j].first,lines[j].second);
			if(r-EPS<p.x&&p.x<EPS+W-r&&r-EPS<p.y&&p.y<EPS+H-r)hb.push_back(p);
		}
		bool ok=false;
	//	printf("%d ",hb.size());
		for(int i=0;i<hb.size();i++){
			bool OK=true;
			for(int j=0;j<N;j++){
				if(dLP(L[j],R[j],hb[i])<t[j]+r-EPS)OK=false;
			}
			if(OK)ok=true;
		}
		if(ok)printf("Yes\n");
		else printf("No\n");
	}
}