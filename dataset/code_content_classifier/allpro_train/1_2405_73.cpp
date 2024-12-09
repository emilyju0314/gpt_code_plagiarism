#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string s;
	cin >> s;
	vector<int>three(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		three[i] = three[i - 1] * 3;
	}
	vector<vector<vector<int>>>place(N + 1);
	vector<vector<int>>ed(N + 1);
	for (int i = 1; i <= N; i++) {
		place[i].resize(three[i]);
		ed[i].resize(three[i]);
	}
	s = 'A' + s;
	place[0].resize(1);
	for (int i = 0; i < s.size(); i++) {
		if(s[i]=='R')place[0][0].push_back(i);
	}
	vector<int>sum(s.size());
	for (int i = 1; i < s.size(); i++) {
		sum[i] = s[i] == 'S';
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j<three[i]; j++) {
			int p = j / three[i - 1];
			int md = j % three[i - 1];
			int cn = 0;
			for (auto k : place[i - 1][md]) {
				if (sum[k] % 2 != sum[cn] % 2) {
					p = (3 - p) % 3;
				}
				cn = k;
				p++;
				if (p == 3) {
					p = 0;
					place[i][j].push_back(k);
				}
			}
			if (sum.back() % 2 != sum[cn] % 2) {
				p = (3 - p) % 3;
			}
			ed[i][j] = p;
		}
	}
	for (int i = 0; i < three[N]; i++) {
		int ans = 0;
		for (int j = N; j > 0; j--) {
			ans *= 3;
			ans += ed[j][i%three[j]];
		}
		cout << ans << " ";
	}
	cout << endl;
}