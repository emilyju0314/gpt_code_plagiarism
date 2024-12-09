#include<bits/stdc++.h>
using namespace std ;

# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) (v).begin() , (v).end() , comp

# define ll long long
# define ld long double

# define line cout << "\n" ;
# define fast ios_base :: sync_with_stdio ( false ) ; cin.tie ( 0 ) ;

# define pii pair < int , int >
# define pll pair < ll , ll >

# define F first
# define S second

const int mod = 1e9 + 7 ;

const int dx[] = { -1 , 0 , 1 , 0 } ;
const int dy[] = { 0 , 1 , 0 , -1 } ;

void solve ( int test_case )
{
    int n , m , k ;
    cin >> n >> m >> k ;

    if ( n * m - 1 == k )
        cout << "YES" ;

    else cout << "NO" ;

    line ;
}

int main()
{
    int t = 1 ;
    cin >> t ;

    for ( int i = 1 ; i <= t ; i ++ )
    {
//        cout << "Case #" << i << ": " ;
        solve ( i ) ;
    }

    return 0 ;
}

/*



*/
