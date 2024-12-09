#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const long long mod = 1000000007;

struct UnionFind{
	vector<int> par;
	void init(int N){
		par.clear();
		for(int i = 0; i < N; ++i){
			par.push_back(i);
		}
	}
	int find(int x){
		if(x == par[x]) return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y){
		x = find(x), y = find(y);
		if(x == y) return;
		par[x] = y;
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
};

long long pw[220];

vector<long long> valid_cycles;
vector<long long> num_t;

int N, M, A;

void dfs(int c, UnionFind uf, long long st){
	if(c == M){
		for(int c2 = 1; c2 < M; ++c2){
			if(((st >> c2) & 1) == 0){
				bool flg = false;
				for(int i = 0; i + c2 < M; ++i){
					bool tmp = uf.same(i, i + c2);
					if(!tmp){
						flg = true;
						break;
					}
				}
				if(!flg) return;
			}
		}
		valid_cycles.push_back(st);
		int cnt = 0;
		for(int i = 0; i < M; ++i){
			if(uf.find(i) == i) cnt++;
		}
		num_t.push_back(pw[cnt]);
		return;
	}
	//c is not a period
	bool flg = false;
	for(int i = 0; i + c < M; ++i){
		bool tmp = uf.same(i, i + c);
		if(!tmp){
			flg = true;
			break;
		}
	}
	if(flg){
		dfs(c + 1, uf, st);
	}
	//c is a period
	for(int i = 0; i + c < M; ++i){
		uf.unite(i, i + c);
	}
	dfs(c + 1, uf, st | (1ll << c));
}

long long dp[220];

long long count_s(long long cycles){
	for(int i = 0; i < 220; ++i) dp[i] = 0;
	for(int i = M; i <= N; ++i){
		dp[i] = pw[i - M];
		for(int j = M; j <= i - M; ++j){
			long long coe1 = dp[j];
			long long coe2 = pw[i - M - j];
			dp[i] = (dp[i] - coe1 * coe2) % mod;
		}
		for(int j = i - M + 1; j < i; ++j){
			int d = i - j;
			if((cycles >> d) & 1){
				dp[i] = (dp[i] - dp[j]) % mod;
			}
		}
	}
	long long res = 0;
	for(int i = M; i <= N; ++i){
		long long coe1 = dp[i];
		long long coe2 = pw[N - i];
		res = (res + coe1 * coe2) % mod;
	}
	res += mod;
	res %= mod;
	return res;
}

void count_t(){
	for(int i = (int)valid_cycles.size() - 1; i >= 0; --i){
		for(int j = i + 1; j < valid_cycles.size(); ++j){
			if((valid_cycles[i] & valid_cycles[j]) == valid_cycles[i]){
				num_t[i] = (num_t[i] - num_t[j]) % mod;
			}
		}
	}
}

long long solve(){
	pw[0] = 1;
	for(int i = 1; i < 220; ++i) pw[i] = (pw[i - 1] * A) % mod;
	UnionFind uf;
	uf.init(M);
	dfs(1, uf, 0);
	count_t();
	long long ans = 0;
	for(int i = 0; i < valid_cycles.size(); ++i){
		long long num1 = num_t[i];
		long long num2 = count_s(valid_cycles[i]);
		ans = (ans + num1 * num2) % mod;
	}
	ans += mod;
	ans %= mod;
	return ans;
}

int main(){
	scanf("%d%d%d", &N, &M, &A);
	long long ans = solve();
	printf("%lld\n", ans);
	return 0;
}