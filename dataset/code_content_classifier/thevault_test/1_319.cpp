long long gauss ( vector < vector < long long > > a, vector < long long > & ans, long long mod)
{
    int n = ( int ) a. size ( ) ;
    int m = ( int ) a [ 0 ] . size ( ) - 1 ;
    vector < int > where ( n, - 1 ) ;
    for ( int col = 0, row = 0 ; col < m && row < n ; ++ row )
    {
        int sel = col ;
        for ( int i = col ; i < m ; ++ i )
            if ( abs ( a [ row ] [ i ] ) > abs ( a [ row ] [ sel ] ) )
                sel = i ;
        if ( abs ( a [ row ] [ sel ] ) == 0 )
            continue ;
        for ( int i = 0 ; i < n ; ++ i )
            swap ( a [ i ] [ col ], a [ i ] [ sel ] ) ;
        where [ row ] = col ;
//print3(row,col,a[row][col]);
        for ( int i = 0 ; i < n ; ++ i )
            if ( i != row )
            {
                long long c = a [ row ] [ col ];
                long long d = a [ i ][ col ];
                for ( int j = col ; j <= m ; ++ j )
                {
                    a [ i ] [ j ] = (c*a[i][j]-d*a[row][j])%mod ;
                    a [i][j]=(a[i][j]+mod)%mod;
                }
            }
        ++ col ;
    }
    ans. assign ( m, 0 ) ;
    for ( int i = 0 ; i < n ; ++ i )
        if ( where [ i ] != - 1 )
            ans [ where[i] ] = (a [ i ] [ m ]*
                                BigMod( a [ i ] [ where[i] ],mod-2,mod))%mod ;
    for ( int i = 0 ; i < n ; ++ i )
    {
        long long sum = 0 ;
        for ( int j = 0 ; j < m ; ++ j )
        {
            sum += (ans [ j ] * a [ i ] [ j ])%mod ;
            sum %= mod;
        }
        if ( abs ( sum - a [ i ] [ m ] ) != 0 ) //no solution
            return 0 ;
    }
    long long totalans=1;
    for ( int i = 0 ; i < m ; ++ i )
        if ( where [ i ]== - 1 ) //use mod if necessary
            totalans=(totalans* mod)%1000000007;
    return totalans ;
}