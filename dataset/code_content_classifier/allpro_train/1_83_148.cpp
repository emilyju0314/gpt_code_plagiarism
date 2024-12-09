#include <cstdio>
#include <vector>
using namespace std;

int main() {
	char i_mark, o_mark;
	int i_rank, n,ma['S'+1],mb[4];
	ma['S'] = 0, ma['H'] = 1, ma['C'] = 2, ma['D'] = 3;
	mb[0] = 'S', mb[1] = 'H', mb[2] = 'C', mb[3] = 'D';
	(void)scanf("%d", &n);
	vector<vector<bool> > v(4, vector<bool>(13, 0));
	for (int i = 0; i < n; i++) {
		(void)scanf("%*c%c %d", &i_mark, &i_rank);
	     v[ma[i_mark]][i_rank - 1] = 1;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (!v[i][j]) printf("%c %d\n", mb[i], j + 1);
		}
	}
	return 0;
}
