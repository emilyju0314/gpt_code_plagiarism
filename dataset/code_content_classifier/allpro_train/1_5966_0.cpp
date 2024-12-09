#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int INF = 0x3f3f3f3f;
inline int get_note(int O, char ch, int f) {
	if (ch == 'C') return (O - 1) * 12 + 1 + f;
	else if (ch == 'D') return (O - 1) * 12 + 3 + f;
	else if (ch == 'E') return (O - 1) * 12 + 5 + f;
	else if (ch == 'F') return (O - 1) * 12 + 6 + f;
	else if (ch == 'G') return (O - 1) * 12 + 8 + f;
	else if (ch == 'A') return (O - 1) * 12 + 10 + f;
	else return (O - 1) * 12 + 12 + f;
}
inline int get_num(char *str, int len, int &i) {
	int x = 0;
	while (i < len && isdigit(str[i + 1])) x = x * 10 + str[++i] - '0';
	return x;
}
inline int get_dot(char *str, int len, int &i) {
	int c = 0;
	while (i < len && str[i + 1] == '.') c++, i++;
	return c;
}
inline int get_len(int x, int L) {
	if (!x) return L;
	else if (x == 1) return 1;
	else if (x == 2) return 2;
	else if (x == 4) return 3;
	else if (x == 8) return 4;
	else if (x == 16) return 5;
	else if (x == 32) return 6;
	else if (x == 64) return 7;
	else return 8;
}
struct Node {
	int nt, x, c, vol;
};
int n;
Node dat[N];
inline void init_all(char *str) {
	int len = strlen(str + 1);
	int O = 4;
	int L = 3;
	int V = 100;
	n = 0;
	for (int i = 1; i <= len; i++) {
		char ch = str[i];
		if (ch >= 'A' && ch <= 'G') {
			int f = 0;
			if (i < len && str[i + 1] == '+') f = 1, i++;
			else if (i < len && str[i + 1] == '-') f = -1, i++;
			int nt = get_note(O, ch, f);
			int x = get_len(get_num(str, len, i), L);
			int c = get_dot(str, len, i);
			dat[++n] = (Node){nt, x, c, V};
		} else if (ch == 'R') {
			int x = get_len(get_num(str, len, i), L);
			int c = get_dot(str, len, i);
			x = (1 << (8 - x));
			int t = x;
			while (c--) {t >>= 1; x += t;}
			if (n && !dat[n].nt) dat[n].x += x;
			else dat[++n] = (Node){0, x, 0, 0};
		} else if (ch == 'O') {
			O = str[++i] - '0';
		} else if (ch == '<') {
			O--;
		} else if (ch == '>') {
			O++;
		} else if (ch == 'L') {
			L = get_len(get_num(str, len, i), L);
		} else if (ch == 'V') {
			V = get_num(str, len, i);
		} else assert(false);
	}
}
char str[N];
int dp_oct[N][9], dp_L[N][9];
int fr_oct[N][9], fr_L[N][9];
const int Len_note[12] = {1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1};
const int Len_dura[9] = {0, 1, 1, 1, 1, 2, 2, 2, 3};
int dp_r[512][9][9], dp_r2[1024][9][9], fr_r2[1024][9][9];
pair<int, int> fr_r[512][9][9];
pair<int, int> rests[40];
void init_r() {
	int crests = 0;
	for (int i = 1; i <= 8; i++)
		for (int j = i; j <= 8; j++)
			rests[++crests] = {i, j};
	memset(dp_r, 0x3f, sizeof(dp_r));
	for (int j0 = 1; j0 <= 8; j0++) for (int j1 = 1; j1 <= 8; j1++) dp_r[0][j0][j1] = (j0 != j1 ? 1 + Len_dura[j1] : 0);
	for (int i = 1; i < 512; i++) {
		for (int j0 = 1; j0 <= 8; j0++) {
			for (int j1 = 1; j1 <= 8; j1++) {
				for (int k = 1; k <= 36; k++) {
					int l = rests[k].first, r = rests[k].second, len = (1 << (9 - l)) - (1 << (8 - r));
					if (i - len >= 0) {
						for (int j2 = 1; j2 <= 8; j2++) {
							int cur = dp_r[i - len][j0][j2] + (j1 != j2 ? 1 + Len_dura[j1] : 0) + (l != j1 ? Len_dura[l] : 0) + 1 + r - l;
							if (dp_r[i][j0][j1] > cur) {
								dp_r[i][j0][j1] = cur;
								fr_r[i][j0][j1] = {k, j2};
							}
						}
					}
				}
			}
		}
	}
	memset(dp_r2, 0x3f, sizeof(dp_r2));
	for (int i = 0; i < 1024; i++) {
		for (int j0 = 1; j0 <= 8; j0++) {
			for (int j1 = 1; j1 <= 8; j1++) {
				for (int k = max(0, i - 511); k <= i && k < 512; k++) {
					int cur = dp_r[k][j0][1] + dp_r[i - k][1][j1];
					if (dp_r2[i][j0][j1] > cur) {
						dp_r2[i][j0][j1] = cur;
						fr_r2[i][j0][j1] = k;
					}
				}
			}
		}
	}
}
void print_dp_r(int i, int j0, int j1) {
	if (!i) {
		if (j0 != j1) printf("L%d", 1 << (j1 - 1));
		return;
	}
	int k = fr_r[i][j0][j1].first;
	int j2 = fr_r[i][j0][j1].second;
	int l = rests[k].first, r = rests[k].second, len = (1 << (9 - l)) - (1 << (8 - r));
	print_dp_r(i - len, j0, j2);
	if (j1 != j2) printf("L%d", 1 << (j1 - 1));
	printf("R");
	if (l != j1) printf("%d", 1 << (l - 1));
	int cnt = r - l;
	while (cnt--)
		printf(".");
}
int calc_r(int l, int j0, int j1) {
	int c1 = 0, tl = l;
	while (l >= 1024) {
		c1++;
		l -= 128;
	}
	int res = INF;
	res = min(res, dp_r2[l][j0][j1] + c1);
	while (l >= 128) {
		c1++;
		l -= 128;
		res = min(res, dp_r2[l][j0][j1] + c1);
	}
	c1 = 0;
	l = tl;
	while (l >= 512) {
		c1 += 2;
		l -= 128;
	}
	res = min(res, dp_r[l][j0][j1] + c1);
	while (l >= 128) {
		c1 += 2;
		l -= 128;
		res = min(res, dp_r[l][j0][j1] + c1);
	}
	return res;
}
void print_r(int l, int j0, int j1) {
	int c1 = 0, tl = l, a1 = 0, al = 0;
	while (l >= 1024) {
		c1++;
		l -= 128;
	}
	int res = INF;
	if (res > dp_r2[l][j0][j1] + c1) {
		res = dp_r2[l][j0][j1] + c1;
		a1 = 1;
		al = l;
	}
	while (l >= 128) {
		c1++;
		l -= 128;
		if (res > dp_r2[l][j0][j1] + c1) {
			res = dp_r2[l][j0][j1] + c1;
			a1 = 1;
			al = l;
		}
	}
	c1 = 0;
	l = tl;
	while (l >= 512) {
		c1 += 2;
		l -= 128;
	}
	if (res > dp_r[l][j0][j1] + c1) {
		res = dp_r[l][j0][j1] + c1;
		a1 = 0;
		al = l;
	}
	while (l >= 128) {
		c1 += 2;
		l -= 128;
		if (res > dp_r[l][j0][j1] + c1) {
			res = dp_r[l][j0][j1] + c1;
			a1 = 0;
			al = l;
		}
	}
	if (a1) {
		c1 = (tl - al) / 128;
		int k = fr_r2[al][j0][j1];
		print_dp_r(k, j0, 1);
		while (c1--) printf("R");
		print_dp_r(al - k, 1, j1);
	} else {
		c1 = (tl - al) / 128;
		while (c1--) printf("R1");
		print_dp_r(al, j0, j1);
	}
}
int ans_oct[N], ans_L[N];
const char van[14][5] = {"C-", "C", "C+", "D", "D+", "E", "F", "F+", "G", "G+", "A", "A+", "B", "B+"};
int main() {
	int Case = 0;
	init_r();
	while (scanf(" %s", str + 1) == 1 && str[1] != '*') {
		Case++;
		init_all(str);
		for (int i = 0; i <= n; i++)
			for (int j = 1; j <= 8; j++)
				dp_oct[i][j] = dp_L[i][j] = INF;
		dp_oct[0][4] = dp_L[0][3] = 0;
		for (int i = 1; i <= n; i++) {
			if (dat[i].nt) {
				vector<pair<int, int> > vec;
				vec.push_back({(dat[i].nt - 1) / 12 + 1, Len_note[(dat[i].nt - 1) % 12]});
				if (dat[i].nt % 12 == 1 && dat[i].nt != 1) {
					vec.push_back({(dat[i].nt - 1) / 12, 2});
				} else if (dat[i].nt % 12 == 0 && dat[i].nt != 96) {
					vec.push_back({dat[i].nt / 12 + 1, 2});
				}
				for (pair<int, int> P : vec) {
					int j = P.first, cst = P.second;
					for (int k = 1; k <= 8; k++) if (dp_oct[i - 1][k] < INF) {
						int cur = dp_oct[i - 1][k] + min(2, abs(j - k)) + cst;
						if (dp_oct[i][j] > cur) {
							dp_oct[i][j] = cur;
							fr_oct[i][j] = k;
						}
					}
				}
				for (int j = 1; j <= 8; j++) {
					for (int k = 1; k <= 8; k++) if (dp_L[i - 1][k] < INF) {
						int cur = dp_L[i - 1][k] + (j != k ? Len_dura[j] + 1 : 0) + (dat[i].x != j ? Len_dura[dat[i].x] : 0) + dat[i].c;
						if (dp_L[i][j] > cur) {
							dp_L[i][j] = cur;
							fr_L[i][j] = k;
						}
					}
				}
			} else {
				for (int j = 1; j <= 8; j++)
					dp_oct[i][j] = dp_oct[i - 1][j], fr_oct[i][j] = j;
				for (int k = 1; k <= 8; k++) if (dp_L[i - 1][k] < INF) {
					for (int j = 1; j <= 8; j++) {
						int cur = dp_L[i - 1][k] + calc_r(dat[i].x, k, j);
						if (dp_L[i][j] > cur) {
							dp_L[i][j] = cur;
							fr_L[i][j] = k;
						}
					}
				}
			}
		}
		int x1 = 1, x2 = 1;
		for (int i = 2; i <= 8; i++) {
			if (dp_oct[n][i] < dp_oct[n][x1])
				x1 = i;
			if (dp_L[n][i] < dp_L[n][x2])
				x2 = i;
		}
		printf("Case %d: ", Case);
		for (int i = n; i >= 1; i--) {
			ans_oct[i] = x1;
			ans_L[i] = x2;
			x1 = fr_oct[i][x1];
			x2 = fr_L[i][x2];
		}
		int V = 100, O = 4, L = 3;
		for (int i = 1; i <= n; i++) {
			if (dat[i].nt) {
				if (dat[i].vol != V) {
					V = dat[i].vol;
					printf("V%d", V);
				}
				if (ans_L[i] != L) {
					L = ans_L[i];
					printf("L%d", 1 << (L - 1));
				}
				if (ans_oct[i] != O) {
					if (abs(ans_oct[i] - O) > 1)
						printf("O%d", ans_oct[i]);
					else if (ans_oct[i] < O)
						printf("<");
					else
						printf(">");
					O = ans_oct[i];
				}
				printf("%s", van[dat[i].nt - (O - 1) * 12]);
				if (dat[i].x != L)
					printf("%d", 1 << (dat[i].x - 1));
				while (dat[i].c--)
					printf(".");
			} else {
				print_r(dat[i].x, ans_L[i - 1], ans_L[i]);
				L = ans_L[i];
			}
		}
		printf("\n");
	}
	return 0;
}
