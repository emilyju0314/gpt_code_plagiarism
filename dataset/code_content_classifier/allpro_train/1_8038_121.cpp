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
#include <iterator>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
 
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())

typedef unsigned long long ull;
const int INF = (int)1e8;


int main(){
	int n;
	while(cin>>n,n){
		int ans = 0;
		FOR(i,n){
			int x,y,h,w; cin>>x>>y>>h>>w;
			int len = x+y+h;
			int a = max(0,min((len-1)/20 - 2,6));
			int b = min(6,((w-1)/5+1) * (w>=3));
		  if(max(a,b)!=6)ans += 600+200*max(a,b);
		}
		cout << ans << endl;

	}

	return 0;
}