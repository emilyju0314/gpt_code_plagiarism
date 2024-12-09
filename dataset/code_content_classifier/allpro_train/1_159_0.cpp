#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <cctype>
using namespace std;

#define ALL(v) begin(v),end(v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)

typedef long long LL;
typedef vector<int> vint;

const int targets[4][9] = {
	{1, 1, 2, 2, 2, 1, 8, 8, 8},
	{3, 2, 2, 3, 4, 4, 4, 3, 2},
	{5, 5, 4, 4, 4, 5, 6, 6, 6},
	{7, 8, 8, 7, 6, 6, 6, 7, 8}
};

int getdir(char c){
	switch(c){
		case 'R': return 0;
		case 'U': return 1;
		case 'L': return 2;
		case 'D': return 3;
	}
	abort();
}

struct solver{
	int n;
	solver(int n_) : n(n_) {}
	vector<vint> ids[9];
	vint trs[4];
	vint unit;
	const char *p;
	
	vint mul(const vint &x, const vint &y){
		int sz = x.size();
		vint ret(sz);
		REP(i, sz){ ret[i] = y[x[i]]; }
		return ret;
	}
	
	vint pow(vint x, LL y){
		vint a = unit;
		while(y){
			if(y & 1){ a = mul(a, x); }
			x = mul(x, x);
			y >>= 1;
		}
		return a;
	}
	
	vint parse(){
		vint a = unit;
		vint b;
		while(1){
			if(*p == '('){
				++p;
				vint x = parse();
				++p;
				char *endp;
				LL r = strtoll(p, &endp, 10);
				p = endp;
				b = pow(x, r);
			}
			else if(isalpha(*p)){
				int dir = getdir(*p);
				++p;
				b = trs[dir];
			}
			else{ break; }
			a = mul(a, b);
		}
		return a;
	}
	
	void solve(){
		vector<string> in0(n);
		REP(i, n){ cin >> in0[i]; }
		string op;
		cin >> op;

		int fstdir = -1;
		for(char c : op){
			if(isalpha(c)){
				fstdir = getdir(c);
				break;
			}
		}

		vector<string> in(n, string(n, '.'));
		if(fstdir == 0){
			REP(y, n){
				int u = n - 1;
				RREP(x, n){
					if(in0[y][x] != '.'){
						in[y][u--] = in0[y][x];
					}
				}
			}
		}
		else if(fstdir == 1){
			REP(x, n){
				int u = 0;
				REP(y, n){
					if(in0[y][x] != '.'){
						in[u++][x] = in0[y][x];
					}
				}
			}
		}
		else if(fstdir == 2){
			REP(y, n){
				int u = 0;
				REP(x, n){
					if(in0[y][x] != '.'){
						in[y][u++] = in0[y][x];
					}
				}
			}
		}
		else{
			REP(x, n){
				int u = n - 1;
				RREP(y, n){
					if(in0[y][x] != '.'){
						in[u--][x] = in0[y][x];
					}
				}
			}
		}

		REP(i, 9){
			ids[i].assign(n, vint(n, -1));
		}

		int id = 0;
		REP(i, n)
		REP(j, n){
			if(in[i][j] != '.'){
				ids[0][i][j] = id;
				++id;
			}
		}
		int pcnt = id;

		REP(i, 4){ trs[i].assign(9 * pcnt, -1); }
		unit.resize(9 * pcnt);
		iota(ALL(unit), 0);

		REP(from, 9){
			int to, dir;

			dir = 0;
			to = targets[dir][from];
			id = to * pcnt;
			REP(y, n){
				int u = n - 1;
				RREP(x, n){
					if(ids[from][y][x] >= 0){
						int &r = ids[to][y][u];
						--u;
						if(r == -1){ r = id++; }
						trs[dir][ids[from][y][x]] = r;
					}
				}
			}

			dir = 1;
			to = targets[dir][from];
			id = to * pcnt;
			REP(x, n){
				int u = 0;
				REP(y, n){
					if(ids[from][y][x] >= 0){
						int &r = ids[to][u][x];
						++u;
						if(r == -1){ r = id++; }
						trs[dir][ids[from][y][x]] = r;
					}
				}
			}

			dir = 2;
			to = targets[dir][from];
			id = to * pcnt;
			REP(y, n){
				int u = 0;
				REP(x, n){
					if(ids[from][y][x] >= 0){
						int &r = ids[to][y][u];
						++u;
						if(r == -1){ r = id++; }
						trs[dir][ids[from][y][x]] = r;
					}
				}
			}

			dir = 3;
			to = targets[dir][from];
			id = to * pcnt;
			REP(x, n){
				int u = n - 1;
				RREP(y, n){
					if(ids[from][y][x] >= 0){
						int &r = ids[to][u][x];
						--u;
						if(r == -1){ r = id++; }
						trs[dir][ids[from][y][x]] = r;
					}
				}
			}
		}
		
		p = op.c_str();
		vint res = parse();

		vector<char> val(9 * pcnt);
		REP(y, n)
		REP(x, n){
			int k = ids[0][y][x];
			if(k >= 0){
				val[res[k]] = in[y][x];
			}
		}
		vector<string> ans(n, string(n, '.'));
		REP(i, 9)
		REP(y, n)
		REP(x, n){
			int k = ids[i][y][x];
			if(k >= 0 && val[k] != 0){
				ans[y][x] = val[k];
			}
		}
		
		REP(i, n){
			cout << ans[i] << '\n';
		}
	}
};

int main(){
	int n;
	while(cin >> n && n){
		solver(n).solve();
	}
}

