#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define dl double long

using namespace std;

const int N = 5e5 + 7;
const long long mod = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n,k,m;
    cin >> n >> k >> m;
    vector < int > a(m + 1 , 0);
    for( int i = 1; i <= m; i++ ){
        cin >> a[i];
    }
    if( (n - m) % (k - 1) ){
        cout << "NO\n";
        return;
    }
    int x = n - m;
    int y = 0;
    for( int i = 1 , j = 1; i <= n; i++ ){
        if( j <= m && a[j] == i ){
            if( x >= k / 2 && y >= k / 2 ){
                cout << "YES\n";
                return;
            }
            j++;
        }else{
            y++,x--;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    int T;
    cin >> T;
    while( T-- ){
        solve();
    }
}
