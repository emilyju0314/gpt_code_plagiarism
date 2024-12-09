#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>
using namespace std;
struct State { bool x[3][3]; };
int p[1020][1020], H, W, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int M[1020][1020][128];

State slide(int rx, int ry, State S) {
	State T; for (int i = 0; i < 9; i++)T.x[i / 3][i % 3] = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int h1 = i - rx, h2 = j - ry; if (h1 < 0 || h2 < 0)continue;
			T.x[h1][h2] = S.x[i][j];
		}
	}
	return T;
}
int solve(int cx, int cy, State S) {
	State SV = S;
	short SV2 = 0; for (int i = 0; i < 9; i++) { if (S.x[i / 3][i % 3] == true)SV2 += (1 << i); }
	if (M[cx][cy][SV2] >= 1)return M[cx][cy][SV2] - 1;

	if (cx == H && cy == W) { M[cx][cy][SV2] = 1; return 0; }
	if (cx > H || cy > W) { M[cx][cy][SV2] = 100000000; return 99999999; }

	int e1 = 0; if (S.x[1][1] == false && p[cx][cy] >= 1) { S.x[1][1] = true; e1 = p[cx][cy]; }
	vector<tuple<int, int, int>>v;
	for (int i = 0; i < 4; i++) {
		int fx = cx + dx[i], fy = cy + dy[i];
		if (p[fx][fy] >= 1 && S.x[1 + dx[i]][1 + dy[i]] == false)v.push_back(make_tuple(fx, fy, i));
	}
	if (v.size() == 0) {
		int e3 = min(solve(cx + 1, cy, slide(1, 0, S)), solve(cx, cy + 1, slide(0, 1, S))) + e1;
		M[cx][cy][SV2] = e3 + 1;
		return e3;
	}
	int ret = 99999999;
	for (int i = 0; i < (int)v.size(); i++) {
		State Y = S; int e2 = 0;
		for (int j = 0; j < v.size(); j++) {
			if (i != j) { Y.x[1 + dx[get<2>(v[j])]][1 + dy[get<2>(v[j])]] = true; e2 += p[get<0>(v[j])][get<1>(v[j])]; }
		}
		ret = min(ret, solve(cx + 1, cy, slide(1, 0, Y)) + e2 + e1);
		ret = min(ret, solve(cx, cy + 1, slide(0, 1, Y)) + e2 + e1);
	}
	M[cx][cy][SV2] = ret + 1;
	return ret;
}
int main() {
	cin >> H >> W; for (int i = 1; i <= H; i++) { for (int j = 1; j <= W; j++) { char c; cin >> c; if (c >= '1' && c <= '9')p[i][j] = c - '0'; } }
	State T; for (int i = 0; i < 9; i++)T.x[i / 3][i % 3] = false;
	int ans = solve(1, 1, T);
	cout << ans << endl;
	return 0;
}