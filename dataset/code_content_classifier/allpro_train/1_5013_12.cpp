#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-8) 
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

class Point{
public:
  double x,y;

  Point(double x = 0,double y = 0): x(x),y(y){}

  Point operator + (Point p){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (double a){return Point(a*x,a*y);}
  Point operator / (double a){return Point(x/a,y/a);}
  Point operator * (Point a){ return Point(x * a.x - y * a.y, x * a.y + y * a.x); }

  bool operator < (const Point& p) const{ return !equals(x,p.x)?x<p.x:(!equals(y,p.y)&&y<p.y); }

  bool operator == (const Point& p)const{ return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS; }

};

struct Segment{
  Point p1,p2;
  Segment(Point p1 = Point(),Point p2 = Point()):p1(p1),p2(p2){}
 bool operator == (const Segment& p)const { return ( p.p1 == p1 && p.p2 == p2 ) || ( p.p1 == p2 && p.p2 == p1 ); }
};

typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;

ostream& operator << (ostream& os,const Point& a){ os << "(" << a.x << "," << a.y << ")"; }

ostream& operator << (ostream& os,const Segment& a){ os << "( " << a.p1 << " , " << a.p2 << " )"; }

double dot(Point a,Point b){ return a.x*b.x + a.y*b.y; }

double cross(Point a,Point b){ return a.x*b.y - a.y*b.x; }

double norm(Point a){ return a.x*a.x+a.y*a.y; }

double abs(Point a){ return sqrt(norm(a)); }

//rad は角度をラジアンで持たせること
Point rotate(Point a,double rad){ return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y); }

// 度をラジアンに変換
double toRad(double agl){ return agl*M_PI/180.0; }

// a => prev, b => cur, c=> next
// prev から cur へ行って next へ行く際の角度を求める
double getArg(Point a,Point b,Point c){
  double arg1 = atan2(b.y-a.y,b.x-a.x);
  double arg2 = atan2(c.y-b.y,c.x-b.x);
  double arg = fabs( arg1 - arg2 );
  while( arg > M_PI ) arg -= 2.0 * M_PI;
  return fabs(arg);
}

int ccw(Point p0,Point p1,Point p2){
  Point a = p1-p0;
  Point b = p2-p0;
  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS)return CLOCKWISE;
  if(dot(a,b) < -EPS)return ONLINE_BACK;
  if(norm(a) < norm(b))return ONLINE_FRONT;
  return ON_SEGMENT;
}

// p0 を p1 を基準に時計回りで回した時の p2 までの角度
double ccw_angle(Point p0,Point p1,Point p2){
  double ret = M_PI - getArg(p0,p1,p2);
  //cout << ret * 180 / M_PI << endl;
  if( ccw(p1,p0,p2) == COUNTER_CLOCKWISE ) ret = 2*M_PI - ret;
    return ret;
}


double cross3p(Point p,Point q,Point r) { return (r.x-q.x) * (p.y -q.y) - (r.y - q.y) * (p.x - q.x); }
  
bool collinear(Point p,Point q,Point r) { return fabs(cross3p(p,q,r)) < EPS; }
  
bool ccwtest(Point p,Point q,Point r)   { return cross3p(p,q,r) > 0; }
 
bool onSegment(Point p,Point q,Point r) { return collinear(p,q,r) && equals(sqrt(pow(p.x-r.x,2)+pow(p.y-r.y,2)) + sqrt(pow(r.x-q.x,2) + pow(r.y-q.y,2) ),sqrt(pow(p.x-q.x,2)+pow(p.y-q.y,2)) ) ; }


typedef pair<double,double> dd;
const double DINF = 1e20;
#define pow2(a) ((a)*(a))
bool LT(double a ,double b){ return !equals(a,b) && a < b; }
bool LTE(double a,double b){ return  equals(a,b) || a < b; }

dd calc(double x1,double y1,double vx1,double vy1,
        double x2,double y2,double vx2,double vy2,double r){
  double VX = (vx1-vx2), X = (x1-x2), VY = (vy1-vy2), Y = (y1-y2);
  double a = pow2(VX) + pow2(VY), b = 2*(X*VX+Y*VY), c = pow2(X) + pow2(Y) - pow2(r);
  dd ret = dd(DINF,DINF);
  double D = b*b - 4 * a * c;

  if( LT(D,0.0) ) return ret;

  if( equals(a,0.0) ) {
    if( equals(b,0.0) ) return ret;
    if( LT(-c/b,0.0)  ) return ret;
    ret.first = - c / b;
    return ret;
  }

  if( equals(D,0.0) ) D = 0;
  ret.first  = ( -b - sqrt( D ) ) / ( 2 * a );
  ret.second = ( -b + sqrt( D ) ) / ( 2 * a );
  if( !equals(ret.first,ret.second) && ret.first > ret.second ) swap(ret.first,ret.second);
  return ret;
}


Point c;
Polygon poly,qoly;

// type => 0 : CW, type => 1 : CCW
double calc(Polygon &A,Polygon &B,int type){
  double ret = DINF;
  rep(i,A.size()){
    double cost = DINF;
    rep(j,B.size()){
      Vector e = ( B[j] - B[(j+1)%(int)B.size()] ) / abs( B[j] - B[(j+1)%(int)B.size()] );
      dd tmp = calc(c.x,c.y,0,0,
                    B[j].x,B[j].y,e.x,e.y,abs(A[i]-c));
      vector<Point> vp;
      if( !equals(tmp.first ,DINF) ) vp.push_back(B[j]+e*tmp.first);
      if( !equals(tmp.second,DINF) ) vp.push_back(B[j]+e*tmp.second);
      rep(k,vp.size()) if( onSegment(B[j],B[(j+1)%(int)B.size()],vp[k]) ) {
        double theta = ccw_angle(A[i],c,vp[k]);
        cost = min(cost,(!type?theta:2*M_PI-theta));
      }
    }
    ret = min(ret,cost);
  }
  return ret;
}

void compute(){
  double mini = min(calc(poly,qoly,0),calc(qoly,poly,1));
  if( equals(mini,DINF) ) puts("360.0000000");
  else                    printf("%.10lf\n",mini * 180.0 / M_PI); 
}

int main(){
  int M,N;
  while( cin >> M >> N, M|N ){
    poly.resize(M); qoly.resize(N);
    rep(i,M) cin >> poly[i].x >> poly[i].y;
    rep(i,N) cin >> qoly[i].x >> qoly[i].y;
    cin >> c.x >> c.y;
    compute();
  }
  return 0;
}