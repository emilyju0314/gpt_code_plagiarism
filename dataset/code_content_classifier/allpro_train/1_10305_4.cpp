#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#define EPS (1e-10)

struct Point{
  double x,y;
  Point(){};
  Point(double x,double y):x(x),y(y){}
  Point operator+(Point p){return Point(x+p.x, y+p.y);}
  Point operator-(Point p){return Point(x-p.x, y-p.y);}
  Point operator*(double k){return Point(x*k,y*k);}
  Point operator/(double k){return Point(x/k,y/k);}
  double norm(){return x*x + y*y;}
  double abs(){return sqrt(norm());}
};

struct Segment{
  Point p1,p2;
  Segment(){};
  Segment(Point p1,Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;
typedef vector<Point> Polygon;

typedef Point Vector;
double dot(Vector a,Vector b){return a.x * b.x + a.y * b.y;}
double cross(Vector a,Vector b){return a.x * b.y - a.y * b.x;}
double norm(Vector a){return a.x * a.x + a.y * a.y;}
double abs(Vector a){return sqrt(norm(a));}

double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double getDistanceSP(Segment s,Point p){
  if(dot(s.p2 - s.p1, p-s.p1) < 0.0) return abs(p-s.p1);
  if(dot(s.p1 - s.p2, p-s.p2) < 0.0) return abs(p-s.p2);
  return getDistanceLP(s,p);
}

istream& operator>>(istream &is,Point& p){
  is>>p.x>>p.y;
  return is;
}

signed main(){  
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n;
  cin>>n;
  vector<Polygon> s(2,Polygon(n));
  double r[n];
  for(Int i=0;i<n;i++){
    cin>>r[i]>>s[0][i]>>s[1][i];
  }
  vector<Int> dp(1<<16,0);
  dp[0]=1;
  Int ans=0;
  for(Int b=0;b<(1<<n);b++){
    if(!dp[b]) continue;
    //cout<<b<<endl;
    ans=max(ans,Int(__builtin_popcount(b)));
    for(Int i=0;i<n;i++){
      if((b>>i)&1) continue;
      bool f=1;
      for(Int j=0;j<n;j++){
	if(i==j) continue;
	double d=getDistanceSP(Segment(s[0][i],s[1][i]),s[(b>>j)&1][j]);
	if(0){
	  cout<<i<<" "<<j<<":"<<r[i]+r[j]<<" "<<d<<endl;
	  cout<<s[0][i].x<<" "<<s[0][i].y<<endl;
	  cout<<s[1][i].x<<" "<<s[1][i].y<<endl;
	  cout<<s[0][j].x<<" "<<s[0][j].y<<endl;
	  cout<<s[1][j].x<<" "<<s[1][j].y<<endl;
	}
	f&=(r[i]+r[j]<d+EPS);
      }
      Int nb=b|(1<<i);
      dp[nb]|=f;
    }
  }
  cout<<ans<<endl;
  return 0;
}

