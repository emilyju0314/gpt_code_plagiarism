#include <cstdlib>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

#define operation(x, y) \
{\
	if(house[y][x] >= 0 && !((visited >> house[y][x]) & 1)) {	\
		can_pass[y][x] = true;									\
		res += dfs(x, y, (visited | (1 << house[y][x])));		\
		can_pass[y][x] = false;									\
		break;													\
	}\
	if(!can_pass[y][x])\
		break;\
}

int w, h, num;
int sx, sy;
map<pair<short, int>, int> memo;
vector<vector<bool> > can_pass;
vector<vector<short> > house;

int dfs(int x, int y, int visited = 0) {
	if(visited == (1 << num) - 1)
		if(x == sx || y == sy)
			return 1;
		else
			return 0;

	if(memo.count(make_pair(house[y][x], visited)))
		return memo[make_pair(house[y][x], visited)];

	int res = 0;
	for(int i = x + 1; i < w; ++i)
		operation(i, y)

	for(int i = x - 1; i >= 0; --i)
		operation(i, y)

	for(int i = y + 1; i < h; ++i)
		operation(x, i)

	for(int i = y - 1; i >= 0; --i)
		operation(x, i)

	if(__builtin_popcount(visited) < 19)
		memo[make_pair(house[y][x], visited)] = res;
			
	return res;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	while(cin >> w >> h, w) {
		can_pass.clear();
		can_pass.resize(h, vector<bool>(w, false));
		house.clear();
		house.resize(h, vector<short>(w, -1));

		num = 0;
		for(int i = 0; i < h; ++i) {
			for(int j = 0; j < w; ++j) {
				int in;
				cin >> in;

				if(in == 1) {
					house[i][j] = num++;
				}

				else {
					can_pass[i][j] = true;
					if(in == 2) {
						sx = j;
						sy = i;
					}
				}
			}
		}

		memo.clear();
		cout << dfs(sx, sy) << endl;
	}


	return EXIT_SUCCESS;
}