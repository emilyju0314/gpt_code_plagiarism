#include<bits/stdc++.h>
using namespace std;

typedef complex<double> P;
typedef pair<P,P> L;

int N;
vector<bitset<40> > G;
double const EPS = 1e-10;
namespace std {
  bool operator < (const P& a, const P& b){
    return fabs(real(a)-real(b)) < EPS ? imag(a) < imag(b) : real(a) < real(b);
  }
}
bool equal(double a,double b){ return abs(a-b)<EPS; }
double dot(P a, P b){ return a.real()*b.real() + a.imag() * b.imag(); }
double cross(P a,P b){ return a.real()*b.imag() - a.imag() * b.real(); }

//  a -> b -> c ?????????????????? b -> c ?????????
int ccw(P a, P b, P c){
  b -= a;
  c -= a;
  if(cross(b,c) > EPS) return 1; //???????¨???????
  if(cross(b,c) < -EPS) return -1; // ????¨???????
  if(dot(b,c) < -EPS) return 2; // c -- a -- b ????????´???
  if(norm(b) < norm(c)) return -2; // a -- b -- c ????????´???
  return 0; // a -- c -- b ????????´????
}

// ????????¨?????????????????????????????????????????????true???
bool isIntersect(L s1, L s2){  
  //ccw ??????????????????????????¨, ????????????????????´?????????????????¨??????????????????????????????
  if(max(real(s1.first), real(s1.second)) + EPS < min(real(s2.first), real(s2.second)) ||
     max(imag(s1.first), imag(s1.second)) + EPS < min(imag(s2.first), imag(s2.second)) ||
     max(real(s2.first), real(s2.second)) + EPS < min(real(s1.first), real(s1.second)) ||
     max(imag(s2.first), imag(s2.second)) + EPS < min(imag(s1.first), imag(s1.second))) return false;
  return ( ccw(s1.first,s1.second,s2.first) * ccw(s1.first,s1.second,s2.second) <= 0 &&
           ccw(s2.first,s2.second,s1.first) * ccw(s2.first,s2.second,s1.second) <= 0 );
}

// ?????´???????????????
P crossPoint(L l, L m){
  double A = cross(l.second - l.first, m.second - m.first);
  double B = cross(l.second - l.first, l.second - m.first);
  if(fabs(A) < EPS && fabs(B) < EPS) return m.first;
  else if(fabs(A) >= EPS) return m.first + B / A * (m.second - m.first);
}

/* 
   ????§???¢????????????????????????????§???¢????????¨????¢????????????¨???????????????????????? 
   ????????? 0:?????¨ 1:?¢???? 2:?????¨ 
   O(n) 
*/
int contains(vector<P> v, P p){ 
  bool in = false; 
  for(int i=0;i<(int)v.size();i++){ 
    P a = v[i] - p; 
    P b = v[(i+1)%v.size()] - p; 
    if(imag(a) > imag(b)) swap(a,b); 
    if((imag(a) <= 0 || equal(imag(a),0.0)) && EPS < imag(b)) 
      if(cross(a,b) < -EPS) in = !in; 
    if(equal(cross(a,b), 0.0) && dot(a,b) < EPS) return 1; 
  } 
  return in ? 2 : 0; 
} 

//????§???¢???????????????????????????
bool polygonInSegment(L s,vector<P> v){
  vector<P> ps;
  int n = v.size();
  for(int i=0;i<n;i++){
    L s2 = L( v[i], v[(i+1)%n] );
    if( isIntersect( s, s2 ) ) 
      ps.push_back( crossPoint( s, s2 ) );    
  }
  sort( ps.begin(), ps.end() );
  for(int i=1;i<(int)ps.size();i++){
    if( contains( v, (ps[i-1]+ps[i])/2.0 ) == 0 ) return false;
  }
  return true;
}

bitset<40> state(int id,vector<P> v){
  bitset<40> ret=0; ret[id] = true;
  for(int i=0;i<N;i++){
    if( id == i ) continue;
    L s = L( v[id],v[i] );
    if( polygonInSegment(s,v) ) ret[i] = true;
  }
  return ret;
}


bool incheck(int id){
  for(int i=0;i<(int)G.size();i++){
    if( i == id ) continue;
    if( (G[i]&G[id]) == G[id] ) return false;
  }
  return true;
}

void enump(vector<P> v){
  for(int i=0;i<N;i++)
    G.push_back( state(i,v) );
  bool f=true;
  while(f){
    f = false;
    for(int i=0;i<(int)G.size();i++){
      if( incheck( i ) ) continue;
      G.erase( G.begin()+i );
      f = true;
      break;
    }
  }
}

inline bool check(int st,int m){
  bitset<40> ret=0;
  for(int i=0;i<m;i++)
    if( st & (1<<i) )
      ret |= G[i];
  for(int i=0;i<N;i++) if( !ret[i] ) return false;
  return true;
}

inline bool solve(int k,int id,int m, int st){
  if( k == 0 ) return check( st, m );
  if( m - id == k ) return solve(k-1,id+1,m, st|(1<<id));
  if( solve(k,id+1,m,st) ) return true;
  return solve(k-1,id+1,m,st|(1<<id));
}

int main(){
  cin >> N;
  vector<P> v;
  for(int i=0;i<N;i++){
    int x,y; cin >> x >> y; v.push_back( P(x,y) );
  }

  enump(v);  

  int m = G.size();
  assert(m<=31);
  for(int i=1;;i++){
    if( solve(i,0,m,0) ) {
      cout << i << endl; break;
    }
  }
}