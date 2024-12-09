#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef priority_queue<int> PQ;
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;


int N, K;
VI X(210), Y(210);

double f(double x, double y) {//答えのカウント

	vector<double>dis(N);
	REP(i, N) {
		double a = X[i], b = Y[i];
		
		dis[i] = pow((a - x)*(a - x) + (b - y)*(b - y), 0.5);
	}

	rSORT(dis);
	double res = 0;
	REP(i, K)res += dis[i];
	return res;

}

double g(double x) {//fの最適化

	double L = -1000, R = 1000;
	REP(i, 100) {
		double m1 = (L * 2 + R) / 3;
		double m2 = (L + R * 2) / 3;

		if (f(x, m1) > f(x, m2))L = m1;
		else R = m2;
	}
	return f(x, L);
}


signed main(){
cin.tie(0);
ios::sync_with_stdio(false);


	cin >> N >> K;
	REP(i, N)cin >> X[i] >> Y[i];

	double L = -1000, R = 1000;
	REP(i, 100) {
		double m1 = (L * 2 + R) / 3;
		double m2 = (L + R * 2) / 3;

		if (g(m1) > g(m2))L = m1;
		else R = m2;
	}
	
	printf("%.9f\n", g(L));

	return 0;
}


