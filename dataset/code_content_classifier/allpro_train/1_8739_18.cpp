#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
using namespace std;

typedef long long LL;

LL dist, ans = (LL)1e18;
int n, m;
vector<int> S, intr;
vector<LL> D;

vector<int> ptn;

void enumpattern(int a, int i){
	if(i >= n - 1){
		ptn.push_back(a);
	}
	else{
		enumpattern(a, i + 1);
		enumpattern(a | 1 << i, i + 2);
	}
}


void calcans(){
	vector<LL> stm(n + 1, -1LL);
	LL lst0 = -1, lft0 = 0;	// last start/finish time

	vector<vector<int> > odr(m + 1, vector<int>(n));
	for(int i = 0; i < n; ++i){
		odr[0][i] = i;
	}
	
	int cnt = 0;
	for(int j = 0; j < m; ++j){
		odr[j + 1] = odr[j];
		for(int i = 0; i < n; ++i){
			if(intr[j] >> i & 1){
				++cnt;
				int a = odr[j][i], b = odr[j][i + 1];
				if(a > b || S[a] <= S[b]){
					return;
				}
				swap(odr[j + 1][i], odr[j + 1][i + 1]);
				++i;
			}
		}
	}

	for(int i = 0; i < n; ++i){
		if(stm[i] != -1LL) continue;

		stm[i] = 0;
		bool updated = true;
		while(updated){
			updated = false;

			for(int j = 0; j < m; ++j){
				for(int k = i; k < n; ++k){
					if((intr[j] >> k & 1) == 0){
						continue;
					}

					int a = odr[j][k], b = odr[j][k+1];
					if(stm[a] == -1LL && stm[b] != -1LL){
						updated = true;
						stm[a] = stm[b] + D[j] * (S[b] - S[a]);
					}
					else if(stm[a] != -1LL && stm[b] == -1LL){
						updated = true;
						stm[b] = stm[a] + D[j] * (S[a] - S[b]);
					}
				}
			}
		}

		for(int j = i; stm[j] != -1LL; ++j)
		for(int k = j + 1; stm[k] != -1LL; ++k){
			if(S[j] <= S[k]){ continue; }
			LL ip = (stm[k] - stm[j]) / (S[j] - S[k]);
			if(ip < 0 || ip >= dist){ continue; }
			if((stm[k] - stm[j]) % (S[j] - S[k]) != 0){
				return;
			}
			
			int x = find(D.begin(), D.end(), ip) - D.begin();
			if(x >= m) return;
			int y = find(odr[x].begin(), odr[x].end(), j) - odr[x].begin();
			if(y >= n - 1 || odr[x][y+1] != k ||
			  odr[x+1][y] != k || odr[x+1][y+1] != j){
				return;
			}
			--cnt;
		}
		
		int u = find(stm.begin(), stm.end(), -1LL) - stm.begin() - 1;	//[i,u]
		int farv = odr[m][i], larv = odr[m][u];	//first/last arrival
		LL lst1 = stm[u];
		LL fft1 = S[farv] * dist + stm[farv];
		LL lft1 = S[larv] * dist + stm[larv];

		for(int j = i; j < u; ++j){
			if(stm[j] >= stm[j + 1]){ return; }
		}

		LL offset;
		if(lst0 + fft1 + 1 >= lft0){	//start as early as possible
			offset = lst0 + 1;
		}
		else{
			offset = lft0 - fft1;
		}
		lst0 = offset + lst1;
		lft0 = offset + lft1;

		i = u;
	}
	if(cnt != 0) return;

	ans = min(ans, lft0);
}

void solve(int i){
	if(i == m){
		calcans();
	}
	else{
		for(int j = 0; j < ptn.size(); ++j){
			intr[i] = ptn[j];
			solve(i + 1);
		}
	}
}


int main(){
	cin >> dist >> n;
	S.resize(n);

	for(int i = 0; i < n; ++i){
		cin >> S[i];
	}
	cin >> m;
	D.resize(m);
	intr.resize(m);
	for(int i = 0; i < m; ++i){
		cin >> D[i];
	}
	sort(D.begin(), D.end());

	enumpattern(0, 0);

	solve(0);

	cout << ans << '\n';
}