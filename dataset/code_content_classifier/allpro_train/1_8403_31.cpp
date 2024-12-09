#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second
#define SIZE( A )   int( ( A ).size( ) )
#define ALL( A )    ( A ).begin( ), ( A ).end( )
#define ALLR( A )   ( A ).rbegin( ), ( A ).rend( )

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double              lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 1e5 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;
const lf EPS = 1e-9;

struct pt {
  lf x, y;
  pt( ) { }
  pt( lf x, lf y ) : x( x ), y ( y ) { }
};

inline lf x( pt P ) { return P.x; }
inline lf y( pt P ) { return P.y; }

istream& operator >> ( istream& in, pt& p ) {
  lf x,y; in >> x >> y;
  p = pt(x,y); return in;
}

ostream& operator << ( ostream& out, const pt& p ) {
  out << double(p.x) << " " << double(p.y);
  return out;
}

pt operator + ( const pt& A, const pt& B ) {
  return pt( x(A)+x(B), y(A)+y(B) );
}

pt operator - ( const pt& A, const pt& B ) {
  return pt( x(A)-x(B), y(A)-y(B) );
}

pt operator * ( const lf& B, const pt& A ) {
  return pt( x(A)*B, y(A)*B );
}

pt operator * ( const pt& A, const lf& B ) {
  return pt( x(A)*B, y(A)*B  );
}

pt operator / ( const pt& A, const lf& B ) {
  return { x(A)/B, y(A)/B };
}

inline lf dot( pt A, pt B ) {
  return x(A)*x(B) + y(A)*y(B);
}

inline lf cross( pt A, pt B ) {
  return x(A)*y(B) - y(A)*x(B);
}

inline lf norm( pt A ) {
  return x(A)*x(A) + y(A)*y(A);
}

inline lf abs( pt A ) {
  return sqrt( norm(A) );
}

inline lf dist ( pt A, pt B ) { return abs( B - A ); }

inline bool same ( lf a, lf b ) {
  return a+EPS > b && b+EPS > a;
}

inline bool samePt ( pt A, pt B ) {
  return same ( x(A), x(B) ) && same ( y(A), y(B) );
}

lf distToLine (pt p, pt A, pt B, pt &c) {
  lf u = dot( p-A , B-A ) / norm( B-A );
  c = A + u*( B-A );
  return dist( p , c );
}

bool circleLineIntersection( pt c, lf r, pt A, pt B, pt &p1, pt &p2 ) {
  pt t;
  lf u = distToLine( c, A, B, t );
  if( u > r+EPS ) {
    return false;
  }
  pt v = (B-A)/abs(B-A);
  lf d = sqrt(r*r - u*u);
  p1 = t + d*v;
  p2 = t - d*v;
  return true;
}

int q;
pt c, p1, p2;
lf r;

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif
  cout << fixed << setprecision(8);
  cin >> c >> r >> q;
  for( int i = 0; i < q; ++i ) {
    pt A,B; cin >> A >> B;
    if( circleLineIntersection( c, r, A, B, p1, p2 ) ) {
      if( same( p1.x, p2.x ) ) {
        if( p1.y > p2.y+EPS ) {
          swap( p1,p2 );
        }
      }
      if( p1.x > p2.x+EPS ) {
        swap( p1,p2 );
      }
      cout << p1 << " " << p2 << '\n';
    }
    else {
      assert( false );
    }
  }
  return 0;
}