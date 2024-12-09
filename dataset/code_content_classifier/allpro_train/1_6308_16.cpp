#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<b?(a=b,1):0)
#define chmin(a,b) (a>b?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;

typedef complex<double> P;
P pIN() { double x,y; cin >> x >> y; return P(x,y); }
namespace std {
  bool operator < (const P& a, const P& b) {
    // if (abs(a-b)<EPS) return 0;
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
bool operator==(const P &a, const P &b) {
  return abs(a-b)<EPS;
}
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > EPS)   return +1;       // counter clockwise
  if (cross(b, c) < -EPS)   return -1;       // clockwise
  if (dot(b, c) < -EPS)     return +2;       // c--a--b on line
  if (EPS < norm(b) && norm(b) < norm(c)-EPS) return -2; // a--b--c on line
  return 0;
}
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
  L() { resize(2); }
};
ostream &operator<<(ostream &os, const L &a) {
  os << a[0] << " -> " << a[1];
  return os;
}
typedef vector<P> G;
#define curr(g, i) g[i]
#define next(g, i) g[(i+1)%g.size()]
#define prev(g, i) g[(i+g.size()-1)%g.size()]
L line(const G &g, int i) {
  return L(g[i],g[(i+1)%g.size()]);
}
struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};
bool contain(const C &c1, const C &c2) {
  double d = abs(c1.p - c2.p);
  return d < c1.r - c2.r + EPS;
}
vector<L> tangentCP(const C &c, const P &p) {
  vector<L> ret;
  P vect = c.p - p;
  double d = abs(vect);
  double l = sqrt(d*d-c.r*c.r);
  if (::isnan(l)) { return ret; }
  P v1 = vect * P(l / d,  c.r / d);
  P v2 = vect * P(l / d, -c.r / d);
  ret.push_back(L(p, p+v1));
  if (l > EPS)
    ret.push_back(L(p, p+v2));
  return ret;
}
vector<L> tangentCC(const C &c1, const C &c2) {
  vector<L> ret;
  if (abs(c1.p - c2.p) - (c1.r + c2.r) > -EPS) {
    P center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);
    ret = tangentCP(c1, center);
  }
  if (fabs(c1.r - c2.r) > EPS) {
    P out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);
    vector<L> nret = tangentCP(c1, out);
    ret.insert(ret.end(), nret.begin(), nret.end());
  } else {
    P vect = c2.p - c1.p;
    vect /= abs(vect);
    P q1 = c1.p + vect * P(0, 1) * c1.r;
    P q2 = c1.p + vect * P(0, -1) * c1.r;
    ret.push_back(L(q1, q1 + vect));
    ret.push_back(L(q2, q2 + vect));
  }
  return ret;
}
P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
P reflection(const L &l, const P &p) {
  return p + P(2,0) * (projection(l, p) - p);
}

vector<P> crosspointLC(const L &l, const C &c) {
  vector<P> ret;
  P center = projection(l, c.p);
  double d = abs(center - c.p);
  double t = sqrt(c.r * c.r - d * d);
  if (::isnan(t)) { return ret; }
  P vect = (l[1] - l[0]);
  vect /= abs(vect);
  ret.push_back(center - vect * t);
  if (t > EPS) {
    ret.push_back(center + vect * t);
  }
  return ret;
}
bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

vector<P> crosspointSC(const L &s, const C &c) {
  vector<P> ret;
  vector<P> nret = crosspointLC(s, c);
  FOR(it, nret)
    if (intersectSP(s, *it))
      ret.push_back(*it);
   return ret;
}


G g;
double l,r;
int N;

struct Res {
  P ct;
  L s;
  double ang;
  Res(const P &ct, const L &s, double ang) :
    ct(ct),s(s),ang(ang) {}
  Res() {}
};

bool win(const Res &a, const Res &b, const P &ct) {
  if (abs(a.ang-b.ang)>EPS) return a.ang > b.ang;
  return abs(a.ct-ct) < abs(b.ct-ct);
}
bool sameang(const P &a, const P &b) {
  return abs(cross(a,b))<EPS && dot(a,b)>0;
}
double angle(const P &a, const P &b) {
  double ret = arg(b)-arg(a);
  return (ret>=0) ? ret : ret + 2*PI;
}
// テ」ツδ凖」ツつッテ」ツδ暗」ツδォaテ」ツ?ィテ」ツδ凖」ツつッテ」ツδ暗」ツδォbテ」ツ?ョテゥツ鳴禿」ツ?ョティツァツ津・ツコツヲ
double angle2(const P &a, const P &b) {
  return min(angle(a,b), angle(b,a));
}
double angle2_2(const P &a, const P &b) {
  double ret = abs(arg(b)-arg(a));
  return ret>PI ? 2*PI-ret : ret;
}
// テヲツ卍づィツィツ暗・ツ崢榲」ツつ甘・ツ?エテ」ツ?ッテ・ツ青ォテ」ツ?ソテ」ツ??・ツ債甘ヲツ卍づィツィツ暗・ツ崢榲」ツつ甘・ツ?エテ」ツ?ッテ・ツ青ォテ」ツ?セテ」ツ?ェテ」ツ??
int quadrant(const P &a) {
  if (a.real() > 0 && a.imag() >= 0) return 0;
  if (a.real() <= 0 && a.imag() > 0) return 1;
  if (a.real() < 0 && a.imag() <= 0) return 2;
  return 3;
}
// テ」ツδュテ」ツδ静」ツつケテ」ツδ暗」ツ?ェティツァツ津・ツコツヲテヲツッツ氾ィツシツ?
bool cmpAngle(const P &a, const P&b) {
  int q1 = quadrant(a);
  int q2 = quadrant(b);
  if (q1 != q2) return q1 < q2;
  return cross(a,b)>0;
}
// テ」ツδ凖」ツつッテ」ツδ暗」ツδォテ」ツ?ョテ・ツ崢榲ィツサツ「
P rotate(P p, double ang) {
  return p * P(cos(ang), sin(ang));
}
// テ・ツ篠淌ァツつケテ・ツ堕ィテ」ツつ甘」ツ?ョテァツ崢エテァツキツ堙」ツ?ョテ・ツ崢榲ィツサツ「
L rotate(L l, double ang) {
  return L(rotate(l[0], ang),rotate(l[1], ang));
}

double signedLength(const P &p1, const P &p2, const P &p) {
  P pc = projection(L(p1,p2),p);
  double res = abs(pc-p1);
  if (dot(pc-p1,p2-p1)>0) return res;
  else return -res;
}

Res find_next(const P &ct, const L& s) {
  Res res;
  res.ang = INF;
  // vertex
  REP(i,N) {
    if (ct==g[i]) continue;
    REP(j,2) {
      if (s[j]==ct) continue;
      if (abs(g[i]-ct)<abs(s[j]-ct)) {
        if (sameang(g[i]-ct,s[j]-ct)) {
          if (ccw(ct,s[j],next(g,i)) == -1 ||
              ccw(ct,s[j],prev(g,i)) == -1) {
            // stuck
            Res t(g[i], s, 0);
            if (win(res,t,ct)) res = t;
          }
        } else {
          double ang = angle(g[i]-ct,s[j]-ct);
          Res t(g[i],L(ct+rotate(s[0]-ct,-ang),ct+rotate(s[1]-ct,-ang)),ang);
          if (win(res,t,ct)) res = t;
        }
      }
    }
  }
  // edge
  REP(i,N) {
    REP(j,2) {
      if (s[j]==ct) continue;
      vector<P> ps = crosspointSC(line(g,i),C(ct,abs(s[j]-ct)));
      FOR(it, ps) {
        if (sameang(*it-ct,s[j]-ct)) {
          P a = g[i];
          P b = next(g,i);
          P c = prev(g,i);
          if (abs(signedLength(ct,s[j],a) - signedLength(ct,s[j],b)) < EPS) continue;
          if (signedLength(ct,s[j],a) > signedLength(ct,s[j],b)) {
            swap(a,b);
            c = g[(i+2)%g.size()];
          }
          if (ccw(ct,*it,a) == 1) continue;
          if (ccw(ct,*it,a) != -1) {
            continue;
            if (ccw(ct,*it,c) == 1) continue;
          }
          // cout << ct << " " << s[j] << " " << a << " " << b << " :" << signedLength(ct,s[j],a) << " " << signedLength(ct,s[j],b) << endl;
          // cout << *it << endl;
          // cout << ccw(ct,*it,a) << endl;
          
          // cout << *it << endl;
          // stuck
          Res t(*it, s, 0);
          if (win(res,t,ct)) res = t;
        } else {
          // cout << *it << endl;
          double ang = angle(*it-ct,s[j]-ct);
          Res t(*it,L(ct+rotate(s[0]-ct,-ang),ct+rotate(s[1]-ct,-ang)),ang);
          // cout << res.ang << " " << ang << endl;
          if (win(res,t,ct)) res = t;
        }      
      }
    }
  }
  return res;
}
FILE *fp;
double scale = 10;
P diff(300, 300);
double WH = 500;
void outputLine(const L &l) {
  if (!fp) return;
  P a = l[0];
  P b = l[1];
  a = a*P(scale,0)+diff;
  b = b*P(scale,0)+diff;
  fprintf(fp,"line(%f,%f,%f,%f);\n",a.real(),WH-a.imag(),b.real(),WH-b.imag());  
}
void outputCircle(C c) {
  if (!fp) return;
  c.p = c.p*P(scale,0) + diff;
  c.r *= scale;
  fprintf(fp, "circle(%f,%f,%f);\n", c.p.real(), WH-c.p.imag(), c.r);
}


int main() {
  fp = fopen("data.js","w");
  while(cin>>l>>r>>N, l||r||N) {
    g.clear();
    double tang = r*2*PI;
    REP(i,N) g.push_back(pIN());
    REP(i,N) outputLine(line(g,i));
    L s(P(0,0),P(0,l));
    P ct(0,0);
    double ang = 0;
    outputLine(s);
    REP(i,1000) {
      Res ret = find_next(ct,s);
      // cout << ang << " " << ret.ang << " " << tang << endl;
      if (ang+ret.ang>=tang) {
        double ag = tang-ang;
        s[0] = ct+rotate(s[0]-ct,-ag);
        s[1] = ct+rotate(s[1]-ct,-ag);
        outputLine(s);
        break;
      }
      // cout << ang << " " << s  << ":" << ret.ang << " " << ret.s<< " " << ret.ct << endl;
      outputLine(ret.s);
      outputCircle(C(ct,l));
      ang += ret.ang;
      s = ret.s;
      ct = ret.ct;
    }
    printf("%.10f %.10f\n", s[0].real(), s[0].imag());
  }
}