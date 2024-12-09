#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

typedef istringstream ISS;
typedef ostringstream OSS;
typedef vector<string> VS;
typedef int INT;
typedef vector<INT> VI;
typedef vector<VI> VVI;
typedef pair <INT, INT> II;
typedef vector <II> VII;

template<class T> ostream& operator << ( ostream& os, vector<T> v ) {
    for ( typename vector<T>::iterator it_i = v.begin(); it_i != v.end(); ++it_i ) {
        os << *it_i << ", ";
    }
    return os;
}


class CPoint;
typedef CPoint CVector2D;
class CSegment;
typedef vector <CSegment> CSegments;
double GetSquare( double );
bool Equal( double, double );
bool LessthanEqual( double, double );
double GetCrossProduct( double, double, double, double );
double GetCrossProduct( CPoint, CPoint );
double GetDotProduct( double, double, double, double );
double GetDotProduct( CPoint, CPoint );
double GetGradientFromTwoPoints( CPoint, CPoint );
int CheckCounterClockWise( CPoint, CPoint, CPoint );
bool Intersect( CPoint, CPoint, CPoint, CPoint );
bool Intersect( CSegment, CSegment );
CPoint GetCrossPoint( CSegment, CSegment );
double GetLength( CPoint, CPoint );
double GetDistance( CPoint, CPoint );
double GetDistance( CSegment, CPoint );
CPoint GetLowestY( CPoint, CPoint );
class CPoint {
public:
    double x, y;
    CPoint( double x, double y ): x(x), y(y) {}
    CPoint(): x(0), y(0) {};
    double getNorm() {
        return x * x + y * y;
    }
    double getAbs() {
        return sqrt( getNorm() );
    }
    CPoint operator + ( CPoint p ) {
        return CPoint( x + p.x, y + p.y );
    }
    CPoint operator - ( CPoint p ) {
        return CPoint( x - p.x, y - p.y );
    }
    CPoint operator * ( double k ) {
        return CPoint( x * k, y * k );
    }
    bool operator < ( const CPoint& p ) const {
        if ( x < p.x ) return true;
        return x == p.x ? y < p.y : false;
    }
};
CPoint operator * ( double k, CPoint p ) {
    return CPoint( p.x * k, p.y * k );
}
ostream& operator << ( ostream& os, CPoint p0 ) {
    os << "(" << p0.x << ", " << p0.y << ")";
    return os;
}
class CSegment {
public:
    CPoint a, b;
    CSegment( int x1, int y1, int x2, int y2 ): a(CPoint( x1, y1 )), b(CPoint( x2, y2 )) {}
    CSegment( CPoint a, CPoint b ): a(a), b(b) {}
    CSegment() {}
    double getGradient() {
        return GetGradientFromTwoPoints( a, b );
    }
    double getLength() {
        return GetLength( a, b );
    }
    double getMinX() {
        return min( a.x, b.x );
    }
    double getMinY() {
        return min( a.y, b.y );
    }
    double getMaxX() {
        return max( a.x, b.x );
    }
    double getMaxY() {
        return max( a.y, b.y );
    }
    bool operator < ( const CSegment& s ) const {
        return b.y > s.b.y;
    }
    
};
ostream& operator << ( ostream& os, CSegment s0 ) {
    os << "(" << s0.a << " - " << s0.b << ")";
    return os;
}
class CCircle {
public:
    CPoint p;
    int r;
    CCircle(): p( 0, 0 ), r(0) {}
    CCircle( int x, int y, int r ): p(x, y), r(r) {}
    CCircle( CPoint p, int r ): p(p), r(r) {}
};
ostream& operator << ( ostream& os, CCircle c0 ) {
    os << "{(" << c0.p.x << ", " << c0.p.y << "), r = " << c0.r << ")";
    return os;
}
class CTriangle {
public:
    CPoint a;
    CPoint b;
    CPoint c;
    CTriangle( int x1, int y1, int x2, int y2, int x3, int y3 ):
        a(CPoint(x1,y1)), b(CPoint(x2,y2)), c(CPoint(x3,y3)) {}
    CTriangle( CPoint a, CPoint b, CPoint c ):
        a(a), b(b), c(c) {}
    double getArea() {
        CSegment AB( a, b );
        CSegment BC( b, c );
        CSegment CA( c, a );
        double aa = AB.getLength();
        double bb = BC.getLength();
        double cc = CA.getLength();
        double s = ( aa + bb + cc ) / 2.0;
        return sqrt( s * ( s - aa ) * ( s - bb ) * ( s - cc ) );
    }
};
ostream& operator << ( ostream& os, CTriangle t0 ) {
    os << "{" << t0.a << ", " << t0.b << ", " << t0.c << "}";
    return os;
}
const double EPS = 1e-9;
double GetSquare( double x ) {
    return x * x;
}
bool Equal( double a, double b ) {
    return fabs( b - a ) < EPS;
}
bool LessthanEqual( double a, double b ) {
    return a < b ? true : ( fabs( b - a ) < EPS );
}
double GetCrossProduct( double x1, double y1, double x2, double y2 ) {
    return x1 * y2 - y1 * x2;
}
double GetCrossProduct( CPoint a, CPoint b ) {
    return GetCrossProduct( a.x, a.y, b.x, b.y );
}
double GetDotProduct( double x1, double y1, double x2, double y2 ) {
    return x1 * x2 + y1 * y2;
}
double GetDotProduct( CPoint a, CPoint b ) {
    return GetDotProduct( a.x, a.y, b.x, b.y );
}
bool Intersect( CPoint p1, CPoint p2, CPoint p3, CPoint p4 ) {
    bool f1 = LessthanEqual( CheckCounterClockWise( p1, p2, p3 ) * CheckCounterClockWise( p1, p2, p4 ), 0 );
    bool f2 = LessthanEqual( CheckCounterClockWise( p3, p4, p1 ) * CheckCounterClockWise( p3, p4, p2 ), 0 );
    return f1 && f2;
}
bool Intersect( CSegment s1, CSegment s2 ) {
    return Intersect( s1.a, s1.b, s2.a, s2.b );
}
bool Contain( CTriangle a, CPoint p ) {
    CVector2D AP = p - a.a;
    CVector2D BP = p - a.b;
    CVector2D CP = p - a.c;
    CVector2D AB = a.b - a.a;
    CVector2D BC = a.c - a.b;
    CVector2D CA = a.a - a.c;
    if ( GetCrossProduct( AP, AB ) < 0.0
         && GetCrossProduct( BP, BC ) < 0.0
         && GetCrossProduct( CP, CA ) < 0.0 ) return true;
    if ( GetCrossProduct( AP, AB ) > 0.0
         && GetCrossProduct( BP, BC ) > 0.0
         && GetCrossProduct( CP, CA ) > 0.0 ) return true;
    return false;
}
bool Contain( CCircle cir, CTriangle tri ) {
    double maxd = 0.0;
    maxd = max( maxd, GetDistance( tri.a, cir.p ) );
    maxd = max( maxd, GetDistance( tri.b, cir.p ) );
    maxd = max( maxd, GetDistance( tri.c, cir.p ) );
    return LessthanEqual( maxd, cir.r );
}
bool Contain( CTriangle tri, CCircle cir ) {
    double mind = GetDistance(CSegment(tri.a, tri.b), cir.p);
    mind = min( mind, GetDistance(CSegment(tri.b, tri.c), cir.p) );
    mind = min( mind, GetDistance(CSegment(tri.c, tri.a), cir.p) );
    return LessthanEqual( cir.r, mind );
}
double GetGradientFromTwoPoints( CPoint a, CPoint b ) {
    return ( b.y - a.y ) / ( b.x - a.x );
}
const int COUNTER_CLOCKWISE = 1;
const int CLOCKWISE = -1;
const int ONLINE_BACK = 2;
const int ONLINE_FRONT = -2;
const int ON_SEGMENT = 0;
int CheckCounterClockWise( CPoint p0, CPoint p1, CPoint p2 ) {
    CVector2D a = p1 - p0;
    CVector2D b = p2 - p0;
    if ( GetCrossProduct( a, b ) > EPS ) return COUNTER_CLOCKWISE;
    if ( GetCrossProduct( a, b ) < EPS ) return CLOCKWISE;
    if ( GetDotProduct( a, b ) < -EPS ) return ONLINE_BACK;
    if ( a.getNorm() < b.getNorm() ) return ONLINE_FRONT;
    return ON_SEGMENT;
}
CPoint GetCrossPoint( CSegment s1, CSegment s2 ) {
    CVector2D base = s2.b - s2.a;
    double d1 = abs( GetCrossProduct( base, s1.a - s2.a ) );
    double d2 = abs( GetCrossProduct( base, s1.b - s2.a ) );
    double t = d1 / ( d1 + d2 );
    return s1.a + ( s1.b - s1.a ) * t;
}
double GetLength( CPoint a, CPoint b ) {
    return sqrt( GetSquare( a.x - b.x ) + GetSquare( a.y - b.y ) );
}
double GetDistance( CPoint a, CPoint b ) {
    return GetLength( a, b );
}
CPoint GetLowestY( CPoint a, CPoint b ) {
    if ( a.y == b.y ) return a.x < b.x ? a : b;
    return a.y < b.y ? a : b;
}
double GetDistance( CSegment seg, CPoint p ) {
    if ( GetDotProduct( seg.b - seg.a, p - seg.a ) < EPS ) return (p - seg.a).getAbs();
    if ( GetDotProduct( seg.a - seg.b, p - seg.b ) < EPS ) return (p - seg.b).getAbs();
    return fabs( GetCrossProduct( seg.b - seg.a, p - seg.a ) ) / ( seg.b - seg.a ).getAbs();
}
bool CheckIntersect( CSegment seg, CCircle c ) {
    bool f1 = LessthanEqual( ( c.p - seg.a ).getAbs(), c.r );
    bool f2 = LessthanEqual( ( c.p - seg.b ).getAbs(), c.r );
    if ( f1 ^ f2 ) return true;
    return LessthanEqual( GetDistance( seg, c.p ), c.r ) && ( ! f1 && ! f2 );
}
bool CheckIntersect( CTriangle tri, CCircle cir ) {
    return CheckIntersect( CSegment( tri.a, tri.b ), cir )
        || CheckIntersect( CSegment( tri.b, tri.c ), cir )
        || CheckIntersect( CSegment( tri.c, tri.a ), cir );
}


const string DAI = "dai-kichi";
const string CHU = "chu-kichi";
const string KIC = "kichi";
const string SYO = "syo-kichi";
const string KYO = "kyo";

string solve( CSegment s0, CSegment s1, CSegment s2 ) {
    if ( ! Intersect( s0, s1 ) || ! Intersect( s1, s2 ) || ! Intersect( s2, s0 ) ) {
        return KYO;
    }
    CTriangle tri( GetCrossPoint( s0, s1 ), GetCrossPoint( s1, s2 ), GetCrossPoint( s2, s0 ) );
    double area = tri.getArea();
    if ( fabs( area ) < 1e-9 ) {
        return KYO;
    } else if ( area < 100000.0 ) {
        return SYO;
    } else if ( area < 1000000.0 ) {
        return KIC;
    } else if ( area < 1900000.0 ) {
        return CHU;
    }
    return DAI;
}

int main() {
    int x1, y1, x2, y2;
    while ( cin >> x1 >> y1 >> x2 >> y2 ) {
        if ( x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 ) break;
        CSegment S0( x1, y1, x2, y2 );
        cin >> x1 >> y1 >> x2 >> y2;
        CSegment S1( x1, y1, x2, y2 );
        cin >> x1 >> y1 >> x2 >> y2;
        CSegment S2( x1, y1, x2, y2 );
        cout << solve( S0, S1, S2 ) << endl;
    }
    return 0;
}