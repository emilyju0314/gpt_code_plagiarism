#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#include<set>
#include<random>
#include<stdio.h>
#include<map>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 11451419198109311;
const long double pi = 3.1415926535897932384626433;
typedef pair<int, int> P;
struct edge { int to, cost; };

signed main() {
	int n, a, b, c; cin >> n >> a >> b >> c;
	cout << n - a - b + c << endl;
}
