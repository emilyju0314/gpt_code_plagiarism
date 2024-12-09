#include <bits/stdc++.h>
using namespace std;

int n, m;
char c[60][60];
int bio[60][60];
int d1[] = {0, 0, -1, 1};
int d2[] = {1, -1, 0, 0};
queue< pair<int, int> > q;

void bfs() {
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i ++) {
			int x1 = x + d1[i];
			int y1 = y + d2[i];
			if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || bio[x1][y1] != -1 || c[x1][y1] == '#') continue;
			bio[x1][y1] = bio[x][y] + 1;
			q.push( make_pair(x1, y1) );
		}
	}
	
}

int main () {

	cin >> n >> m;
	int b = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> c[i][j];
			bio[i][j] = -1;
			if (c[i][j] == '.') b ++;
		}
	}
	q.push( make_pair(0, 0) );
	bio[0][0] = 0;
	bfs();
	if (bio[n-1][m-1] == -1) cout << -1;
	else {
		cout << b - bio[n-1][m-1] - 1;
	}

	return 0;
}