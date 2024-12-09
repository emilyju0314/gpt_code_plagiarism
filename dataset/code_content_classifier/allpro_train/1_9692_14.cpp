#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<complex>
#include<cmath>
using namespace std;

#define REP(i,N) for(int i=0;i<(int)(N);++i)
#define ALL(v) (v).begin(),(v).end()

typedef complex<double> P;
const double EPS = 1e-10;
const double PI = 4.0 * atan2(1, 1);

namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

inline double dot(P a, P b) {return real( conj(a)*b);}
inline double cross(P a, P b) {return imag( conj(a)*b);}
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > EPS)   return +1;       // counter clockwise
  if (cross(b, c) < -EPS)   return -1;       // clockwise
  if (dot(b, c) < -EPS)     return +2;       // c--a--b on line
  if (norm(b) + EPS < norm(c)) return -2;       // a--b--c on line
  return 0;
}

bool IsIntersectSS(P a1, P a2, P b1, P b2) {
  return ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 &&
    ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0;
}

bool IsIntersectSP(P a, P b, P c) {
  return (abs(a-c) + abs(c-b) < abs(a-b) + EPS);
}

P IntersectionLL(P a1,P a2,P b1, P b2) {
  double A = cross(b2 - b1, a2 - a1);
  double B = cross(b2 - b1, b2 - a1);
  if (abs(A) < EPS && abs(B) < EPS) return a1; // same line
//  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return a1 + B / A * (a2 - a1);
}

typedef vector<vector<int> > Graph;

Graph Arrangement(const vector<P> &from, const vector<P> &to, vector<P> &ps) {
  REP(i, from.size()) {
    ps.push_back( from[i] );
    ps.push_back( to[i] );
    REP(j, i) {
      if( IsIntersectSS( from[i], to[i], from[j], to[j]) )
        ps.push_back( IntersectionLL(from[i], to[i], from[j], to[j]));
    }
  }
  sort(ALL(ps));
  ps.erase(unique(ALL(ps)), ps.end());
  Graph g(ps.size());

  REP(i, from.size()) {
    vector< pair<double, int> > onlines;
    REP(j, ps.size()) {
      if( IsIntersectSP(from[i], to[i], ps[j]) )
        onlines.push_back( make_pair(norm(from[i] - ps[j]), j) );
    }
    sort( ALL(onlines) );
    for(int j = 0; j + 1 < onlines.size(); j++) {
      int a = onlines[j].second;
      int b = onlines[j+1].second;
      g[a].push_back(b);
      g[b].push_back(a);
    }
  }
  return g;
}

double memo[1024][1024];
struct State {
  int pos, prev;
  double cost;

  bool operator<(const State& t) const {
    return cost > t.cost;
  }
  double &ref() {
    return memo[pos][prev];
  }
};

int indexOf(const vector<P>& ps, P p) {
  REP(i, ps.size()) {
    if( norm( ps[i] - p ) < EPS )
      return i;
  }
  return -1;
}

double Arg(P a, P b, P c) {
  if( norm(b - a) < EPS ) return 0;
//   if( ccw(a, b, c) == 2 || ccw(a, b, c) == 0 ) {return 0;}
  double theta = arg( (c - b) / (b - a) );
  theta = abs(theta);
//   if( dot( b - a, c - b) < -EPS ) theta += PI / 2;
  return theta;
}

double solve(Graph &g, vector<P> &ps, int si, int gi) {
  REP(i, 1024) REP(j, 1024) memo[i][j] = 1e10;

  priority_queue< State > up;

  State s = (State){si, si,0};
  up.push(s);
  s.ref() = 0;
  while( !up.empty() ) {
    s = up.top(); up.pop();

    if( s.pos == gi )
      return s.cost;

    for(int i = 0; i < g[s.pos].size(); i++) {
      State next = s;
      next.pos = g[s.pos][i];
      next.prev = s.pos;
      next.cost += Arg( ps[s.prev], ps[s.pos], ps[next.pos] );
      if( next.ref() > next.cost + EPS ) {
        next.ref() = next.cost;
        up.push( next );
      }
    }
  }
  return -1;
}

int main() {
  for(;;) {
    int N; scanf("%d", &N);
    if( N == 0 ) break;
    vector<P> from, to;
    REP(i, N) {
      int a, b, c, d;
      scanf("%d%d%d%d", &a, &b, &c, &d);
      from.push_back( P(a, b) );
      to.push_back( P(c, d) );
    }
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    P start(a, b);
    P goal(c, d);

    vector<P> ps;
    Graph g = Arrangement(from, to, ps);

    int si = indexOf( ps, start );
    int gi = indexOf( ps, goal );
    
    double rad = solve(g, ps, si, gi);
    if( rad < -0.5 ) {
      cout << -1 << endl;
    } else {
      printf("%.8f\n", rad * 180  / PI);
    }
  }
}