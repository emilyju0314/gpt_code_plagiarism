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

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<D,int> pdi;

const D EPS = 1e-8;
const D PI = acos(-1);

namespace std{
  bool operator<(const P &a,const P &b){
    return EQ(real(a),real(b))?imag(a)<imag(b):real(a)<real(b);
  }
  bool operator==(const P &a, const P &b){return EQ(a,b);}
}

//for vector
inline D dot(P x, P y){return real(conj(x)*y);}
inline D cross(P x, P y){return imag(conj(x)*y);}

//for line(segment)
int ccw(P a,P b,P c){
  b -= a;c -= a;
  if (cross(b,c)>EPS) return 1;   //counter clockwise
  if (cross(b,c)<-EPS) return -1; //clockwise
  if (dot(b, c)<-EPS) return 2;   //c--a--b on line
  if (abs(b)<abs(c)) return -2;   //a--b--c on line
  return 0;                       //on segment
}

inline bool para(L a,L b){return abs(cross(a.fs-a.sc,b.fs-b.sc))<EPS;}

inline P line_cp(L a,L b){
  return a.fs+(a.sc-a.fs)*cross(b.sc-b.fs,b.fs-a.fs)/cross(b.sc-b.fs,a.sc-a.fs);
}

inline bool is_cp(L a,L b){
  if(ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0)
    if(ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<=0)return true;
  return false;
}

inline bool in_poly(Poly p,P x){
  if(p.empty())return false;

  int s = p.size();
  D xMax = x.real();
  rep(i,s){
    if(xMax < p[i].real())xMax = p[i].real();
    if(EQ(x,p[i]))return false;
  }
  L h = L( x,P(xMax + 1.0, x.imag()) );

  int c = 0;
  rep(i,s){
    L l = L(p[i],p[(i+1)%s]);
    if(!para(h,l) && is_cp(h,l)){
      P cp = line_cp(h,l);
      if(cp.real() < x.real() + EPS)continue;
      if(!EQ(cp, (l.fs.imag() < l.sc.imag())?l.sc:l.fs))c++;
    }
  }
  return (c&1)?true:false;
}

int main(){
  int n;
  P p[20];
  L l[20];

  while(cin >> n,n){
    Poly poly;
    rep(i,n){
      int x,y;
      cin >> x >> y;
      p[i] = P(x,y);
      poly.push_back(p[i]);
    }

    rep(i,n)l[i] = L(p[i],p[(i+1)%n]);

    vector<L> segs;
    rep(i,n){
      vector<P> cut_point;
      rep(j,n)rep(k,n){
	if(j==k)continue;
	L l2 = L(p[j],p[k]);
	if(!para(l[i],l2)){
	  P cp = line_cp(l[i],l2);
	  if(!ccw(l[i].fs,l[i].sc,cp))cut_point.push_back(cp);
	}
      }

      cut_point.push_back(l[i].fs);
      cut_point.push_back(l[i].sc);
      sort(all(cut_point));
      for(int i=1;i<(int)cut_point.size();i++){
	if(EQ(cut_point[i-1],cut_point[i]))continue;
	segs.push_back(L(cut_point[i-1],cut_point[i]));
      }
    }
    
    //cout << segs.size() << endl;

    vector< vector<int> > visible(n);
    rep(i,n)rep(j,segs.size()){
      L lay1 = L(p[i], segs[j].fs), lay2 = L(p[i], segs[j].sc);

      bool f = false;
      rep(k,n){
	if(!para(lay1,l[k])){
	  P cp1 = line_cp(lay1,l[k]);
	  if(!EQ(lay1.fs,cp1) && !EQ(lay1.sc,cp1) && !EQ(l[k].fs,cp1) && !EQ(l[k].sc,cp1) &&
	     !ccw(lay1.fs,lay1.sc,cp1) && !ccw(l[k].fs,l[k].sc,cp1)){
	    f = true;
	  }
	}

	if(!para(lay2,l[k])){
	  P cp2 = line_cp(lay2,l[k]);
	  if(!EQ(lay2.fs,cp2) && !EQ(lay2.sc,cp2) && !EQ(l[k].fs,cp2) && !EQ(l[k].sc,cp2) &&
	     !ccw(lay2.fs,lay2.sc,cp2) && !ccw(l[k].fs,l[k].sc,cp2)){
	    f = true;
	  }
	}
      }
      if(f)continue;

      P mp = 1.0L/3*(p[i]+lay1.sc+lay2.sc);
      rep(k,n){
	if(!ccw(l[k].fs,l[k].sc,mp))f = true;
      }
      if(f || in_poly(poly,mp))visible[i].push_back(j);
    }
    /*
    rep(i,n){
      cout << "-----" << p[i] << "-----" <<  endl;
      cout << visible[i].size() << endl;
      rep(j,visible[i].size()){
	cout << segs[visible[i][j]].fs << " " << segs[visible[i][j]].sc << endl;
      }
    }
    */

    int ans = n;
    rep(i,1<<n){
      vector<bool> ok(segs.size(),false);
      int cnt = 0;
      rep(j,n){
	if( (i>>j) & 1 ){
	  rep(k,visible[j].size())ok[visible[j][k]] = true;
	  cnt++;
	}
      }
      bool f = true;
      rep(j,ok.size())f &= ok[j];
      if(f)ans = min(ans, cnt);
    }
    cout << ans << endl;
  }
}