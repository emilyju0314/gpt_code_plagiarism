#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 9999999

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;



typedef int Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;

Matrix mul(const Matrix &a, const Matrix &b){
	Matrix res(a.size(), Array(b[0].size()));
	REP(i, a.size()){
		REP(j, b[0].size()){
			REP(k, a[0].size()){
				res[i][j] |= a[i][k] & b[k][j];
			}
		}
	}
	return res;
}

Matrix powMat(const Matrix &a, int b){
	if(!b){
		Matrix res(a.size(), Array(a[0].size(), 0));
		REP(i, a.size()) res[i][i] = 1;
		return res;
	}
	Matrix res = powMat(mul(a, a), b / 2);
	if(b&1) res = mul(res, a);
	return res;
}


int main(void){
	int N, M, Z;
	while(cin>>N>>M>>Z, N){
		vector<pair<int, int> > g;
		g.push_back(make_pair(0,0));
		REP(i,M){
			int s, d;
			cin >> s >> d;
			s--; d--;
			g.push_back(make_pair(s,d));
			g.push_back(make_pair(d,s));
		}
		Matrix a(g.size(), Array(g.size(), 0));
		REP(i, g.size()){
			REP(j, g.size()){
				if(!j) continue;
				if(i == j) continue;
				if(g[i].first == g[j].second && g[i].second != g[j].first){
					a[i][j] = 1;
				}
			}
		}
		Matrix b = powMat(a, Z);
		int f = 0;
		REP(i, g.size()){
			if(g[i].first == N-1){
				if(b[0][i]) f = 1;
			}
		}
		if(f) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}