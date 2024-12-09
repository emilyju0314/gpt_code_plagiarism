#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
string input[10];
string dp[1 << 10][10];
int cover[10][10];

string solve(const vector<string>& names) {
	int n = names.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			cover[i][j] = 0;
			for (int k = min(names[i].size(), names[j].size()); k > 0; --k) {
				if (names[i].substr(names[i].size() - k) == names[j].substr(0, k)) {
					cover[i][j] = k;
					break;
				}
			}
		}
	}
	for (int i = 0; i < (1 << n); ++i) {
		fill(&dp[i][0], &dp[i][n], string());
	}
	for (int i = 0; i < n; ++i) {
		dp[1 << i][i] = names[i];
	}
	for (int i = 1; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (dp[i][j].empty()) continue;
			for (int k = 0; k < n; ++k) {
				if (i & (1 << k)) continue;
				string& cur = dp[i|(1<<k)][k];
				string next = dp[i][j] + names[k].substr(cover[j][k]);
				if (cur.empty()
					 	|| cur.size() > next.size()
					 	|| cur.size() == next.size() && cur > next) {
					cur = next;
				}
			}
		}
	}
	string ret = "";
	for (int i = 0; i < 100; ++i) ret += "z";
	for (int i = 0; i < n; ++i) {
		string& cur = dp[(1 << n) - 1][i];
		if (ret.size() > cur.size() || ret.size() == cur.size() && ret > cur) ret = cur;
	}
	return ret;
}

int main() {
	while (true) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; ++i) {
			cin >> input[i];
		}
		vector<string> names;
		for (int i = 0; i < N; ++i) {
			bool contains = false;
			for (int j = 0; j < N; ++j) {
				if (j == i) continue;
				if (input[i].size() < input[j].size() && input[j].find(input[i]) != string::npos) {
					contains = true;
					break;
				}
			}
			if (!contains) names.push_back(input[i]);
		}
		cout << solve(names) << endl;
	}
}