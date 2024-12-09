////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>
//#include <chrono>
//#include <random>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N = 1e4;
LL dp[N + 5];
LL pref[N + 5];
LL s[N + 5], p[N + 5];

void hora(int tc) {
	int c,n,m;
	cin>>c>>n>>m;
	for(int i = 0;i < n;i++) cin>>s[i]>>p[i];
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	for(int i = 0;i < n;i++) {
		for(int j = c;j >= s[i];j--) if(dp[j - s[i]] != -1) dp[j] = max(dp[j], dp[j - s[i]] + p[i]);
	}
	pref[0] = 0;
	for(int i = 1;i <= c;i++) pref[i] = max(pref[i - 1], dp[i]);
	for(int i = 1;i <= m;i++) {
		cout<<pref[c / i] * i<<endl;
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}



