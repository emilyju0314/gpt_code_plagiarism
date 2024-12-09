#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )
#define EACH( v, c ) for ( auto &v : c )

#define ITER( c ) __typeof( (c).begin() )
#define IREP( c, it ) for ( ITER(c) it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

const double EPS = 1e-9;

struct Point
{
	double x, y;

	Point() : x( 0 ), y( 0 ) {}
	Point( const double x, const double y ) : x( x ), y( y ) {}
	Point( const Point &a ) : x( a.x ), y( a.y ) {}
	
	Point operator + ( const Point &a ) const
	{
		return Point( x + a.x, y + a.y );
	}

	Point& operator += ( const Point &a ) 
	{
		x += a.x;
		y += a.y;

		return *this;
	}

	Point operator - ( const Point &a ) const
	{
		return Point( x + ( -a.x ), y + ( -a.y ) );
	}

	Point& operator -= ( const Point &a )
	{
		x -= a.x;
		y -= a.y;

		return *this;
	}

	Point operator * ( const double &a ) const
	{
		return Point( x * a, y * a );
	}

	Point& operator *= ( const double &a )
	{
		x *= a;
		y *= a;

		return *this;
	}

	Point operator / ( const double &a ) const
	{
		return Point( x / a, y / a );
	}

	Point& operator /= ( const double &a )
	{
		x /= a;
		y /= a;

		return *this;
	}

	bool operator < ( const Point &a ) const
	{
		return x == a.x ? y < a.y : x < a.x;
	}

	double abs() const
	{
		return sqrt( pow( x, 2. ) + pow( y, 2. ) );
	}
};

// 二点間の距離
double distance( const Point &a, const Point &b )
{
	return sqrt( pow( a.x - b.x, 2. ) + pow( a.y - b.y, 2. ) );
}

// 内積（ドット積）
double dot( const Point &a, const Point &b )
{
	return a.x * b.x + a.y * b.y;
}

// 外積（クロス積）
double cross( const Point &a, const Point &b )
{
	return a.x * b.y - a.y * b.x;
}

// 凸包を求める（ Graham Scan ）
vector< Point > convexHull( vector< Point > ps )
{
	const int N = ps.size();

	sort( ALL( ps ) );

	int k = 0;
	vector< Point > convex( N * 2 );

	for ( int i = 0; i < N; i++ )
	{
		while ( 2 <= k && cross( convex[ k - 1 ] - convex[ k - 2 ], ps[i] - convex[ k - 1 ] ) <= EPS )
		{
			k--;
		}

		convex[ k++ ] = ps[i];
	}

	for ( int i = N - 2, t = k; 0 <= i; i-- )
	{
		while ( t < k && cross( convex[ k - 1 ] - convex[ k - 2 ], ps[i] - convex[ k - 1 ] ) <= EPS )
		{
			k--;
		}

		convex[ k++ ] = ps[i];
	}

	convex.resize( k - 1 );

	return convex;
}

double enclosing( Point A, Point B, Point C )
{
	double a = distance( B, C ), b = distance( C, A ), c = distance( A, B );

	if ( dot( B - A, C - A ) <= EPS ||
		 dot( A - B, C - B ) <= EPS ||
		 dot( A - C, B - C ) <= EPS )
	{
		return max( a, max( b, c ) ) / 2;
	}
	else
	{
		double cosA = ( pow( b, 2. ) + pow( c, 2. ) - pow( a, 2. ) ) / ( 2 * b * c );
		double sinA = sin( acos( cosA ) );

		return abs( a / sinA ) / 2;
	}
}

vector<double> convexHullRs( vector< vector< Point > > polygons )
{
	vector<double> res;

	EACH( polygon, polygons )
	{
		vector< Point > convex( convexHull( polygon ) );
		const int N = convex.size();

		double r = 0;

		REP( i, 0, N )
		{
			REP( j, i + 1, N )
			{
				REP( k, j + 1, N )
				{
					r = max( r, enclosing( convex[i], convex[j], convex[k] ) );
				}
			}
		}

		res.PB( r );
	}

	return res;
}

template < typename T >
vector< T > diffSet( const vector< T > &whole, const vector<bool> &used )
{
	vector< T > res;

	REP( i, 0, whole.size() )
	{
		if ( used[i] )
		{
			continue;
		}

		res.PB( whole[i] );
	}

	return res;
}

bool valid( VI holes, vector<double> rs )
{
	sort( ALL( holes ) );
	sort( ALL( rs ) );

	int last = -1;

	REP( i, 0, rs.size() )
	{
		bool ok = false;

		REP( j, last + 1, holes.size() )
		{
			if ( rs[i] <= holes[j] + EPS )
			{
				ok = true;
				last = j;

				break;
			}
		}

		if ( !ok )
		{
			return false;
		}
	}

	return true;
}

VI matching( const VI &holes, const vector<double> &rs )
{
	const int N = holes.size(), M = rs.size();

	VI res;
	vector<bool> closed( N, false ), entered( M, false );

	REP( i, 0, M )
	{
		REP( j, 0, N )
		{
			if ( closed[j] || entered[i] || holes[j] < rs[i] - EPS )
			{
				continue;
			}

			vector<bool> nextClosed( closed ), nextEntered( entered );
			nextClosed[j] = true;
			nextEntered[i] = true;

			if ( valid( diffSet( holes, nextClosed ), diffSet( rs, nextEntered ) ) )
			{
				entered = nextEntered;
				closed = nextClosed;
				res.PB( j + 1 );

				break;
			}
		}
	}

	return res.size() == M ? res : VI();
}

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int n, m;
	cin >> n >> m;

	VI holes( n );

	EACH( hole, holes )
	{
		cin >> hole;
	}

	vector< vector< Point > > players( m );

	EACH( player, players )
	{
		int p;
		cin >> p;

		player.resize( p );

		EACH( point, player )
		{
			cin >> point.x >> point.y;
		}
	}

	VI res( matching( holes, convexHullRs( players ) ) );

	if ( res.size() < m )
	{
		cout << "NG" << endl;
	}
	else
	{
		EACH( tmp, res )
		{
			cout << tmp << endl;
		}
	}

	return 0;
}