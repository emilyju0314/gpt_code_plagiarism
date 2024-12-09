#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-7)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1 
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

using namespace std;

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
  bool operator <  (const Segment& s) const { return ( p2 == s.p2 ) ? p1 < s.p1 : p2 < s.p2; }
  bool operator == (const Segment& s) const { return ( s.p1 == p1 && s.p2 == p2 ) || ( s.p1 == p2 && s.p2 == p1 ); }

};

typedef Point Vector;
typedef Segment Line;

double dot(Point a,Point b){ return a.x*b.x + a.y*b.y; }

double cross(Point a,Point b){ return a.x*b.y - a.y*b.x; }

double norm(Point a){ return a.x*a.x+a.y*a.y; }

double abs(Point a){ return sqrt(norm(a)); }

Point rotate(Point a,double rad){ return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y); }

double toRad(double agl){ return agl*M_PI/180.0; }

int ccw(Point p0,Point p1,Point p2){
  Point a = p1-p0;
  Point b = p2-p0;
  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS)return CLOCKWISE;
  if(dot(a,b) < -EPS)return ONLINE_BACK;
  if(norm(a) < norm(b))return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool intersectLL(Line l, Line m) {
  return abs(cross(l.p2-l.p1, m.p2-m.p1)) > EPS || // non-parallel
         abs(cross(l.p2-l.p1, m.p1-l.p1)) < EPS;   // same line
}

bool intersectLS(Line l, Line s) {
  return cross(l.p2-l.p1, s.p1-l.p1)*       // s[0] is left of l
         cross(l.p2-l.p1, s.p2-l.p1) < EPS; // s[1] is right of l
}

bool intersectLP(Line l,Point p) { return abs(cross(l.p2-p, l.p1-p)) < EPS; }

bool intersectSS(Line s, Line t) {
  return ccw(s.p1,s.p2,t.p1)*ccw(s.p1,s.p2,t.p2) <= 0 &&
         ccw(t.p1,t.p2,s.p1)*ccw(t.p1,t.p2,s.p2) <= 0;
}

bool intersectSP(Line s, Point p) { return abs(s.p1-p)+abs(s.p2-p)-abs(s.p2-s.p1) < EPS; }

Point projection(Line l,Point p) {
  double t = dot(p-l.p1, l.p1-l.p2) / norm(l.p1-l.p2);
  return l.p1 + (l.p1-l.p2)*t;
}

Point reflection(Line l,Point p) { return p + (projection(l, p) - p) * 2; }

double distanceSP(Line s, Point p) {
  Point r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s.p1 - p), abs(s.p2 - p));
}

Point crosspoint(Line l,Line m){
  double A = cross(l.p2-l.p1,m.p2-m.p1);
  double B = cross(l.p2-l.p1,l.p2-m.p1);
  if(abs(A) < EPS && abs(B) < EPS){
    vector<Point> vec;
    vec.push_back(l.p1),vec.push_back(l.p2),vec.push_back(m.p1),vec.push_back(m.p2);
    sort(vec.begin(),vec.end());
    assert(vec[1] == vec[2]); //???????????°??????????????????
    return vec[1];
    //return m.p1;
  }
  if(abs(A) < EPS)assert(false);
  return m.p1 + (m.p2-m.p1)*(B/A);
}

// --------

inline bool LT(double a,double b) { return !equals(a,b) && a < b; }
inline bool LTE(double a,double b) { return equals(a,b) || a < b; }

const double PI2 = M_PI * 2.0;
struct AngleRange {
  Point o; // ?????????, ???????????????????§???? ????????¨???????????????????????????,????????????
  double mini,maxi; // mini <= maxi | 0 <= mini,maxi <= 720
  // ?????°?????????????????§abs(maxi-mini)???180??????

  AngleRange( Point p, Segment seg ) {
    o = p;
    seg.p1 = seg.p1 - o, seg.p2 = seg.p2 - o;
    complex<double> p1(seg.p1.x,seg.p1.y);
    complex<double> p2(seg.p2.x,seg.p2.y);
    double tmp = arg( p1 / p2 ); // ???????????? p1 ??¨ p2 ??????????§? arg( p1 / p2 )
    mini = LT(0.0,tmp) ? arg(p2) : arg(p1);
    if( LT(mini,0) ) mini += PI2;
    maxi = abs(tmp) + mini;
  }

  bool fail(){ return equals(mini,maxi); }

  // mini < a < maxi
  bool contains(double a) const { 
    return ( LT(mini,a-PI2) && LT(a-PI2,maxi) ) || ( LT(mini,a) && LT(a,maxi) )  || ( LT(mini,a+PI2) && LT(a+PI2,maxi) );
  }

  bool contains(Point p) const {
    p = p - o;
    complex<double> cp(p.x,p.y);
    return contains(arg(cp));
  }

  void update( AngleRange ar ) {
    if( contains(ar.mini) ) {
      if( contains(ar.maxi) ) mini = ar.mini, maxi = ar.maxi;
      else                    mini = ar.mini;
    } else { 
      if(        contains(ar.maxi) ) maxi = ar.maxi;
      else  if( !ar.contains(mini) && !equals(mini,ar.mini) ) maxi = mini;
    }
    if( LT(maxi-mini,0)    ) maxi += PI2;
    if( LTE(PI2,maxi-mini) ) maxi -= PI2;
  }

};

ostream& operator << (ostream& os,const AngleRange& a){ os << "[ " << a.mini*180.0/M_PI << " , " << a.maxi*180.0/M_PI << " ]"; }

Segment reflection(Line line, Segment seg){
  return Segment(reflection(line,seg.p1),reflection(line,seg.p2));
}

double distance(Segment s,Point p1,Point p2){
  Segment t = Segment(p1,p2);
  Point cp = crosspoint(s,Line(p1,p2));
  return abs(p1-cp);
}

Point vp;
double distance2(Segment s,double rad){
  Vector e = Point(10,0);
  e = rotate(e,rad);
  Point cp = crosspoint(s,Line(vp,vp+e));
  return abs(cp-vp);
}

const int loop_limit = 100000;
void compute(Point phantom,Segment mirror1,Segment mirror2){
  
  vp = phantom;

  Point iPhantom[2] = { reflection(mirror1,phantom), reflection(mirror2,phantom) }; 
  Segment nmirror[2] = { mirror1, mirror2 };
  AngleRange range[2] = { AngleRange(phantom,mirror1), AngleRange(phantom,mirror2) };
  int cnt = 0;
  int i = 0;
  while( i < loop_limit && cnt <= 100 && !( range[0].fail() && range[1].fail() ) ){
    if( !range[0].fail() )
    if( !intersectSS(Segment(phantom,iPhantom[0]),mirror2) || !LT(distance(mirror2,phantom,iPhantom[0]),distance(mirror1,phantom,iPhantom[0])) ) {
      if( range[0].contains(iPhantom[0]) ) ++cnt;
    }

    if( !range[1].fail() )
     if( !intersectSS(Segment(phantom,iPhantom[1]),mirror1) || !LT(distance(mirror1,phantom,iPhantom[1]),distance(mirror2,phantom,iPhantom[1])) ) {
      if( range[1].contains(iPhantom[1]) ) ++cnt;
    }
    
    Segment tmp1 = reflection(mirror1,nmirror[1]);
    Segment tmp2 = reflection(mirror2,nmirror[0]);
    Point   tmp3 = reflection(mirror1,iPhantom[1]);
    Point   tmp4 = reflection(mirror2,iPhantom[0]);

    AngleRange tmpR(phantom,tmp1);
    range[0].update(tmpR);
    tmpR = AngleRange(phantom,tmp2);
    range[1].update(tmpR);

    double mid = ( range[0].mini + range[0].maxi ) / 2;
    if( !range[0].fail() && LT(distance2(tmp1,mid),distance2(nmirror[0],mid)) ) range[0].mini = range[0].maxi = 0;
    mid = ( range[1].mini + range[1].maxi ) / 2;
    if( !range[1].fail() && LT(distance2(tmp2,mid),distance2(nmirror[1],mid)) ) range[1].mini = range[1].maxi = 0;

    nmirror[0] = tmp1;
    nmirror[1] = tmp2;
    iPhantom[0] = tmp3;
    iPhantom[1] = tmp4;

    ++i;
    
  }

  if( cnt > 100 ) puts("TOO MANY");
  else cout << cnt << endl;
}

int main(){
  int sx,sy;
  while( cin >> sx >> sy, sx | sy ){
    Point sp = Point(sx,sy);
    Segment segs[2];
    rep(i,2) cin >> segs[i].p1.x >> segs[i].p1.y >> segs[i].p2.x >> segs[i].p2.y;
    compute(sp,segs[0],segs[1]);
  }
  return 0;
}