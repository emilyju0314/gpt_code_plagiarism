#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
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
pair<Pt,Pt> pCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).ABS();
	double x = (d * d + r * r - s * s) / (d * 2);
	Pt e = (b - a) / d, w = e * Pt(0, 1) * sqrt(max(r * r - x * x, 0.0));
	return make_pair(a + e * x - w, a + e * x + w);
}
pair<Pt,Pt> tCP(Pt a, double r, Pt b) {
	double d2 = (b - a).abs2();
	double x = sqrt(max(d2 - r * r, 0.0));
	Pt h = a + (b - a) * (r * r / d2);
	Pt w = (b - a) * Pt(0, 1) * (x * r / d2);
	return make_pair(h - w, h + w);
}
double dSP(Pt a, Pt b, Pt c) {
	if (sig((b - a).dot(c - a)) <= 0) return (c - a).ABS();
	if (sig((a - b).dot(c - b)) <= 0) return (c - b).ABS();
	return ABS(tri(a, b, c)) / (b - a).ABS();
}
int sAP(Pt a, Pt b, Pt c) {
	return sig(a.det(c)) - sig(b.det(c)) - sig(a.det(b));
}
vector<Pt> hb;
Pt c[10];
double ijk[11000];
int v[11000];
int main(){
	int a,gx,gy;
	scanf("%d%d%d",&a,&gx,&gy);
	Pt g=Pt((double)gx,(double)gy);
	hb.push_back(Pt(0,0));
	hb.push_back(g);
	for(int i=0;i<a;i++){
		double x,y;
		scanf("%lf%lf",&x,&y);
		c[i]=Pt(x,y);
	}
	for(int i=0;i<a;i++)for(int j=i+1;j<a;j++){
		if((c[i]-c[j]).ABS()<200.0){
			pair<Pt,Pt> it=pCC(c[i],100.0,c[j],100.0);
			hb.push_back(it.first);
			hb.push_back(it.second);
		}
	}
	int rn=hb.size();
	for(int i=0;i<rn;i++){
		for(int j=0;j<a;j++){
			if((hb[i]-c[j]).ABS()>100.0+EPS){
				pair<Pt,Pt> it=tCP(c[j],100.0,hb[i]);
				hb.push_back(it.first);
				hb.push_back(it.second);
			}
		}
	}
	for(int i=0;i<a;i++)for(int j=i+1;j<a;j++){
		Pt v=(c[j]-c[i])*100.0/((c[j]-c[i]).ABS())*Pt(0,1);
		hb.push_back(c[i]+v);
		hb.push_back(c[i]-v);
		hb.push_back(c[j]+v);
		hb.push_back(c[j]-v);
		if((c[i]-c[j]).ABS()>200.0){
			double th=asin(200.0/(c[i]-c[j]).ABS());
			hb.push_back(c[i]+v*Pt(cos(-th),sin(-th)));
			hb.push_back(c[i]-v*Pt(cos(th),sin(th)));
			hb.push_back(c[j]+v*Pt(cos(th),sin(th)));
			hb.push_back(c[j]-v*Pt(cos(-th),sin(-th)));
		}
	}
	int n=hb.size();
	for(int i=1;i<n;i++){
		ijk[i]=999999999.9;
	}
	for(int i=0;i<n;i++){
		double dist=9999999999.9;
		int at=0;
		for(int j=0;j<n;j++){
			if(!v[j]&&dist>ijk[j]){
				dist=ijk[j];at=j;
			}
		}
		v[at]=1;
		for(int j=0;j<n;j++){
			if(v[j]||ijk[j]<ijk[at]+(hb[at]-hb[j]).ABS())continue;
			bool ok=true;
			for(int k=0;k<a;k++){
				if(dSP(hb[at],hb[j],c[k])<100.0-EPS)ok=false;
			}
			if(ok){
				ijk[j]=ijk[at]+(hb[at]-hb[j]).ABS();
			}
		}
		int on=0;
		for(int j=0;j<a;j++){
			if(100.0-EPS<(c[j]-hb[at]).ABS()&&(c[j]-hb[at]).ABS()<100.0+EPS)on+=(1<<j);
		}
		for(int j=0;j<n;j++){
			if(v[j])continue;
			for(int k=0;k<a;k++){
				if(!(on&(1<<k)))continue;
				if(100.0-EPS>(c[k]-hb[j]).ABS()||(c[k]-hb[j]).ABS()>100.0+EPS)continue;
				bool ok1=true;
				bool ok2=true;
				for(int l=0;l<a;l++){
					if(k==l)continue;
					if((c[k]-c[l]).ABS()>200.0)continue;
					pair<Pt,Pt> tmp=pCC(c[k],100.0,c[l],100.0);
					if(sAP(hb[at]-c[k],hb[j]-c[k],tmp.first-c[k])>0)ok1=false;
					if(sAP(hb[j]-c[k],hb[at]-c[k],tmp.first-c[k])>0)ok2=false;
					if(sAP(hb[at]-c[k],hb[j]-c[k],tmp.second-c[k])>0)ok1=false;
					if(sAP(hb[j]-c[k],hb[at]-c[k],tmp.second-c[k])>0)ok2=false;
				//	if(i==1&&j==70&&l==1)printf("%f %f %f\n",(hb[at]-c[k]).arg(),(hb[j]-c[k]).arg(),(tmp.first-c[k]).arg());
				}
				
				if(ok1){
					double th=(hb[j]-c[k]).arg()-(hb[at]-c[k]).arg();
					if(th<0)th+=PI*2;
					Pt chk=c[k]+(hb[at]-c[k])*Pt(cos(th/2),sin(th/2));
					bool ok=true;
					for(int l=0;l<a;l++)if((chk-c[l]).ABS()<100.0-EPS)ok=false;
					if(ok){
			//			if(i==1)printf("%d (%f, %f) %d 1\n",at,hb[j].x,hb[j].y,k);
						ijk[j]=min(ijk[j],ijk[at]+100.0*th);
					}
				}
				if(ok2){
					double th=(hb[at]-c[k]).arg()-(hb[j]-c[k]).arg();
					if(th<0)th+=PI*2;
					Pt chk=c[k]+(hb[j]-c[k])*Pt(cos(th/2),sin(th/2));
					bool ok=true;
					for(int l=0;l<a;l++)if((chk-c[l]).ABS()<100.0-EPS)ok=false;
					if(ok){
				//		if(i==1)printf("%d (%f, %f) %d 2\n",at,hb[j].x,hb[j].y,k);
						ijk[j]=min(ijk[j],ijk[at]+100.0*th);
					}
				}
			}
		}
	//	if(i==1)for(int j=0;j<hb.size();j++)printf("(%f, %f): %f\n",hb[j].x,hb[j].y,ijk[j]);	
	}
	//for(int i=0;i<hb.size();i++)printf("(%f, %f): %f\n",hb[i].x,hb[i].y,ijk[i]);
	if(ijk[1]<99999999.9)printf("%.12f\n",ijk[1]);
	else printf("0.0\n");
}