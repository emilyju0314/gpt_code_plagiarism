#include<iostream>
#include<complex>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cstdio>
#include<iomanip>
#include<fstream>

#ifdef DEBUG_OUTPUT
#define DEBUG(s) s
#else
#define DEBUG(s)
#endif

using namespace std;

typedef double elem;
typedef complex<elem> point,vec;
typedef pair<point,point> line,seg;

const elem pi = 2.0 * acos(0.0);
const elem eps = 1e-11;
enum CCW{FRONT=0x01,RIGHT=0x02,BACK=0x04,LEFT=0x08,OVER=0x10};

point arcSortCenter;

bool eq(elem a, elem b){ return abs(b-a)<eps; }
vec uvec(const vec &u){ return u/abs(u); }
elem dot(const point &a, const point &b){ return a.real() * b.real() + a.imag() * b.imag(); }
elem cross(const point &a, const point &b){ return a.real() * b.imag() - a.imag() * b.real(); }

bool cmpXy(const point &a, const point &b){
  if( eq(a.real(),b.real() ) ) return a.imag()<b.imag();
  if( a.real()<b.real() ) return true;
  return false;
}

elem varg(vec a, vec b){
  elem ret=arg(a)-arg(b);
  if(ret<0)ret+=2*pi;
  if(ret>2*pi)ret-=2*pi;
  if(eq(ret,2*pi))ret=0;
  return ret;
}

inline int ccw(const point &a, point b, point x){
  b -= a;
  x -= a;
  elem cr = cross(b,x);
  if( eq(cr,0.0) && dot(b,x) < 0 ) return BACK;
  if( eq(cr,0.0) && abs(b) < abs(x) ) return FRONT;
  if( eq(cr,0.0) ) return OVER;
  if( cr > 0 ) return LEFT;
  if( cr < 0 ) return RIGHT;
}

bool lessArg(const point &a,const point &b){
  return varg(vec(1,0),a-arcSortCenter)<varg(vec(1,0),b-arcSortCenter);
}

void argSort(const point &O, vector<point> &vp){
  arcSortCenter = O;
  sort(vp.begin(),vp.end(),lessArg);
}

bool intersectedLL(const line &a, const line &b){ return !eq( cross(a.second-a.first,b.second-b.first), 0.0 ); }

point intersectionLL(const line &a, const line &b)
{
  vec va = a.second - a.first;
  vec vb = b.second - b.first;
  return a.first + va * ( cross(vb, b.first - a.first) / cross(vb,va) );
}

bool intersectionLL(const line &a, const line &b, point &ret){
  return intersectedLL( a, b ) ? ret = intersectionLL( a, b ), true : false;
}

bool intersectionLS(line l, seg s, point &ret){
  point tmp;
  return intersectionLL(l,s,tmp) ? ( ccw(s.first,s.second,tmp)&OVER ? ret=tmp, true : false ) : false;
}

elem areaOfPolygon(const vector<point> &vp){
  elem ret = 0;
  for(int i = 0; i < (int)vp.size(); ++i){
    ret += cross(vp[i],vp[(i+1)%vp.size()]);
  }
  return abs(ret/2.0);
}

elem areaOfTriangle(const point &a, const point &b, const point &c)
{
  return abs(cross(b-a,c-a)/2.);
}

void andrewConvexHull(const vector<point> &Q, vector<point> &CH)
{
  vector<point> T = Q;
  if(Q.size()<3){CH=Q;return ;}
  int n = T.size(), k = 0;
  sort( T.begin(), T.end(), cmpXy );
  CH.resize(2*n);
  for(int i = 0; i < n; CH[k++] = T[i++]){
    while( k >= 2 && ccw( CH[k-2], CH[k-1], T[i] ) != LEFT ) --k;
  }
  for(int i = n-2, t = k+1; i >= 0; CH[k++] = T[i--] ){
    while( k >= t && ccw( CH[k-2], CH[k-1], T[i] ) != LEFT ) --k;
  }
  CH.resize(k-1);
}

bool regularConvex(vector<point> &vp){
  vector<point> ret;
  for(int i = 0; i < (int)vp.size(); ++i){
    for(int j = i+1; j < (int)vp.size(); ++j){
      if( abs(vp[i]-vp[j])<eps ){
        vp.erase( vp.begin() + j );
        j = i;
      }
    }
  }
  andrewConvexHull( vp, ret );
  vp = ret;
}

bool convexCut(const vector<point> &vp, // counter clock wise order
	       const line &l,
	       vector<point> &left)
{
  vector<point> tmp;
  for(int i = 0; i < (int)vp.size(); ++i){
    point is;
    seg s(vp[i],vp[(i+1)%vp.size()]);
    if( ccw(l.first, l.second, vp[i] )!=RIGHT ){
      tmp.push_back(vp[i]);
    }
    if(intersectionLS( l, s, is )&&abs(is-s.first)>eps&&abs(is-s.second)>eps){
      tmp.push_back(is);
    }
  }
  left = tmp;
  return true;
}

double Af(const vector<point> &v, double f){
  vector<point> left;
  convexCut(v,line(point(0,0),point(20*cos(f),20*sin(f))),left);
  return areaOfPolygon(v)/2. - areaOfPolygon(left);
}

int main()
{
  int N;
  while(1){
    scanf("%d", &N);
    if( N == 0 ) break;
    vector<point> K;
    point res;
    double hi = pi;
    double low = 0;
    // int cnt = 0;
    double A_hi, A_low, A_m;

    for(int i = 0; i < N; ++i){
      int x,y;
      scanf("%d%d", &x, &y);
      K.push_back( point(x,y));
    }

    while(1){
      double m = (hi+low)/2.;
      
      A_hi = Af(K,hi);
      A_low = Af(K,low);
      A_m = Af(K,m);
      
      if( abs(A_m) <= eps ){
        res = point(20*cos(m),20*sin(m));
        break;
      }
      
      if( A_hi * A_m > 0 ) hi = m;
      else low = m;
    }
cout << fixed << setprecision(15) << res.real() << ' ' << res.imag() << endl;
    // printf("%.15lf %.15lf\n", res.real(), res.imag());
  }
  return 0;
}