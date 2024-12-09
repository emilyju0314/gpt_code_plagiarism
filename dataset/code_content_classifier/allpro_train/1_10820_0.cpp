#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-5;

struct point{
	double x,y;
	point():x(0),y(0){}
	point(double x,double y):x(x),y(y){}
	point operator+(const point &a)const{ return point(x+a.x,y+a.y); }
	point operator-(const point &a)const{ return point(x-a.x,y-a.y); }
};

point operator*(double c,const point &a){ return point(c*a.x,c*a.y); }

bool operator< (const point &a,const point &b){ return a.x+EPS<b.x || abs(a.x-b.x)<EPS && a.y+EPS<b.y; }
bool operator==(const point &a,const point &b){ return abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS; }

double cross(const point &a,const point &b){ return a.x*b.y-a.y*b.x; }

struct line{ point a,b; };

bool cover(const line &L,const point &p){
	return abs(cross(L.a-p,L.b-p))<EPS;
}

bool intersect(const line &L1,const line &L2){
	return abs(cross(L1.b-L1.a,L2.b-L2.a))>EPS
		|| abs(cross(L1.b-L1.a,L2.a-L1.a))<EPS;
}

point get_intersect(const line &L1,const line &L2){
	double a1=cross(L1.b-L1.a,L2.b-L2.a);
	double a2=cross(L1.b-L1.a,L1.b-L2.a);
	if(abs(a1)<EPS) return L1.a;
	return L2.a+a2/a1*(L2.b-L2.a);
}

// 二次曲線 Ax^2+Bxy+Cy^2+Dx+Ey+F=0 と直線 ax+by+c=0 の交点を求める
int get_intersect(double A,double B,double C,double D,double E,double F,double a,double b,double c,vector<point> &res){
	if(abs(a)<EPS){
		vector<point> tmp;
		int cnt=get_intersect(C,B,A,E,D,F,b,a,c,tmp);
		rep(i,tmp.size()) res.push_back(point(tmp[i].y,tmp[i].x));
		return cnt;
	}

	double d=b/a,e=c/a;
	double P=A*d*d-B*d+C,Q=2*A*d*e-B*e-D*d+E,R=A*e*e-D*e+F;
	if(abs(P)<EPS){
		if(abs(Q)<EPS){
			return 0; // 交点は有限個だから R=0 はありえない
		}
		else{
			double y=-R/Q;
			res.push_back(point(-b/a*y-c/a,y));
			return 1;
		}
	}
	else{
		double G=Q*Q-4*P*R;
		if(G<-EPS){
			return 0;
		}
		else if(abs(G)<EPS){
			double y=-Q/(2*P);
			res.push_back(point(-b/a*y-c/a,y));
			return 1;
		}
		else{
			double y1=(-Q+sqrt(G))/(2*P);
			double y2=(-Q-sqrt(G))/(2*P);
			res.push_back(point(-b/a*y1-c/a,y1));
			res.push_back(point(-b/a*y2-c/a,y2));
			return 2;
		}
	}
}

// 二直線 a1*x+b1*y+c1=0 と a2*x+b2*y+c2=0 が同じものかどうか
bool equal(double a1,double b1,double c1,double a2,double b2,double c2){
	if(a1*b2!=a2*b1) return false; // 平行でない
	else if(a1!=0) return a1*c2==a2*c1;
	else           return b1*c2==b2*c1;
}

int main(){
	int n; scanf("%d",&n);
	double A,B,C,D,E,F,a[20],b[20],c[20];
	scanf("%lf%lf%lf%lf%lf%lf",&A,&B,&C,&D,&E,&F);
	rep(i,n) scanf("%lf%lf%lf",a+i,b+i,c+i);

	// 直線の重複を除去
	rep(i,n){
		bool same=false;
		rep(j,i) if(equal(a[i],b[i],c[i],a[j],b[j],c[j])) same=true;
		if(same){
			swap(a[i],a[n-1]);
			swap(b[i],b[n-1]);
			swap(c[i],c[n-1]);
			i--;
			n--;
		}
	}

	line L[20];
	rep(i,n){
		if(b[i]==0){
			L[i].b=point(-c[i]/a[i], 1);
			L[i].a=point(-c[i]/a[i],-1);
		}
		else{
			L[i].a=point( 1,-a[i]/b[i]-c[i]/b[i]);
			L[i].b=point(-1, a[i]/b[i]-c[i]/b[i]);
		}
	}

	vector<point> P; // 交点の全体
	rep(i,n){
		rep(j,i) if(intersect(L[i],L[j])) P.push_back(get_intersect(L[i],L[j]));
		get_intersect(A,B,C,D,E,F,a[i],b[i],c[i],P);
	}
	sort(P.begin(),P.end());
	P.erase(unique(P.begin(),P.end()),P.end());

	int vertex=P.size(),edge=0;
	rep(i,n){
		edge++;
		rep(j,P.size()) if(cover(L[i],P[j])) edge++;
	}
	bool isolated=true;
	rep(j,P.size()){
		double x=P[j].x,y=P[j].y;
		if(abs(A*x*x+B*x*y+C*y*y+D*x+E*y+F)<EPS) edge++, isolated=false;
	}
	if(B*B-4*A*C>0){ // 双曲線
		edge+=2;
	}
	else if(B*B-4*A*C==0){ // 放物線
		edge++;
	}
	else{ // 楕円
		if(isolated) edge++;
	}

	printf("%d\n",edge-vertex+1);

	return 0;
}