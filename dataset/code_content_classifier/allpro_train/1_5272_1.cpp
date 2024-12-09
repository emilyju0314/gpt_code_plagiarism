#include<cstdio>
#include<complex>
#include<vector>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef double Real;

typedef complex<Real> Point;
typedef complex<Real> Vector;
typedef pair<Point,Point> Segment;
typedef vector<Point> Polygon;

const Real eps=1e-9;

template<class T> bool eq(T a,T b){
	return abs(a-b)<eps;
}
template<class T> int sgn(T a){
	if(eq(a,0.0)) return 0;
	if(a>0) return 1;
	return -1;
}

struct Circle{
	Point center;
	Real r;
	Point a,b;
	Circle(){}
	Circle(Point p,Real r):center(p),r(r){}
	Circle(Point p,Real r,Point a,Point b):center(p),r(r),a(a),b(b){}
};

Real crP(Vector a,Vector b){
	return (conj(a)*b).imag();
}

string strs[110];
Point pts[110];
Real rs[110];
int N;
Point cs[110];

int T;

vector<Segment> segs;
vector<Circle> circles;

struct MassPoint{
	Real area;
	Point p;
	MassPoint(){}
	MassPoint(Point p,Real a):p(p),area(a){}
};

vector<MassPoint> vec;

Point G;

void output(Point p,char ch){
	printf("(%f,%f)%c",p.real(),p.imag(),ch);
}

void solve(){
	circles.clear();
	vec.clear();
	for(int i=0;;i++){
		//if(strs[i]!="close") printf("%d %f %f\n",i,pts[i].real(),pts[i].imag());
		if(strs[i]=="close"){
			Real a=crP(pts[i-1],pts[0])/2;
			Point p=(pts[i-1]+pts[0])/3.0;
			vec.push_back(MassPoint(p,a));
			break;
		}else if(strs[i]=="line"){
			Real a=crP(pts[i-1],pts[i])/2;
			Point p=(pts[i-1]+pts[i])/3.0;
			vec.push_back(MassPoint(p,a));
		//	if(T==2)output(p,'\n');
		}else if(strs[i]=="arc"){
			Real a=crP(pts[i-1],pts[i])/2;
			Point p=(pts[i-1]+pts[i])/3.0;
			vec.push_back(MassPoint(p,a));
			Real d=abs(pts[i-1]-pts[i]);
			Real r=abs(rs[i]);
			Real theta=asin((d/2.0)/r);
			Real area=r*r*(theta*2-sin(theta*2))/2;
			Vector v=pts[i]-pts[i-1];
			if(rs[i]>0){
				Vector v2=v*Vector(0,-1);
				v2/=(abs(v2));
				Point center=(pts[i]+pts[i-1])/2.0;
				center+=v2*r*cos(theta);
				circles.push_back(Circle(center,r,pts[i],pts[i-1]));
				cs[i]=center;
				Real y=2*r*r*r*sin(theta)*sin(theta)*sin(theta)/(3.0*area);
				Point g=center-y*v2;
				vec.push_back(MassPoint(g,-area));
		//		if(T==2)output(g,'\n');
			}else{
				Vector v2=v*Vector(0,1);
				v2/=abs(v2);
				Point center=(pts[i]+pts[i-1])/2.0;
				center+=v2*r*cos(theta);
				cs[i]=center;
				circles.push_back(Circle(center,r,pts[i-1],pts[i]));
				Real y=2*r*r*r*sin(theta)*sin(theta)*sin(theta)/(3.0*area);
				Point g=center-y*v2;
				vec.push_back(MassPoint(g,area));
		//		if(T==2)output(g,'\n');
			}
		}
	}
	Point num=Point(0,0);
	Real den=0;
	for(int i=0;i<vec.size();i++){
		num+=vec[i].p*vec[i].area;
		den+=vec[i].area;
	//	printf("(%f,%f) %f\n",vec[i].p.real(),vec[i].p.imag(),vec[i].area);
	}
	G=num/den;
	printf("%f %f",G.real(),G.imag());
}

bool isin(Polygon poly,Point pt){/*ONは判定してない*/
	bool in=false;
	for(int i=0;i<poly.size();i++){
		Point a=poly[i],b=poly[(i+1)%poly.size()];
		a-=pt,b-=pt;
		if(a.imag()>b.imag()) swap(a,b);
		if(sgn(a.imag())<=0&&sgn(b.imag())>0){
			if(sgn(crP(a,b))<0){
				in=!in;
			}
		}
	}
	return in;
}

Real getAng(Vector v){
	return atan2(v.imag(),v.real());
}

bool check(){
	Polygon poly;
	for(int i=0;;i++){
		if(strs[i]!="close") poly.push_back(pts[i]);
		else break;
	}
	bool in=isin(poly,G);
	for(int i=0;i<circles.size();i++){
		Circle c=circles[i];
		Point a=c.a-c.center;
		Point b=c.b-c.center;
		Point g=G-c.center;
		a/=c.r;b/=c.r;g/=c.r;
		b*=conj(a),g*=conj(a);
		a*=conj(a);
		if(getAng(g)<0||getAng(g)>getAng(b)) continue;
		if(abs(g)>1.0) continue;
		Polygon tmp;
		tmp.push_back(Point(0,0));
		tmp.push_back(a);
		tmp.push_back(b);
		if(isin(tmp,g)) continue;
		in=!in;
	}
	if(in) printf(" +\n");
	else printf(" -\n");
	return in;
}

int main(){
	while(true){
		for(int i=0;;i++){
			cin>>strs[i];
			if(strs[i]=="arc"){
				Real x,y;
				cin>>x>>y>>rs[i];
				pts[i]=Point(x,y);
			}else if(strs[i]=="line"||strs[i]=="start"){
				Real x,y;
				cin>>x>>y;
				pts[i]=Point(x,y);
			}else if(strs[i]=="close"){
				break;
			}else{
				return 0;
			}
		}
		solve();
		check();
	}
	return 0;
}