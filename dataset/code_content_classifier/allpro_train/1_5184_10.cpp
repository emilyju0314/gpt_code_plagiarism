#include <bits/stdc++.h>
using namespace std;

const string dir = "ENSW";
const string rdir = "WSNW";
constexpr int rot[4][6] = { {2, 1, 5, 3, 0, 4}, {3, 0, 2, 5, 4, 1},
							{1, 5, 2, 0, 4, 3}, {4, 1, 0, 3, 5, 2}};

vector<int> roll(vector<int> const& v, char d) {
	const int p = find(begin(dir), end(dir), d) - begin(dir);
	vector<int> res(6);
	for(int i = 0; i < 6; ++i) {
		res[i] = v[rot[p][i]];
	}
	return res;
}

bool check(vector<int> const& dice) {
	int v1 = dice[0] + dice[5], v2 = dice[2] + dice[4], v3 = dice[1] + dice[3];
	int cnt = 0;
	if(dice[0] < 0) return false;
	if(v1 >= v2 + v3 + 1) return false;
	if(v2 > v1 + v3 + 1) return false;
	if(v2 == v1 + v3 + 1) cnt++;
	if(v3 > v1 + v2 + 1) return false;
	if(v3 == v1 + v2 + 1) cnt++;
	return cnt <= 1;
};

bool found = false;
string ans, t;
void dfs(vector<int>& dice) {
	if(found && ans < t) {
		return;
	}
	if(*max_element(begin(dice), end(dice)) == 0) {
		if(found) {
			ans = min(ans, t);
		} else {
			ans = t;
		}
		//cout << "t: " << t << endl;
		found = true;
		return;
	}
	for(int i = 0; i < 4; ++i) {
		dice = roll(dice, dir[i]);
		dice[0]--;
		if(check(dice)) {
			t += dir[i];
			dfs(dice);
			return;
		}
		dice[0]++;
		dice = roll(dice, rdir[i]);
	}
	for(int i = 0; i < 6; ++i) {
		cout << dice[i] << ' ';
	}
	cout << endl;
	assert(false);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	vector<int> v(6);
	while(true) {
		ans.clear(), t.clear();
		found = false;
		for(int i = 0; i < 6; ++i) cin >> v[i];
		if(*max_element(begin(v), end(v)) == 0) break;
		sort(begin(v), end(v));
		int p, q;
		cin >> p >> q;
		
		do {
			auto tdice = v;
			if(!check(v)) continue;
			t.clear();
			dfs(tdice);
			//cout << "sum: " << accumulate(begin(v), end(v), 0) << endl;
		} while(next_permutation(begin(v), end(v)));
		
		if(!found) {
			cout << "impossible" << endl;
		} else {
			//cout << "sz: " << ans.size() << endl;
		    cout << ans.substr(p - 1, q - p + 1) << endl;
		}
	}
}
