#include "bits/stdc++.h"
using namespace std;
using ld =  double;
const ld eps = 1e-9;
const int COMB_MAX = 11;
int per[5][5];
ld dp[101][COMB_MAX + 1][101][5][11];

int A, B;
ld solve(vector<int>&nodes, int now, int combo,int score, int preuse,int preacc) {
	if (dp[now][combo][score][preuse][preacc] > -eps) {
		return dp[now][combo][score][preuse][preacc];
	}else if (now == nodes.size()) {
		if (score == 100) {
			int a;
			a = 1;
			a++;
		}
		dp[now][combo][score][preuse][preacc] = score >= 100;
	}
	else {

		ld ans = 0;
		if (nodes[now] == 0) {
			dp[now][combo][score][preuse][preacc] = solve(nodes, now + 1, combo, score, 4, 10);
		}
		else if (score >= 100) {
			dp[now][combo][score][preuse][preacc] = 1.0l;
		}
		else {
			for (int nextuse = 0; nextuse < 5; ++nextuse) {
				int nextscore(score);
				int nextcombo(combo);
				int kot = nextuse == 4 ? 0 : nextuse % 2+1;
				if (kot&&nodes[now] == kot) {
					nextcombo++;
					nextscore += A + B*min(combo, 10);
				}
				else {
					nextcombo = 0;
				}
				if (nextcombo > COMB_MAX) {
					nextcombo = min(nextcombo, COMB_MAX);
				}
				nextscore = min(nextscore, 100);
				int nextacc = nextuse == 4 ? 10 : max(0, ((per[preuse][nextuse] - 10) * 10 + preacc*10) / 10);
				assert(nextacc <= 10);
				ld nans = 0;
				{
					if (nextacc) {
						nans += (ld(nextacc) / 10)*solve(nodes, now + 1, nextcombo, nextscore, nextuse, nextacc);
					}
					nans += (1.0l-ld(nextacc) / 10)*solve(nodes, now + 1, 0, score, nextuse, nextacc);
				}
				ans = max(ans, nans);
			}
			dp[now][combo][score][preuse][preacc] = ans;
		}
		
	}
	return dp[now][combo][score][preuse][preacc];

}

int main() {
	cout << setprecision(10) << fixed;
	while (1) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j <=COMB_MAX ; ++j) {
				for (int k = 0; k < 101; ++k) {
					for (int l = 0; l < 5; ++l) {
						for (int m = 0; m < 11; ++m) {
							dp[i][j][k][l][m] = -1;
						}
					}
				}
			}
		}
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				int from = j * 2 + i;
				for (int k = 0; k < 2; ++k) {
					for (int l = 0; l < 2; ++l) {
						int to = l * 2 + k;
						cin >> per[from][to];
						if (per[from][to] < -0.5)return 0;
					}
				}
			}
		}
		for (int i = 0; i < 5; ++i) {
			per[i][4] = 10;
			per[4][i] = 10;
		}
		int L; cin >> L;
		vector<int>nodes(L);
		for (int i = 0; i < L; ++i) {
			cin >> nodes[i];
		} cin >> A >> B;
		A /= 100;
		B /= 100;
		ld ans = solve(nodes, 0, 0, 0, 4, 10);
		cout << ans << endl;
	}
	return 0;
}