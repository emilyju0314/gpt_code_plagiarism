#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define EPS 1e-10
#define MAX_N 100100
#define MAX_M 100100

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

string table[] = { "AADINNUY", "AIZUNYAN" };
string d;

int main(){
	cin >> d;
	if (d.size() >= 8){
		REP(i, d.size() - 7){
			string s = d.substr(i, 8);
			sort(ALL(s));
			if (s == table[0]){
				REP(j, 8){
					d[i + j] = table[1][j];
				}
				i += 7;
			}
		}
	}
	cout << d << endl;
}