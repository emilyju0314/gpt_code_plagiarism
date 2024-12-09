#include<bits/stdc++.h>

#define EQ(a,b) (abs((a)-(b)) < EPS)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define fs first
#define sc second
#define pb push_back
#define sz size()
#define all(a) (a).begin(),(a).end()

using namespace std;
typedef long double D;
typedef complex<D> P;
typedef pair<P,P> L;
typedef vector<P> Poly;
typedef pair<P,D> C;

const D EPS = 1e-8;
const D PI = acos(-1);

const int MAX_X = 1000, MAX_Y = 1000;

//for vector
inline P unit(P p){return p/abs(p);}

inline pair<P,P> norm(P p){return make_pair(p*P(0,1),p*P(0,-1));}

inline D dot(P x, P y){return real(conj(x)*y);}

inline D cross(P x, P y){return imag(conj(x)*y);}

inline bool para(L a,L b){return abs(cross(a.fs-a.sc,b.fs-b.sc))<EPS;}

inline int ccw(P a,P b,P c){
  b -= a;c -= a;
  if (cross(b,c)>EPS) return 1;   //counter clockwise
  if (cross(b,c)<-EPS) return -1; //clockwise
  if (dot(b, c)<-EPS) return 2;   //c--a--b on line
  if (abs(b)+EPS<abs(c)) return -2;   //a--b--c on line
  return 0;                       //on segment
}

inline bool is_cp(L a,L b){
  if(ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0)
    if(ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<=0)return true;
  return false;
}

inline P line_cp(L a,L b){
  return a.fs+(a.sc-a.fs)*cross(b.sc-b.fs,b.fs-a.fs)/cross(b.sc-b.fs,a.sc-a.fs);
}

inline D area(Poly p){
  if(p.sz<3)return 0;
  D res = cross(p[p.sz-1],p[0]);
  rep(i,p.sz-1)res += cross(p[i],p[i+1]);
  return res/2;
}

int main(){
  int n;
  cin >> n;

  Poly p(n);
  rep(i,n){
    int x,y;
    cin >> x >> y; x*=2; y*=2;
    p[i] = P(x,y);
  }

  D S = area(p);

  vector< vector<D> > v(4*MAX_X+1);
  for(int i=-2*MAX_X;i<=2*MAX_X;i++){
    L l = L( P(i,-2*MAX_Y-1), P(i,2*MAX_Y+1) );
    for(int j=0;j<n;j++){
      L seg = L( p[j], p[(j+1)%n] );
      if(!para(seg,l) && is_cp(seg,l)){
	P cp = line_cp(seg,l);
	if( abs(cp - (seg.fs.real()<seg.sc.real()?seg.sc:seg.fs)) > EPS){
	  v[i+2*MAX_X].push_back(cp.imag());
	}
      }
    }
    sort(v[i+2*MAX_X].begin(), v[i+2*MAX_X].end());
  }

  D sum = 0;
  for(int i=0;i<2*MAX_X;i++){
    assert(v[2*i].size()%2 == 0 && v[2*i+1].size()%2 == 0);
    assert(v[2*i].size() == v[2*i+1].size());

    for(int j=0;j<v[2*i].size();j+=2){
      sum += (abs(v[2*i][j]-v[2*i][j+1])+abs(v[2*i+1][j]-v[2*i+1][j+1]))/2;
    }
  }

  cout << fixed << setprecision(9) << max(sum,S-sum)/4 << endl;
}