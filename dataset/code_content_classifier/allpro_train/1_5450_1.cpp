#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-6)
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
typedef vector<Point> Polygon;

ostream& operator << (ostream& os,const Point& a){ os << "(" << a.x << "," << a.y << ")"; }

ostream& operator << (ostream& os,const Segment& a){ os << "( " << a.p1 << " , " << a.p2 << " )"; }

double dot(Point a,Point b){ return a.x*b.x + a.y*b.y; }

double cross(Point a,Point b){ return a.x*b.y - a.y*b.x; }

double norm(Point a){ return a.x*a.x+a.y*a.y; }

double abs(Point a){ return sqrt(norm(a)); }

//rad ????§???????????????¢?????§?????????????????¨
Point rotate(Point a,double rad){ return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y); }

// ??????????????¢????????????
double toRad(double agl){ return agl*M_PI/180.0; }

// a => prev, b => cur, c=> next
// prev ?????? cur ????????£??? next ????????????????§????????±???????
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

Polygon andrewScan(Polygon s) {
  Polygon u,l;
  if(s.size() < 3)return s;

  sort(s.begin(),s.end());

  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size()-1]);
  l.push_back(s[s.size()-2]);

  for(int i=2;i<s.size();i++) {
      for(int n=u.size();n >= 2 && ccw(u[n-2],u[n-1],s[i]) != CLOCKWISE; n--)
        u.pop_back();
      u.push_back(s[i]);
    }

  for(int i=s.size()-3; i>=0 ; i--) {
      for(int n=l.size(); n >= 2 && ccw(l[n-2],l[n-1],s[i]) != CLOCKWISE; n--)
        l.pop_back();
      l.push_back(s[i]);
    }

  reverse(l.begin(),l.end());

  for(int i = u.size()-2; i >= 1; i--) l.push_back(u[i]);

  return l;
}

inline double heron(Point A,Point B,Point C){
  double a = abs(B-C);
  double b = abs(A-C);
  double c = abs(A-B);
  double s = ( a + b + c ) / 2;
  return sqrt( s * ( s - a ) * ( s - b ) * ( s - c ) );
}

// -----------------------------------------------------------

const int MAX_V = 1510;
int V,nV;
vector<Point> ps,nps;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

vector<int> buf;
double ternarySearch(int a,int b){
  //cout << "-(" << a << "," << b << ")-" << endl;
  //int L = 1, R = ( a > b ) ? ( ( b - a + nV ) % nV ) : ( ( a - 1 - b + nV) % nV );
  int L = 1;
  int R = ( a > b ) ? ( ( a - b - 1 + nV ) % nV ) : ( ( ( a + nV ) - b - 1  ) % nV );
  //cout << "L = " << L << " R = " << R << endl;
  int sp = b;
  int pL = L, pR = R;

  rep(_,120){
    if( LT(heron(nps[((L+R*2)/3+sp)%nV],nps[a],nps[b]),heron(nps[((L*2+R)/3+sp)%nV],nps[a],nps[b])) ) {
      R = ( L + R * 2 ) / 3;
    } else {
      L = ( L * 2 + R ) / 3;
    }
    if( R == pR && L == pL ) break;
    pR = R, pL = L;
    //if( prev == ((int)((L+R)*0.5+sp))%nV ) break;
    //prev = (int)((L+R)*0.5+sp)%nV;
  }
  /*
  puts("");
  cout << ((int)((L+R)*0.5)+sp)%nV << endl;
  cout << nps[((int)((L+R)*0.5)+sp)%nV] << endl;
  cout << heron(nps[(int)(((L+R)*0.5)+sp)%nV],nps[a],nps[b]) << endl;
  */
  return heron(nps[(int)(((L+R)*0.5)+sp)%nV],nps[a],nps[b]);
}

void compute(){
  nps = andrewScan(ps);
  nV = nps.size();  
  //rep(i,nV) cout << nps[i] << endl;
  //puts("");
  double maxi = 0;
  if( nV == 3 ) {
    rep(i,V) {
      if( nps[0] == ps[i] || nps[1] == ps[i] || nps[2] == ps[i] ) continue;
      double area1 = heron(nps[0],nps[1],ps[i]);
      double area2 = heron(nps[1],nps[2],ps[i]);
      double area3 = heron(nps[2],nps[0],ps[i]);
      double area4 = heron(nps[0],nps[1],nps[2]);
      maxi = max(maxi,area4-min(area1,min(area2,area3)));
    }
  } else {
    /*
    double a = ternarySearch(1,4);
    double b = ternarySearch(4,1);
    cout << a + b << endl;
    maxi = a + b;
    */
    rep(i,nV) REP(j,i+2,nV) {
      double LLVM = 5136;
      double tmp = ternarySearch(i,j)+ternarySearch(j,i);
      if( equals(tmp,LLVM) && !equals(maxi,tmp) ) {
        //cout << i << " !!! " << j << endl;
      }
      maxi = max(maxi,tmp);
    }
  }
  printf("%.1f\n",maxi);
}

int main(){
  /*
  Point p[3];
  rep(i,3) cin >> p[i].x >> p[i].y;
  printf("%.1lf\n",heron(p[0],p[1],p[2]));

  cin >> V;
  ps.resize(V);
  rep(i,V) cin >> ps[i].x >> ps[i].y;
  int L = 1, R = V - 2;
  int sp = 0;
  rep(_,30){
    if( LT(heron(ps[((L+R*2)/3+sp)%V],ps[0],ps[V-1]),heron(ps[((L*2+R)/3+sp)%V],ps[0],ps[V-1])) ) {
      R = ( L + R * 2 ) / 3;
    } else {
      L = ( L * 2 + R ) / 3;
    }
  }
  cout << 0 << " " << ((int)((L+R)*0.5)+sp)%V << " " << V-1 << endl; 
  cout << ps[0] << " " << ps[((int)((L+R)*0.5)+sp)%V] << " " << ps[V-1] << endl;
  cout << heron(ps[(int)(((L+R)*0.5)+sp)%V],ps[0],ps[V-1]) << endl;
  return 0;
  */
  scanf("%d",&V);
  ps.resize(V);
  rep(i,V) scanf("%lf %lf",&ps[i].x,&ps[i].y);
  compute();
  return 0;
}