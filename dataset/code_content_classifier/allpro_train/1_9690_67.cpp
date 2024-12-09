#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

struct st {
	char f[10][11]; int cnt;
};
int w, h, dx[]{ 1,-1,0,0 }, dy[]{ 0,0,1,-1 };
char dir[] = "RGB";
bool ok(st&s) {
	char c = s.f[0][0];
	rep(i, h)rep(j, w) {
		if (s.f[i][j] != c)return false;
	}
	return true;
}
void dfs(st&s, int x, int y, char b, char c) {
	s.f[x][y] = c;
	rep(i, 4) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx&&nx < h && 0 <= ny&&ny < w&&s.f[nx][ny] == b)
			dfs(s, nx, ny, b, c);
	}
}
int main() {
	while (scanf("%d%d", &w, &h), h) {
		st in; in.cnt = 0; memset(in.f, 0, sizeof(in.f));
		rep(i, h)rep(j, w)cin >> in.f[i][j];
		queue<st>que; que.push(in);
		while (1) {
			st p = que.front(); que.pop();
			if (ok(p)) {
				printf("%d\n", p.cnt); break;
			}st u;
			rep(i, 3) {
				u = p;
				if (dir[i] == u.f[0][0])continue;
				dfs(u, 0, 0, u.f[0][0], dir[i]); u.cnt++;
				que.push(u);
			}
		}
	}
}