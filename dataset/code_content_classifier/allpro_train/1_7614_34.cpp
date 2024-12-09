#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using ll=long long;
using R=long double;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

// Problem Specific Parameter:

vector<int> seq[55];
map<string,int> str2idx;

string bnf[55];
string AGCT="ATGC";

void func(int i,int n){
	stringstream ss(bnf[i]);
	string tmp;
	
	ss >> tmp;
	tmp = tmp.substr(0,tmp.size()-1);
	str2idx[tmp] = i;

	while(ss >> tmp){
		if(tmp[0]=='['){
			tmp = tmp.substr(1,tmp.size()-2);
			int val = 0;
			for(auto &mark:tmp) rep(j,4) if(mark == AGCT[j]) val |= (1<<j);
			seq[i].push_back(val);
		}else{
			const int idx = str2idx[tmp];
			seq[i].insert(end(seq[i]),begin(seq[idx]),end(seq[idx]));
		}

		if(seq[i].size()>n) break;
		if(ss.eof()) break;
	}
}

const ll mod = 1000000007LL;
ll dp[55][55][55][55];

int main(void){
	int nATGC[4];
	rep(i,4) cin >> nATGC[i];
	const int total = accumulate(nATGC,nATGC+4,0);


	int m;
	cin >> m;

	cin.ignore();
	rep(i,m) getline(cin,bnf[i]);
	rrep(i,m) func(i,total);

	dp[0][0][0][0]=1LL;

	if(total != int(seq[0].size())){
		cout << 0 << endl;
		return 0;
	}

	rep(i,total)rep(na,nATGC[0]+1)rep(nt,nATGC[1]+1)rep(ng,nATGC[2]+1){
		const int nc = i - na - nt - ng;
		if(nc < 0 or nATGC[3] < nc) continue;

		dp[na][nt][ng][nc] %= mod;

		if(na < nATGC[0] and seq[0][i]&1){
			dp[na+1][nt][ng][nc] += dp[na][nt][ng][nc];
			dp[na+1][nt][ng][nc] %= mod;
		}

		if(nt < nATGC[1] and seq[0][i]&2){
			dp[na][nt+1][ng][nc] += dp[na][nt][ng][nc];
			dp[na][nt+1][ng][nc] %= mod;
		}
		
		if(ng < nATGC[2] and seq[0][i]&4){
			dp[na][nt][ng+1][nc] += dp[na][nt][ng][nc];
			dp[na][nt][ng+1][nc] %= mod;
		}

		if(nc < nATGC[3] and seq[0][i]&8){
			dp[na][nt][ng][nc+1] += dp[na][nt][ng][nc];
			dp[na][nt][ng][nc+1] %= mod;
		}
	}

	cout << dp[nATGC[0]][nATGC[1]][nATGC[2]][nATGC[3]] << endl;

	return 0;
}