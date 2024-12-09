#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

int walls[55][55][4];

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

struct aa {
	int x;
	int y;
	int time;
	vector<int>xs;
	vector<int>ys;
};
class Compare {
public:
	//aaが昇順に並ぶ
	bool operator()(const aa&l, const aa&r) {
		return l.time> r.time;
	}
};
aa getway(const int fx, const int fy, const int tx, const int ty) {
	priority_queue<aa, vector<aa>, Compare>que;
	que.push(aa{ fx,fy,0,{},{} });
	int memo[100][100];
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			memo[i][j] = 99999999;
		}
	}
	memo[fy][fx] = 0;
	while (!que.empty()) {
		aa atop(que.top());
		que.pop();
		if (atop.x == tx&&atop.y == ty) {
			return atop;
		}
		else {
			atop.xs.push_back(atop.x);
			atop.ys.push_back(atop.y);
		}
		vector<int> axs(atop.xs);
		vector<int> ays(atop.ys);
		for (int i = 0; i < 4; ++i) {
			int newx = atop.x + dx[i];
			int newy = atop.y + dy[i];
			if (!walls[atop.y][atop.x][i]) {
				if (memo[newy][newx]>atop.time + 1) {
					memo[newy][newx] = atop.time + 1;
					que.push(aa{ newx,newy,atop.time + 1,atop.xs,atop.ys });
				}
			}
		}
	}
	return aa{ -10000,0,0,{},{} };
}

int main() {
	int W, H,N; cin >> W >> H >> N;
	for (int i = 0; i < N; ++i) {
		int sx, sy, dx, dy; cin >> sx >> sy >> dx >> dy;
		sy = H - sy;
		dy = H - dy;
		if (sx == dx) {
			if (sy > dy)swap(sy, dy);
			for (int y = sy; y < dy; ++y) {
				if(sx-1>=0)walls[y][sx - 1][2] = true;
				if (sx < W)walls[y][sx][0] = true;
			}
		}
		else {
			if (sx > dx)swap(sx, dx);
			for (int x = sx; x < dx; ++x) {
				if(sy-1>=0)walls[sy-1][x][1] = true;
				if(sy<H)walls[sy][x][3] = true;
			}
		}
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (i + dy[k] < 0 || i + dy[k] >= H) {
					walls[i][j][k] = true;
				}
				if (j + dx[k] < 0 || j + dx[k] >= W) {
					walls[i][j][k] = true;

				}
			}
		}
	}
	int startx, starty, goalx, goaly; cin >> startx >> starty >> goalx >> goaly;
	starty = H - starty - 1;
	goaly = H - goaly - 1;

	aa fstway =getway(startx, starty, goalx, goaly);
	fstway.xs.push_back(goalx);
	fstway.ys.push_back(goaly);
	int fsttime = fstway.time;
	int ans = 0;
	if (!fstway.xs.empty()) {
		for (int i = 0; i < fstway.xs.size() - 1; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (fstway.xs[i] + dx[j] == fstway.xs[i + 1] && fstway.ys[i] + dy[j] == fstway.ys[i + 1]) {
					walls[fstway.ys[i]][fstway.xs[i]][j] = true;
					walls[fstway.ys[i + 1]][fstway.xs[i + 1]][(2 + j) % 4] = true;
					aa nowway(getway(startx, starty, goalx, goaly));
					if (nowway.time) {
						ans = max(ans, nowway.time - fsttime);
					}
					walls[fstway.ys[i]][fstway.xs[i]][j] = false;
					walls[fstway.ys[i + 1]][fstway.xs[i + 1]][(2 + j) % 4] = false;
				}
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}