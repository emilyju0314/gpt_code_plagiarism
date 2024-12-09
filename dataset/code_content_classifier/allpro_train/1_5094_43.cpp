#include <bits/stdc++.h>
using namespace std;

int T, f[2][1 << 13], a_win, b_win;
bool a[2][13];

bool in_mask(int j, int i) {
	if(j < 0 || j > 12) return false;
	if((1 << j) & i) return true;
	return false;
}

int main() {
	cin >> T;
	while(T--) {
		a_win = b_win = 0;
		for(int i = 0; i < 13; ++i) a[0][i] = a[1][i] = false;
		for(int i = 0; i < 6; ++i) {
			int x;
			cin >> x;
			x--;
			a[0][x] = true; a_win += 1 << x;
		}
		for(int i = 0; i < 13; ++i) if(!a[0][i] && i != 6) a[1][i] = true, b_win += 1 << i;
		memset(f, -1, sizeof f);
		for(int i = (1 << 13) - 1; i >= 0; --i) {
			int st = 1, nd = 0; bool flag0 = true;
			for(int j = 0; j < 13; ++j)
				if(a[0][j] && !in_mask(j, i) && (in_mask(j - 1, i) || in_mask(j + 1, i))) {
					//if(i == (1 << 6)) cout << j << endl;
					st = 0, nd = 1, flag0 = false;
				}
			f[st][i] = 0;
			//if(i == (1 << 6)) cout << st << ' ' << nd << ' ' << flag0 << endl;
			for(int j = 0; j < 13; ++j)
				if(a[st][j] && !in_mask(j, i) && (in_mask(j - 1, i) || in_mask(j + 1, i)))
					if(f[nd][i ^ (1 << j)] != -1)
						f[st][i] |= !f[nd][i ^ (1 << j)];
			f[nd][i] = 0; bool flag1 = true;
			for(int j = 0; j < 13; ++j)
				if(a[nd][j] && !in_mask(j, i) && (in_mask(j - 1, i) || in_mask(j + 1, i)))
					if(f[st][i ^ (1 << j)] != -1)
						f[nd][i] |= !f[st][i ^ (1 << j)], flag1 = false;
			if(flag1) f[nd][i] = !f[st][i];
			if((i & a_win) == a_win && (i && b_win) != b_win) f[1][i] = 0;
			if((i & b_win) == b_win && (i && a_win) != a_win) f[0][i] = 0;
		}
		int mask = 0;
		for(int i = 0; i < 6; ++i) mask += 1 << i;
		for(int i = 7; i < 12; ++i) mask += 1 << i;
		if(f[0][1 << 6]) cout << "yes\n"; else cout << "no\n";
	}
}
