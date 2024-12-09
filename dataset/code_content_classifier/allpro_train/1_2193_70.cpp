#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ud unsigned int
#define ll long long
#define ull unsigned long long
#define MAX_INF 0x3f
#define MAX_INF_VAL 0x3f3f3f3f
#define MAX_INF_VAL_LL 0x3f3f3f3f3f3f3f3f
//#define pi 3.141592653589
#define eps 1e-9
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
//#define p 2173412051LL
//#define sz 2

using namespace std;

template< typename T > void read( T &x ) {
	x = 0;
	char ch = getchar();
	ll f = 1;
	while( !isdigit( ch ) ) {
		if( ch == '-' )
		f *= -1;
		ch = getchar();
	}
	while( isdigit( ch ) ) {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	x *= f;
}

struct custom_hash {
    static uint64_t splitmix64( uint64_t x ) {
        x += 0x9e3779b97f4a7c15;
        x = ( x ^ ( x >> 30 ) ) * 0xbf58476d1ce4e5b9;
        x = ( x ^ ( x >> 27 ) ) * 0x94d049bb133111eb;
        return x ^ ( x >> 31 );
    }

    size_t operator() ( uint64_t x ) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64( x + FIXED_RANDOM );
    }
};

string s;
int cnt[ 4 ];
int sum[ 4 ];
int p[ 4 ];
int invp[ 4 ];

int main() {
	ios::sync_with_stdio( false );
	cin.tie( 0 ), cout.tie( 0 );
	int t;
	int n;
	cin >> t;
	while( t-- ) {
		cin >> s;
		n = s.size();
		string res;
		ll ans = -1;
		memset( cnt, 0, sizeof( cnt ) );
		for( int i = 0; i < n; ++i ) {
			if( s[ i ] == 'A' )
				s[ i ] = 0;
			else if( s[ i ] == 'N' )
				s[ i ] = 1;
			else if( s[ i ] == 'O' )
				s[ i ] = 2;
			else
				s[ i ] = 3;
			++cnt[ s[ i ] ];
		}
		for( int i = 0; i < 4; ++i )
			p[ i ] = i;
		do {
			string now;
			ll tmp = 0;
			vector< int > fk[ 4 ];
			for( int i = 0, k = 0; i < 4; ++i ) {
				int v = p[ i ];
				char c;
				if( v == 0 )
					c = 'A';
				else if( v == 1 )
					c = 'N';
				else if( v == 2 )
					c = 'O';
				else
					c = 'T';
				for( int j = 0; j < cnt[ v ]; ++j, ++k ) {
					now.push_back( c );
					fk[ v ].push_back( k );
				}
			}
			for( int i = 0; i < 4; ++i )
				invp[ p[ i ] ] = i;
			string nmsl = s;
			for( int i = 0; i < 4; ++i ) {
				string str;
				memset( sum, 0, sizeof( sum ) );
				for( int j = 0; j < n; ++j ) {
					int v = nmsl[ j ];
					if( invp[ v ] <= i ) {
						tmp += j - fk[ v ][ sum[ v ]++ ];
						str.push_back( v );
					}
				}
				for( int j = 0; j < n; ++j ) {
					int v = nmsl[ j ];
					if( invp[ v ] > i ) {
						str.push_back( v );
					}
				}
				swap( nmsl, str );
			}
			if( tmp > ans ) {
				swap( ans, tmp );
				swap( res, now );
			}
		} while( next_permutation( p, p + 4 ) );
		cout << res << '\n';
	}
	return 0;
}