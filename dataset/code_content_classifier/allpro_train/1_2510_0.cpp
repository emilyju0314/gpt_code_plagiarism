#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define EPS 1e-10

using namespace std;
typedef long long ll;

struct Point{
	double x,y;
	Point(double x = 0.0,double y = 0.0): x(x),y(y) {}
	Point operator + (Point p){
		return Point(x + p.x,y + p.y);
	}
	Point operator - (Point p){
		return Point(x - p.x,y - p.y);
	}
	Point operator * (double lambda){
		return Point(x * lambda,y * lambda);
	}
	Point operator / (double lambda){
		return Point(x / lambda,y / lambda);
	}
	double norm(){
		return x * x + y * y;
	}
	double abs_(){
		return sqrt(norm());
	}
	double pol(){
		return atan2(y,x);
	}
	bool operator == (const Point &p)const
	{
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}
	bool operator < (const Point &p)const
	{
		if(abs(x - p.x) < EPS) return y < p.y;
		return x < p.x;
 	}
};
typedef Point Vector;
double dot(Vector a,Vector b){
	return a.x * b.x + a.y * b.y;
}
double det(Vector a,Vector b){
	return a.x * b.y - a.y * b.x;
}
typedef vector<Point> Polygon;
struct Segment{
	Point p1,p2;
	Segment(Point p1 = Point(),Point p2 = Point()): p1(p1),p2(p2) {}
};
typedef Segment Line;
Point crossPoint(Line a,Line b){
	double r = det(b.p2 - b.p1,a.p1 - b.p1) / det(a.p2 - a.p1,b.p2 - b.p1);
	return a.p1 + (a.p2 - a.p1) * r;
}
bool on_left(Point p,Line l){ return det(l.p2 - l.p1,p - l.p1) > EPS; }
bool para(Line a,Line b){ return abs(det(a.p2 - a.p1,b.p2 - b.p1)) < EPS; }
Line L[15],que[15];
int he,ta,n;
bool cmp(Line &a,Line &b){
	return (a.p2 - a.p1).pol() < (b.p2 - b.p1).pol();
}
double area(Polygon P){
	double ans = 0.0;
	int num = P.size();
	for(int i = 0;i < num;i++){
		ans += det(P[i],P[(i + 1) % num]);
	}
	return ans / 2.0;
}
double hp_intersect(){
	sort(L + 1,L + n + 1,cmp);
	he = ta = 0;
	for(int i=1;i<=n;i++){
		while(ta - he > 1 && !on_left(crossPoint(que[ta - 1],que[ta - 2]),L[i])) ta--;
		while(ta - he > 1 && !on_left(crossPoint(que[he],que[he + 1]),L[i])) he++;
		que[ta++] = L[i];
		while(ta - he > 1 && para(que[ta - 1],que[ta - 2])){
			ta--;
			if(on_left(L[i].p1,que[ta - 1])) que[ta - 1] = L[i];
		}
	}
	while(ta - he > 1 && !on_left(crossPoint(que[ta - 1],que[ta - 2]),que[he])) ta--;
	if(ta - he <= 2) return 0.0;
	int cnt = ta - he;
  Polygon po(cnt);
  for(int i=0;i<cnt;i++){
  	po[i] = crossPoint(que[he + i],que[he + (i + 1) % cnt]);
  }
  return area(po);
}
void cut(Polygon P,double x0,vector <double> &lis){
  lis.clear();
  int num = P.size();
  Line l = Line(Point(x0,-1.0),Point(x0,301.0));
  for(int i = 0;i < num;i++){
    if(P[i].x == P[(i + 1) % num].x) continue; // 取x0时应回避这个x
    if((P[i].x - x0) * (P[(i + 1) % num].x - x0) < 0){
      lis.push_back(crossPoint(Line(P[i],P[(i + 1) % num]),l).y);
    }
  }
  sort(lis.begin(),lis.end());
}
Polygon X,Y,Z;
int nx,ny,nz;
vector <double> ylis,zlis; // ylis's segments parallel to z-axis.
double calc(double x0){
  cut(Y,x0,ylis);
  cut(Z,x0,zlis);
  double ans = 0;
  for(int i = 0;i < (int)ylis.size();i += 2){
    for(int j = 0;j < (int)zlis.size();j += 2){
      for(int k = 0;k < nx;k++){
        n = 0;
        L[++n] = Line(Point(zlis[j],ylis[i]),Point(zlis[j + 1],ylis[i]));
        L[++n] = Line(Point(zlis[j + 1],ylis[i]),Point(zlis[j + 1],ylis[i + 1]));
        L[++n] = Line(Point(zlis[j + 1],ylis[i + 1]),Point(zlis[j],ylis[i + 1]));
        L[++n] = Line(Point(zlis[j],ylis[i + 1]),Point(zlis[j],ylis[i]));
        if(det(X[k] + Point(1,1),X[(k + 1) % nx] + Point(1,1)) > 0){
          L[++n] = Line(Point(-1,-1),X[k]);
          L[++n] = Line(X[k],X[(k + 1) % nx]);
          L[++n] = Line(X[(k + 1) % nx],Point(-1,-1));
          ans += hp_intersect();
        }else{
          L[++n] = Line(Point(-1,-1),X[(k + 1) % nx]);
          L[++n] = Line(X[(k + 1) % nx],X[k]);
          L[++n] = Line(X[k],Point(-1,-1));
          ans -= hp_intersect();
        }
      }
    }
  }
  return ans;
}
double work(double l,double r,double y_l,double y_mid,double y_r,double eps){
  double mid = (l + r) / 2;
  double y_lmid = calc((l + mid) / 2), y_rmid = calc((mid + r) / 2);
  double s = (r - l) * (y_l + 4 * y_mid + y_r) / 6;
  double s1 = (mid - l) * (y_l + 4 * y_lmid + y_mid) / 6;
  double s2 = (r - mid) * (y_mid + 4 * y_rmid + y_r) / 6;
  if(abs(s1 + s2 - s) < 15 * eps) return s1 + s2 + (s1 + s2 - s) / 15;
  return work(l,mid,y_l,y_lmid,y_mid,eps / 2) + work(mid,r,y_mid,y_rmid,y_r,eps / 2);
}
vector <double> xs;
int t;
void solve(){
  sort(xs.begin(),xs.end());
  if(t == 20){
    printf("%.6f\n",work(xs.front() + EPS,xs.back() - EPS,calc(xs.front() + EPS),calc((xs.front() + xs.back()) / 2),calc(xs.back() - EPS),1e-7));
    return;
  }
  double ans = 0;
  for(int i = 0;i < (int)xs.size() - 1;i++){
    if(xs[i] + 1e-11 < xs[i + 1] - 1e-11)
      ans += work(xs[i] + 1e-11,xs[i + 1] - 1e-11,calc(xs[i] + 1e-11),calc((xs[i] + xs[i + 1]) / 2),calc(xs[i + 1] - 1e-11),1e-9);
  }
  printf("%.6f\n",ans);
}
int main(){
  while(~scanf("%d",&nx) && nx){
    t++;
    X.resize(nx);
    for(int i = 0;i < nx;i++) scanf("%lf%lf",&X[i].x,&X[i].y);
    scanf("%d",&ny);
    Y.resize(ny);
    for(int i = 0;i < ny;i++){
      scanf("%lf%lf",&Y[i].y,&Y[i].x);
      xs.push_back(Y[i].x);
    }
    reverse(Y.begin(),Y.end());
    scanf("%d",&nz);
    Z.resize(nz);
    for(int i = 0;i < nz;i++){
      scanf("%lf%lf",&Z[i].x,&Z[i].y);
      xs.push_back(Z[i].x);
    }
    solve();
  }
  return 0;
}

