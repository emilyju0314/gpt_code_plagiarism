#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (int)(count); i++)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 100000 ;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

using namespace std;

int main()
{
	int t; cin>>t;
	bool nl = false;
	while(t--){
		int a[9][9]; FOR(i,9)FOR(j,9) cin>>a[i][j];
		bool b[9][9] = {};
		FOR(i,3)FOR(j,3){
			int b2[10] ={};
			FOR(k,3)FOR(l,3) b2[a[i*3+k][j*3+l]]++;
			FOR(k,10) if(b2[k] >= 2){
				FOR(l,3)FOR(m,3)
					if(a[i*3+l][j*3+m] == k) b[i*3+l][j*3+m] = true;
			}
		}
		FOR(i,9){
			int b2[10] ={};
			FOR(j,9) b2[a[i][j]]++;
			FOR(k,10) if(b2[k] >= 2){
				FOR(j,9) if(a[i][j] == k) b[i][j] = true;
			}
		}
		FOR(j,9){
			int b2[10] ={};
			FOR(i,9) b2[a[i][j]]++;
			FOR(k,10) if(b2[k] >= 2){
				FOR(i,9) if(a[i][j] == k) b[i][j] = true;
			}
		}

		if(nl) puts("");
		nl = true;
		FOR(i,9){
			FOR(j,9) printf("%c%d",b[i][j]?'*':' ',a[i][j]);
			puts("");
		}
	}
	return 0;
}