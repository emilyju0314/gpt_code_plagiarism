/* 
方針
0. 初期状態で既にAliceが見えているか判定 =(YES)=> 0.000 と出力して終わる
1. Bombと長方形の角を結ぶ線分を列挙
   線分は建物の角とぶつかるor平行であるならそのまま伸ばしていく ( 建物につっこんだら終了 )
2. Aliceから各点 ( 建物の角、線分の端点 ) への最短距離を求める
3. 各点から直接到達可能なBombの線分をみつけ、その点までの距離 + その点からBombの線分までの最短距離を計算し、最も短いものを記録
 */

#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-5)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

bool  LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return  equals(a,b) || a < b; }

class Point{
public:
  double x,y;
  Point(double x = 0,double y = 0): x(x),y(y){}
  Point operator + (const Point &p){return Point(x+p.x,y+p.y);}
  Point operator - (const Point &p){return Point(x-p.x,y-p.y);}
  Point operator * (double a){return Point(a*x,a*y);}
  Point operator / (double a){return Point(x/a,y/a);}
  Point operator * (const Point &a){ return Point(x * a.x - y * a.y, x * a.y + y * a.x); }
  bool operator < (const Point& p) const{ return !equals(x,p.x)?x<p.x:(!equals(y,p.y)&&y<p.y); }
  bool operator == (const Point& p)const{ return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS; }
};

struct Segment{
  Point p1,p2;
  Segment(Point p1 = Point(),Point p2 = Point()):p1(p1),p2(p2){}
  bool operator <  (const Segment& s) const { return ( p1 == s.p1 ) ? p2 < s.p2 : p1 < s.p1; }
  bool operator == (const Segment& p) const { return ( p.p1 == p1 && p.p2 == p2 ) || ( p.p1 == p2 && p.p2 == p1 ); }
};

typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;

double dot(const Point &a,const Point &b){ return a.x*b.x + a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - a.y*b.x; }
double norm(const Point &a){ return a.x*a.x+a.y*a.y; }
double abs(const Point &a){ return sqrt(norm(a)); }

int ccw(Point p0,Point p1,Point p2){
  Point a = p1-p0;
  Point b = p2-p0;
  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS)return CLOCKWISE;
  if(dot(a,b) < -EPS)return ONLINE_BACK;
  if(norm(a) < norm(b))return ONLINE_FRONT;
  return ON_SEGMENT;
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

double distanceSP(Line s, Point p) {
  Point r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s.p1 - p), abs(s.p2 - p));
}

Point nearest_point(Segment seg,Point p){
  Point r = projection(seg,p);
  if( intersectSP(seg,r) ) return r;
  if( LT(abs(seg.p1-p),abs(seg.p2-p)) ) return seg.p1;
  return seg.p2;
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
  }
  if(abs(A) < EPS)assert(false);
  return m.p1 + (m.p2-m.p1)*(B/A);
}

double cross3p(Point p,Point q,Point r){ return (r.x-q.x) * (p.y -q.y) - (r.y - q.y) * (p.x - q.x); }
  
bool collinear(Point p,Point q,Point r){ return fabs(cross3p(p,q,r)) < EPS; }
  
 
bool onSegment(Point p,Point q,Point r){
  return collinear(p,q,r) && equals(sqrt(pow(p.x-r.x,2)+pow(p.y-r.y,2)) + sqrt(pow(r.x-q.x,2) + pow(r.y-q.y,2) ),sqrt(pow(p.x-q.x,2)+pow(p.y-q.y,2)) ) ;
}

  
//多角形poly内（線分上も含む）に点pが存在するかどうは判定する  
inline bool inPolygon(Polygon poly,Point p,int on) {
  if( LT(poly[0].x,p.x) && LT(p.x,poly[3].x) && LT(poly[0].y,p.y) && LT(p.y,poly[1].y) ) return true;
  return false;
}  

const double DINF = 1e20;
const int MAX_N = 40;
int N;
Point ps[40][2];
Point A,B;

Point vir;
bool comp_dist(const Point &p1,const Point &p2){
  return LT(abs(vir-p1),abs(vir-p2));
}

// target_segがtriesのいづれかと交差しているか? true -> 交差してる false -> してない
bool intersect_checker(const vector<Polygon>& tries,Segment target_seg){
  rep(i,tries.size()){
    vector<Point> vp;
    vp.push_back(target_seg.p1);
    vp.push_back(target_seg.p2);
    rep(j,tries[i].size()){
      Segment seg = Segment(tries[i][j],tries[i][(j+1)%tries[i].size()]);
      if( equals(cross(target_seg.p1-target_seg.p2,seg.p1-seg.p2),0.0) ) {
        if( onSegment(target_seg.p1,target_seg.p2,seg.p1) ) vp.push_back(seg.p1);
        if( onSegment(target_seg.p1,target_seg.p2,seg.p2) ) vp.push_back(seg.p2);
      } else {
        if( intersectSS(target_seg,seg) ) vp.push_back(crosspoint(target_seg,seg));
      }
    }
    sort(vp.begin(),vp.end());
    vp.erase(unique(vp.begin(),vp.end()),vp.end());
    vir = target_seg.p1;
    sort(vp.begin(),vp.end(),comp_dist);
    rep(k,(int)vp.size()-1) {
      Point mp = ( vp[k] + vp[k+1] ) / 2.0;
      if( inPolygon(tries[i],mp,0) ) return true;
    }
  }
  return false;
}

inline bool containAnyPolygon(vector<Polygon> &polies,Point p){
  rep(i,polies.size()) if( LT(polies[i][0].x,p.x) && LT(p.x,polies[i][3].x) && LT(polies[i][0].y,p.y) && LT(p.y,polies[i][1].y) ) return true;
  return false;
}

vector<Segment> createBombLine(vector<Polygon> &tries,Point sp){
  Polygon surround(4);
  surround[0] = Point(-20000,-20000); surround[1] = Point(-20000,20000); // 制約のミスを知らないとここで落ちる
  surround[2] = Point(20000,20000);   surround[3] = Point(20000,-20000);
  vector<Segment> ret;
  rep(i,tries.size()) rep(j,tries[i].size()){
    if( sp == tries[i][j] ) continue;
    Vector e = ( tries[i][j] - sp ) / abs( tries[i][j] - sp );
    Segment line = Segment(sp,sp+e*100000);
    vector<Point> vp;
    vp.push_back(sp);
    vp.push_back(tries[i][j]);
    rep(k,4) {
      if( equals(cross(surround[k]-surround[(k+1)%4],line.p1-line.p2),0.0) ) continue;
      Segment seg = Segment(surround[k],surround[(k+1)%4]);
      if( intersectSS(line,seg) ) vp.push_back(crosspoint(line,seg));
    }

    rep(k,tries.size()) rep(l,tries[k].size()) {
      Segment seg = Segment(tries[k][l],tries[k][(l+1)%tries[k].size()]);
      if( equals(cross(seg.p1-seg.p2,line.p1-line.p2),0.0) ) continue;
      if( intersectSS(seg,line) ) vp.push_back(crosspoint(seg,line));
    }

    sort(vp.begin(),vp.end());
    vp.erase(unique(vp.begin(),vp.end()),vp.end());
    vir = sp;
    sort(vp.begin(),vp.end(),comp_dist);
    rep(k,(int)vp.size()-1){
      Segment seg = Segment(vp[k],vp[k+1]);
      Point mp = ( seg.p1 + seg.p2 ) / 2.0;
      if( containAnyPolygon(tries,mp) ) break;
      ret.push_back(seg);
    }
  }
  sort(ret.begin(),ret.end());
  ret.erase(unique(ret.begin(),ret.end()),ret.end());
  return ret;
}

void makeGraph(const vector<Point> &vp,vector<vector<int> > &G,vector<Polygon> &tries){
  int V = vp.size();
  rep(i,V){
    REP(j,i+1,V){
      if( intersect_checker(tries,Segment(vp[i],vp[j])) ) continue;
      G[i].push_back(j);
      G[j].push_back(i);
    }
  }
}

//Aliceから各点への最短距離を求める
struct Data {  
  int cur;
  double weight;
  bool operator < ( const Data& data ) const { return !equals(weight,data.weight) && weight > data.weight; }
};

void dijkstra(const vector<vector<int> > &G,vector<Point> &vp,vector<double> &mindist){
  int V = vp.size();
  int sp = -1;
  rep(i,V) if( vp[i] == A ) { sp = i; break; }
  assert( sp != -1 );
  mindist[sp] = 0;
  priority_queue<Data> Q;
  Q.push((Data){sp,0});
  while( !Q.empty() ){
    Data data = Q.top(); Q.pop();
    if( LT(mindist[data.cur],data.weight) ) continue;
    rep(i,G[data.cur].size()){
      int to = G[data.cur][i];
      if( LT(data.weight+abs(vp[data.cur]-vp[to]),mindist[to]) ) {
        mindist[to] = data.weight+abs(vp[data.cur]-vp[to]);
        Q.push((Data){to,mindist[to]});
      }
    }
  }
}

void compute(){
  vector<Polygon> tries;
  rep(i,N) {
    Polygon poly;
    poly.push_back(ps[i][0]);
    poly.push_back(Point(ps[i][0].x,ps[i][1].y));
    poly.push_back(ps[i][1]);
    poly.push_back(Point(ps[i][1].x,ps[i][0].y));
    tries.push_back(poly);
  }

  if( !intersect_checker(tries,Segment(A,B)) ) { puts("0.000"); return; } 

  vector<Segment> segs = createBombLine(tries,B);

  vector<Point> vp;
  vp.push_back(A);
  rep(i,tries.size()) rep(j,tries[i].size()) vp.push_back(tries[i][j]);
  rep(i,segs.size()) rep(j,tries.size()) rep(k,tries[j].size()) {
    if( equals(cross(segs[i].p1-segs[i].p2,tries[j][k]-tries[j][(k+1)%tries[j].size()]),0.0) ) continue;
    Segment seg = Segment(tries[j][k],tries[j][(k+1)%tries[j].size()]);
    if( intersectSS(segs[i],seg) ) vp.push_back(crosspoint(segs[i],seg));
  }
  
  sort(vp.begin(),vp.end());
  vp.erase(unique(vp.begin(),vp.end()),vp.end());
  
  int V = vp.size();
  vector<vector<int> > G(V,vector<int>());
  makeGraph(vp,G,tries);

  vector<double> mindist(V,DINF);
  dijkstra(G,vp,mindist);

  double answer = DINF;
  rep(i,vp.size()) {
    if( LTE(answer,mindist[i]) ) continue;
    rep(j,segs.size()){
      double dist = mindist[i] + distanceSP(segs[j],vp[i]);
      if( LTE(answer,dist) ) continue;
      Point np = nearest_point(segs[j],vp[i]);
      Segment seg = Segment(vp[i],np);
      if( intersect_checker(tries,seg) ) continue;
      answer = dist;
    }
  }
  printf("%.6lf\n",answer);
}

int main(){
  while( scanf("%d",&N), N ){
    rep(i,N) rep(j,2) scanf("%lf %lf",&ps[i][j].x,&ps[i][j].y);
    scanf("%lf %lf %lf %lf",&A.x,&A.y,&B.x,&B.y);
    compute();
  }
  return 0;
}