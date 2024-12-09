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

Point crosspoint(Line l,Line m){
  double A = cross(l.p2-l.p1,m.p2-m.p1);
  double B = cross(l.p2-l.p1,l.p2-m.p1);
  if(abs(A) < EPS && abs(B) < EPS){
    vector<Point> vec;
    vec.push_back(l.p1),vec.push_back(l.p2),vec.push_back(m.p1),vec.push_back(m.p2);
    sort(vec.begin(),vec.end());
    assert(vec[1] == vec[2]); //同じセグメントかもよ
    return vec[1];
    //return m.p1;
  }
  if(abs(A) < EPS)assert(false);
  return m.p1 + (m.p2-m.p1)*(B/A);
}

//cross product of pq and pr
double cross3p(Point p,Point q,Point r)
{
  return (r.x-q.x) * (p.y -q.y) - (r.y - q.y) * (p.x - q.x);
}
  
//returns true if point r is on the same line as the line pq
bool collinear(Point p,Point q,Point r)
{
  return fabs(cross3p(p,q,r)) < EPS;
}
  
//returns true if point t is on the left side of line pq
bool ccwtest(Point p,Point q,Point r)
{
  return cross3p(p,q,r) > 0;//can be modified to accept collinear points
}
 
bool onSegment(Point p,Point q,Point r){
  return collinear(p,q,r) && equals(sqrt(pow(p.x-r.x,2)+pow(p.y-r.y,2)) + sqrt(pow(r.x-q.x,2) + pow(r.y-q.y,2) ),sqrt(pow(p.x-q.x,2)+pow(p.y-q.y,2)) ) ;
}


double getArea(vector<Point>& vec){
  double sum = 0;
  for(int i=0;i<(int)vec.size();i++) sum += cross(vec[i],vec[(i+1)%vec.size()]);
  return fabs(sum)/2.0;
}

bool DEBUG = false;
int N;
vector<Point> ps;

bool comp_dist(const Point& a,const Point& b) { return abs(a) < abs(b); }

void makeSegments(vector<Segment> &segs){
  //int dex = 0;
  vector<Point> vp;

  rep(i,N-1) {
  vp.clear();
  vp.push_back(ps[i]);
  vp.push_back(ps[i+1]);
    Segment cur_seg = Segment(ps[i],ps[i+1]);
    rep(j,N-1) if( i != j ) {
      Segment seg = Segment(ps[j],ps[j+1]);
      if( equals(cross(cur_seg.p1-cur_seg.p2,seg.p1-seg.p2),0.0) ) {
        if( onSegment(cur_seg.p1,cur_seg.p2,seg.p1) ) {
          vp.push_back(seg.p1);
        }
        if( onSegment(cur_seg.p1,cur_seg.p2,seg.p2) ) {
          vp.push_back(seg.p2);
        }
      } else if( intersectSS(seg,cur_seg) ) {
        vp.push_back(crosspoint(cur_seg,seg));
      }

    rep(k,vp.size()) vp[k] = vp[k] - ps[i];
    sort(vp.begin(),vp.end(),comp_dist);
    vp.erase(unique(vp.begin(),vp.end()),vp.end());
    rep(k,vp.size()) vp[k] = vp[k] + ps[i];

    }
    rep(k,vp.size()) vp[k] = vp[k] - ps[i];
    sort(vp.begin(),vp.end(),comp_dist);
    vp.erase(unique(vp.begin(),vp.end()),vp.end());
    rep(k,vp.size()) vp[k] = vp[k] + ps[i];
    rep(j,(int)vp.size()-1) {
      segs.push_back(Segment(vp[j],vp[j+1]));
      //segs[dex++] = Segment(vp[j],vp[j+1]);
    }
  }
  //segs.resize(dex);

}



vector<Point> angle_ps;

struct Data{ 
  int from,to,rev; 
  bool operator < (const Data & a)const{
    //cout << from << "," << to << " " << a.from << "," << a.to<< endl;
    int tmp = max(from,to);
    int tmp2 = max(a.from,a.to);
    tmp = max(tmp,tmp2);
    //if( tmp >= angle_ps.size() ) return false;
    Vector vec_a = angle_ps[a.to] - angle_ps[a.from];
    Vector vec_b = angle_ps[to] - angle_ps[from];
    double arg_a = atan2(vec_b.y,vec_b.x);
    double arg_b = atan2(vec_a.y,vec_a.x);
    return !equals(arg_a,arg_b) && arg_a < arg_b;
  }
};
/*
  bool comp_angle(const Data& a,const Data& b){
  cout << a.from << "," << a.to << " " << b.from << "," << b.to << endl;
  Vector vec_a = angle_ps[a.to] - angle_ps[a.from];
  Vector vec_b = angle_ps[b.to] - angle_ps[b.from];
  return atan2(vec_a.y,vec_a.x) <= atan2(vec_b.y,vec_b.x);
  }*/

vector<vector<Data> > G;
vector<Point> vp;

void makeGraph(const vector<Segment> &segs){
  map<Point,int> mp;
  int V = 0;
  rep(i,segs.size()) if( !mp.count(segs[i].p1) ) mp[segs[i].p1] = V++;
  if( !mp.count(segs.back().p2) ) mp[segs.back().p2] = V++;
  vp.resize(V);
  for(map<Point,int>::iterator it = mp.begin(); it != mp.end(); it++){
    vp[it->second] = it->first;
  }
  angle_ps = vp;
  G.resize(V,vector<Data>());
  rep(i,segs.size()) {
    int s = mp[segs[i].p1], t = mp[segs[i].p2];
    G[s].push_back((Data){s,t,-1});
    G[t].push_back((Data){t,s,-1});
  }

  rep(i,V) {
    sort(G[i].begin(),G[i].end());
  }
  rep(i,V) rep(j,(int)G[i].size()) if( G[i][j].rev == -1 ) {
    int to = G[i][j].to;
    rep(k,(int)G[to].size())if( G[to][k].to == i ){
      G[i][j].rev = k;
      G[to][k].rev = j;
      break;
    }
  }

}

const int MAX_V = 6000;
bool visited[MAX_V][MAX_V];


bool getPath(int start_node,int node,int edge,vector<Point> &buf){
  if( visited[node][edge] ){
    if( !buf.empty() && node == start_node ) return true;
    return false;
  }
  visited[node][edge] = true;
 
  int next_node = G[node][edge].to;
  int next_edge = (G[node][edge].rev+1)%((int)G[next_node].size());
  buf.push_back(vp[G[node][edge].from]);
  if(getPath(start_node,next_node,next_edge,buf)) return true;
  else return visited[node][edge] = false;
}

void compute(){
  vector<Segment> segs;
  segs.clear();
  makeSegments(segs);


  makeGraph(segs);


  segs.clear();
  ps.clear();
  angle_ps.clear();
  int V = vp.size();
  assert( V < MAX_V );
  rep(i,V) rep(j,V) visited[i][j] = false;


  double area = 0;
  rep(i,V) rep(j,(int)G[i].size()) if( !visited[i][j] ){
    vector<Point> buf;
    if( getPath(i,i,j,buf) && !buf.empty() ) area += getArea(buf);
  }
  printf("%.10lf\n",area/2.0);  
}

int main(){
  cin >> N;
  ps.resize(N);
  rep(i,N) cin >> ps[i].x >> ps[i].y;

if( N == 43) {
bool ok = true;
Point test[43] = {
Point(720,400),
Point(380,400),
Point(400,460),
Point(720,400),
Point(400,460),
Point(520,560),
Point(720,400),
Point(520,560),
Point(600,580),
Point(720,400),
Point(600,580),
Point(820,580),
Point(720,400),
Point(820,580),
Point(920,500),
Point(720,400),
Point(920,500),
Point(960,400),
Point(720,400),
Point(960,400),
Point(960,300),
Point(720,400),
Point(920,240),
Point(860,180),
Point(720,400),
Point(860,180),
Point(720,180),
Point(720,400),
Point(720,180),
Point(600,200),
Point(720,400),
Point(600,200),
Point(520,240),
Point(720,400),
Point(520,240),
Point(480,280),
Point(720,400),
Point(480,280),
Point(420,320),
Point(720,400),
Point(420,320),
Point(380,400),
Point(720,400)
};
  rep(i,N) if( !( test[i] == ps[i] ) ) ok = false;
  if( ok ) DEBUG = true;
}


  compute();
  return 0;
}