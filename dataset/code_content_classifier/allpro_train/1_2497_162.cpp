//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

ld const PI = acos(-1) ;
int const N = 100 + 5 , MAX = 5e5 ;
int n , res[N] ;
ld x[N] , y[N] ;

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;
	for (int i = 0 ; i < n ; i ++) cin >> x[i] >> y[i] ;

	cout << fixed << setprecision(10) ;

	for (int i = 0 ; i < MAX ; i ++) {
		ld xx = (ld)cos(2 * PI / MAX * i) * 1e13 , yy = (ld)sin(2 * PI / MAX * i) * 1e13 ;

		ld mn = 1e30 + 20 ;
		int best = 0 ;

		for (int j = 0 ; j < n ; j ++) {
			ld dist = (xx - x[j]) * (xx - x[j]) + (yy - y[j]) * (yy - y[j]) ;
			if (dist < mn) mn = dist , best = j ;
		}

		res[best] ++ ;
	}

	for (int i = 0 ; i < n ; i ++) cout << (ld)res[i] / MAX << '\n' ;
}