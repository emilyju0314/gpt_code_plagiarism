#include<iostream>
#include<cmath>
#include<vector>
#include<complex>
#include<cassert>

using namespace std;

#define OVER 0x01
#define RIGHT 0x02
#define LEFT 0x04
#define FRONT 0x08
#define BACK 0x10

typedef long long elem;
typedef complex<elem> point, vec;
typedef pair<point,point> line, seg;

elem dot(point a, point b){ return a.real() * b.real() + a.imag() * b.imag(); }
elem cross(point a, point b){ return a.real() * b.imag() - a.imag() * b.real(); }
elem abs2(point a){ return dot(a,a); }

inline int ccw(const point &a, point b, point x){
  b-=a;
  x-=a;
  if( cross(b,x) == 0 && dot(b,x) < 0 ) return BACK;
  if( cross(b,x) == 0 && abs2(b) < abs2(x) ) return FRONT;
  if( cross(b,x) == 0 ) return OVER;
  if( cross(b,x) > 0 ) return LEFT;
  return RIGHT;
}

inline bool intersectedSS(const seg &a, const seg &b){
  int cwaf=ccw(a.first,a.second,b.first);
  int cwbf=ccw(b.first,b.second,a.first);
  int cwas=ccw(a.first,a.second,b.second);
  int cwbs=ccw(b.first,b.second,a.second);
  if( !( (cwaf|cwas)&(RIGHT|LEFT) ) ) return false;
  if(cwaf == OVER || cwas == OVER || cwbf == OVER || cwbs==OVER) return true;
  return (cwaf|cwas)==(LEFT|RIGHT) && (cwbf|cwbs)==(LEFT|RIGHT);
}

complex<double> intersectionLL(const line &a, const line &b){
  vec va=a.second-a.first;
  vec vb=b.second-b.first;
  assert(cross(vb,va)!=0);
  double t = cross(vb,b.first-a.first)/(double)cross(vb,va);
  return complex<double>(a.first.real() + t * va.real(), a.first.imag() + t * va.imag());
}

bool inSimple(const point &x, const vector<point> &p){
  const int n = p.size();
  if(n<3)return false;
  int cnt=0;
  for(int i=0;i<n;++i){
    point a=p[i]-x,b=p[(i+1)%n]-x;
    if(b.imag()>a.imag())swap(a,b);
    int cw=ccw(a,b,point(0,0));
    if(cw==LEFT&&0<=a.imag()&&b.imag()<0)++cnt;
    if(cw==OVER)return true;
  }
  if(cnt&1)return true;
  else return false;
}

bool goal(const seg &orbit, const seg &gline, complex<double> &ret){
  if( intersectedSS(orbit,gline) ){
    ret = intersectionLL( orbit, gline );
    return true;
  }
  return false;
}

double dist2(const point &a, const complex<double> &b){
  double dx = b.real() - a.real();
  double dy = b.imag() - a.imag();
  return pow(dx,2) + pow(dy,2);
}

bool crashed(const seg &orbit, const vector<point> &inner, const vector<point> &outer,  complex<double> &nearest){
  bool ret = false;
  double n_dist = 1e40;
  for(int k = 0; k < 2; ++k){
    vector<point> c;
    if( k == 0 ){ c = inner; }else{ c = outer; }
    for(int i = 0; i < (int)c.size(); ++i){
      seg s = seg( c[i], c[(i+1)%c.size()] );
      if( intersectedSS( orbit, s ) ){
        // cout << i << ' ' << orbit.first << '-' << orbit.second << " + " << s.first << '-' << s.second << endl;
        ret = true;
        complex<double> tmp;
        tmp = intersectionLL( orbit, s );
        if( n_dist > dist2( orbit.first, tmp ) ){
          nearest = tmp;
          n_dist = dist2(orbit.first, tmp);
        }
      }
    }
  }
  return ret;
}

int main(){
  int T;
  //cin >> T;
  T = 1;
  for(int tc=1;tc<=T;++tc){
    vector<point> inner, outer;
    elem start_y;
    elem start_x1, start_x2;
    line gline;
    bool rev = false;
    
    while(true){
      elem x,y;
      cin >> x;
      if( x == 99999 ) break;
      cin >> y;
      inner.push_back( point(x,y) );
    }
    while(true){
      elem x,y;
      cin >> x;
      if( x == 99999 ) break;
      cin >> y;
      outer.push_back( point(x,y) );
    }

    if(tc>1)cout<<endl;
    
    if( inSimple( outer.front(), inner ) ){
      swap( inner, outer );
    }
    
    assert( inner.size() > 2 );
    assert( outer.size() > 2 );
    
    start_y = outer.front().imag();
    start_x1 = outer.front().real();
    start_x2 = inner.front().real();
    
    if( start_x1 > start_x2 ){
      swap( start_x1, start_x2 );
      rev = true;
    }
    
    gline = line( point(start_x1, start_y), point(start_x2, start_y) );

    while(true){
      bool ng = false;
      bool cleared = false;
      double clear_time = 0;
      int vx = 0, vy = 0;
      int counter = 0;
      elem sx, sy;
      
      cin >> sx;
      if( sx == 99999 ) break;
      cin >> sy;
      
      if( sy != start_y ) ng = true;
      if( !(start_x1 < sx && sx < start_x2) ) ng = true;
      
      double laptime;
      cin >> laptime;
      
      elem x = sx, y = sy;
      elem px=-1,py=-1;
      bool under_y = false;
      bool above_y = false;
      bool cont_on_line = false;

      while(true){
        int ax, ay;
        
        cin >> ax;
        if( ax == 99999 ) break;
        cin >> ay;

        ++counter;
        vx += ax;
        vy += ay;
        
        if( !(ax == -1 || ax == 0 || ax == 1) ) ng = true;
        if( !(ay == -1 || ay == 0 || ay == 1) ) ng = true;

        if( cleared ){
          cleared = false;
          ng = true;
          continue;
        }
        if( ng ) continue;

        if( start_x1 < x && x < start_x2 && y == start_y ){
          cont_on_line = true;
          if( start_x1 < x+vx && x+vx < start_x2 && y+vy == start_y ){
            x += vx;
            y += vy;
            continue;
          }
        }
        if( cont_on_line && py >= 0 ){
          if( (py-start_y) * (y-start_y) < 0 ){
            ng = true;
          }
        }

        cont_on_line = false;

        if( ng ) continue;
        if( vx == 0 && vy == 0 ) continue;
        
        seg orbit( point(x,y), point(x+vx, y+vy) );
        complex<double> tmp, gpoint;
                
        if( crashed( orbit, inner, outer, tmp ) ){
          ng = true;
        }
        
        if( goal( orbit, gline, gpoint ) ){
          if( ( rev ? y > start_y : y < start_y ) && under_y && above_y ){
            // cross the goal line
            if( ng ){
              if( dist2( orbit.first, gpoint ) < dist2( orbit.first, tmp ) - 1e-6 ){
                cleared = true;
              }
            }else{
              cleared = true;
            }
            if( cleared ){
              clear_time = counter - sqrt(dist2(orbit.second,gpoint))/sqrt((vx*vx+vy*vy));
            }
          }else if( dist2( orbit.second, gpoint ) > 1e-6 ){
            // cross the start line
            if( counter > 1 ){
              ng = true;
            }else{
              if( rev ){ if( orbit.second.imag() > start_y ) ng = true; }
              else     { if( orbit.second.imag() < start_y ) ng = true; }
            }
          }
        }

        px = x;
        py = y;
        x += vx;
        y += vy;
        
        if( y < start_y ) under_y = true;
        if( y > start_y ) above_y = true;
      }
      
      if( !ng && cleared && abs(laptime - clear_time) <= 0.01  ){
        cout << "OK" << endl;
      }else{
        cout << "NG" << endl;
      }
      
    }
    
  }
  return 0;
}