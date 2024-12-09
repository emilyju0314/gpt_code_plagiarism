#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-7)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1 
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define equals(a,b) (fabs((a)-(b)) < EPS)

using namespace std;

const int IINF = INT_MAX;

// Library - template - begin

class Point{
public:
  double x,y;

  Point(double x = -IINF,double y = -IINF): x(x),y(y){}

  Point operator + (Point p){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (double a){return Point(a*x,a*y);}
  Point operator / (double a){return Point(x/a,y/a);}
  Point operator * (Point a){ return Point(x * a.x - y * a.y, x * a.y + y * a.x); }

  bool operator < (const Point& p) const{ return !equals(x,p.x)?x<p.x:y<p.y; }

  bool operator == (const Point& p)const{ return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS; }

};

struct Segment{
  Point p1,p2;
  Segment(Point p1 = Point(),Point p2 = Point()):p1(p1),p2(p2){}
  bool operator == (const Segment& p)const { return p.p1 == p1 && p.p2 == p2; }
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

// Library - template - end


// Library - ccw - bingin

int ccw(Point p0,Point p1,Point p2){
  Point a = p1-p0;
  Point b = p2-p0;
  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS)return CLOCKWISE;
  if(dot(a,b) < -EPS)return ONLINE_BACK;
  if(norm(a) < norm(b))return ONLINE_FRONT;
  return ON_SEGMENT;
}

// Library - ccw - end

// Library - intersect - begin

bool intersectLL(Line l, Line m) {
  return abs(cross(l.p2-l.p1, m.p2-m.p1)) > EPS || // non-parallel
         abs(cross(l.p2-l.p1, m.p1-l.p1)) < EPS;   // same line
}
bool intersectLS(Line l, Line s) {
  return cross(l.p2-l.p1, s.p1-l.p1)*       // s[0] is left of l
         cross(l.p2-l.p1, s.p2-l.p1) < EPS; // s[1] is right of l
}
bool intersectLP(Line l,Point p) {
  return abs(cross(l.p2-p, l.p1-p)) < EPS;
}
bool intersectSS(Line s, Line t) {
  return ccw(s.p1,s.p2,t.p1)*ccw(s.p1,s.p2,t.p2) <= 0 &&
         ccw(t.p1,t.p2,s.p1)*ccw(t.p1,t.p2,s.p2) <= 0;
}
bool intersectSP(Line s, Point p) {
  return abs(s.p1-p)+abs(s.p2-p)-abs(s.p2-s.p1) < EPS; // triangle inequality
}

Point projection(Line l,Point p) {
  double t = dot(p-l.p1, l.p1-l.p2) / norm(l.p1-l.p2);
  return l.p1 + (l.p1-l.p2)*t;
}
Point reflection(Line l,Point p) {
  return p + (projection(l, p) - p) * 2;
}
double distanceLP(Line l, Point p) {
  return abs(p - projection(l, p));
}
double distanceLL(Line l, Line m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m.p1);
}

double distanceLS(Line l, Line s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s.p1), distanceLP(l, s.p2));
}
double distanceSP(Line s, Point p) {
  Point r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s.p1 - p), abs(s.p2 - p));
}

double distanceSS(Line s, Line t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t.p1), distanceSP(s, t.p2)),
             min(distanceSP(t, s.p1), distanceSP(t, s.p2)));
}

/*
same lineの時注意
もしm.p1が中心でなかったときに正しい答えとならない
Point crosspoint(Line l,Line m){
  double A = cross(l.p2-l.p1,m.p2-m.p1);
  double B = cross(l.p2-l.p1,l.p2-m.p1);
  if(abs(A) < EPS && abs(B) < EPS){
    vector<Point> vec;
    vec.push_back(l.p1),vec.push_back(l.p2),vec.push_back(m.p1),vec.push_back(m.p2);
    sort(vec.begin(),vec.end());
    assert(vec[1] == vec[2]);
    return vec[1];
    //return m.p1;
  }
  if(abs(A) < EPS)assert(false);
  return m.p1 + (m.p2-m.p1)*(B/A);
}

*/
Point crosspoint(Line l, Line m) {
  double A = cross(l.p2 - l.p1, m.p2 - m.p1);
  double B = cross(l.p2 - l.p1, l.p2 - m.p1);
  if (abs(A) < EPS && abs(B) < EPS) return m.p1; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m.p1 +   (m.p2 - m.p1) * (B / A);
}


// Library - intersect - end

int V;
double vw,vc;
Point ps[1010];
bool here[1010]; // here is the point
double mincost[1010];

// a < b
inline bool LT(double a,double b) { return !equals(a,b) && a < b; }

// a <= b
inline bool LTE(double a,double b) { return equals(a,b) || a < b; }

int main(){

  while( cin >> V, V ){
    cin >> vw >> vc;
    rep(i,V) cin >> ps[i].x >> ps[i].y;

    rep(i,V) mincost[i] = IINF;
    mincost[0] = 0;
    REP(i,1,V) mincost[i] = mincost[i-1] + abs(ps[i]-ps[i-1]) / vw;

    rep(i,V-2){
      if( !( LT(ps[i].y,ps[i+1].y) ) ) continue;
      double lower = ps[i+1].y;
      //cout << "start = " << i << endl;
      REP(k,i+2,V){
        if( !( ps[k-1].y > ps[k].y ) ) {
          //cout << "continue " << k  << endl;
          lower = min(lower,ps[k].y);
          continue;
        }
        if( ps[k].y < lower ){
          double Y = max(ps[i].y,ps[k].y);
          Line line = Line(Point(-10100,Y),Point(10100,Y));
          Point sp = ps[i], gp = ps[k];
          Point np = crosspoint(line,Line(ps[i  ],ps[i+1]));
          Point mp = crosspoint(line,Line(ps[k-1],ps[k]));
          double dist1 = abs(np-sp);
          double dist3 = abs(np-mp);
          double dist4 = abs(gp-mp);
          double time1 = dist1 / vw + dist3 / vc + dist4 / vw;
          //cout << np << " <=> " << mp<<endl;
          //cout << "time1 = " << time1 << " :: " << mincost[i] + time1 << endl;
          if( LT(mincost[i]+time1,mincost[k]) ){
            mincost[k] = mincost[i]+time1;
            REP(j,k,V) mincost[j] = min(mincost[j],mincost[j-1] + abs(ps[j]-ps[j-1])/vw);
          }
        }

        lower = min(lower,ps[k].y);
        if( lower < ps[i].y ) break;
        //if( k == V-1) cout << "BREAK " << k << endl;
      }
    }

    //rep(i,V) cout << mincost[i] << " "; cout << endl;
    printf("%.8f\n",mincost[V-1]);

  }
  return 0;
}