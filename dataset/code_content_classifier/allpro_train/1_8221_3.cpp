#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1);
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
inline double ABS(double a){return max(a,-a);}
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
	if (sig((a - b).dot(c - b)) < 0) return +2; // a-b-c
	return 0;
}
int iLL(Pt a, Pt b, Pt c, Pt d) {
	if (sig((b - a).det(d - c))) return 1; // intersect
	if (sig((b - a).det(c - a))) return 0; // parallel
	return -1; // correspond
}
Pt pLL(Pt a, Pt b, Pt c, Pt d) {
	b = b - a; d = d - c; return a + b * (c - a).det(d) / b.det(d);
}
double dLP(Pt a, Pt b, Pt c) {
	return ABS(tri(a, b, c)) / (b - a).ABS();
}
int iCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).ABS();
	if (sig(d) == 0 && sig(r - s) == 0) return -1; // correspond
	if (sig(r - s - d) > 0) return +2; // r > s
	if (sig(s - r - d) > 0) return -2; // s > r
	return (sig(r + s - d) >= 0) ? 1 : 0;
}
pair<Pt,Pt> pCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).ABS();
	double x = (d * d + r * r - s * s) / (d * 2);
	Pt e = (b - a) / d, w = e * Pt(0, 1) * sqrt(max(r * r - x * x, 0.0));
	return make_pair(a + e * x - w, a + e * x + w);
}
pair<Pt,Pt> pCL(Pt a, double r, Pt b, Pt c) {
	Pt h = b + (c - b) * (c - b).dot(a - b) / (c - b).abs2(); // perp(b, c, a)
	double d = (h - a).ABS();
	double y = sqrt(max(r * r - d * d, 0.0));
	Pt e = (c - b) / (c - b).ABS();
	return make_pair(h - e * y, h + e * y);
}
Pt p[30];
double r[30];
double s[30];
double t[30];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int a;scanf("%d",&a);
		for(int i=0;i<a;i++){
			double x,y;
			scanf("%lf%lf%lf%lf%lf",&x,&y,r+i,s+i,t+i);
			s[i]=s[i]*PI/180;
			t[i]=t[i]*PI/180;
			p[i]=Pt(x,y);
		}
		vector<Pt>v;
		for(int i=0;i<a;i++)for(int j=i+1;j<a;j++){
			if(iCC(p[i],r[i],p[j],r[j])==1){
				pair<Pt,Pt>tmp=pCC(p[i],r[i],p[j],r[j]);
				v.push_back(tmp.first);
				v.push_back(tmp.second);
			}
			Pt p11=p[i]+Pt(cos(s[i]),sin(s[i]))*r[i];
			Pt p12=p[i]+Pt(cos(t[i]),sin(t[i]))*r[i];
			Pt p21=p[j]+Pt(cos(s[j]),sin(s[j]))*r[j];
			Pt p22=p[j]+Pt(cos(t[j]),sin(t[j]))*r[j];
			if(iLL(p[i],p11,p[j],p21)==1)v.push_back(pLL(p[i],p11,p[j],p21));
			if(iLL(p[i],p12,p[j],p21)==1)v.push_back(pLL(p[i],p12,p[j],p21));
			if(iLL(p[i],p11,p[j],p22)==1)v.push_back(pLL(p[i],p11,p[j],p22));
			if(iLL(p[i],p12,p[j],p22)==1)v.push_back(pLL(p[i],p12,p[j],p22));
			if(sig(dLP(p[i],p11,p[j])-r[j])<=0){
				pair<Pt,Pt>tmp=pCL(p[j],r[j],p[i],p11);
				v.push_back(tmp.first);v.push_back(tmp.second);
			}
			if(sig(dLP(p[i],p12,p[j])-r[j])<=0){
				pair<Pt,Pt>tmp=pCL(p[j],r[j],p[i],p12);
				v.push_back(tmp.first);v.push_back(tmp.second);
			}
			if(sig(dLP(p[j],p21,p[i])-r[i])<=0){
				pair<Pt,Pt>tmp=pCL(p[i],r[i],p[j],p21);
				v.push_back(tmp.first);v.push_back(tmp.second);
			}
			if(sig(dLP(p[j],p22,p[i])-r[i])<=0){
				pair<Pt,Pt>tmp=pCL(p[i],r[i],p[j],p22);
				v.push_back(tmp.first);v.push_back(tmp.second);
			}
		}
		for(int i=0;i<a;i++){
			v.push_back(p[i]);
			v.push_back(p[i]+Pt(cos(s[i]),sin(s[i]))*r[i]);
			v.push_back(p[i]+Pt(cos(t[i]),sin(t[i]))*r[i]);
		}
		int ret=0;
		for(int i=0;i<v.size();i++){
			int val=0;
			for(int j=0;j<a;j++){
				double dist=(v[i]-p[j]).ABS();
				if(dist>r[j]+EPS)continue;
				double th=(v[i]-p[j]).arg();
				if(sig(dist)==0){
					val++;continue;
				}
				if(th<0)th+=PI*2;
				if(s[j]>t[j]){
					if(t[j]+EPS<th&&th+EPS<s[j])continue;
				}else{
					if(th+EPS<s[j]||t[j]+EPS<th)continue;
				}
				val++;
			}
			ret=max(ret,val);
		}
		printf("%d\n",ret);
	}
}