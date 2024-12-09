#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int INF = 987654321;
const int MAX_N = 100001;

int N, M;
int a[MAX_N];
int LR[2][MAX_N][2];
int cont[2][MAX_N];
int d[2][MAX_N];
int sel[2][MAX_N];

bool isInside(int k, int lr, int q)
{
	return LR[lr][q][0] <= k && k <= LR[lr][q][1];
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i < N; i++) {
		scanf("%d", &a[i]);
		for (int j=0; j < 2; j++)
			scanf("%d%d", &LR[j][i][0], &LR[j][i][1]);
	}
	for (int lr = 0; lr < 2; lr++) {
		map<pair<int, int>, int> ck;
		
		for (int i=0; i < N; i++) {
			if (!isInside(a[i], !lr, i)) {
				for (auto it=ck.begin(); it != ck.end();
					 it = ck.erase(it))
					cont[lr][it->second] = i;
			}
			if (isInside(a[i], lr, i))
				ck[{a[i], i}] = i;
			for (auto it=ck.begin();
				it != ck.end() && it->first.first < LR[lr][i][0];
				it = ck.erase(it)) {
				cont[lr][it->second] = i;
			}
 
			for (auto it=ck.upper_bound(make_pair(LR[lr][i][1], N));
				it != ck.end();
				it = ck.erase(it)) {
				cont[lr][it->second] = i;
			}
		}
		for (auto it=ck.begin(); it != ck.end(); it++)
			cont[lr][it->second] = N;
		//for (int i=0; i < N; i++)
		//	printf("%d %d %d\n", i, a[i], cont[lr][i]);
	}
	map<int, int> success[2];
	int cont_success[2] = {};
	for (int lr=0; lr < 2; lr++) {
		if (isInside(a[0], lr, 0)) {
			d[lr][0] = true;
			success[lr][a[0]] = 0;
			success[!lr][0] = -1;
			cont_success[lr] = 1;
		} else {
			d[lr][0] = false;
		}
	}
	//printf("%d) %d %d\n", 0, d[0][0], d[1][0]);
	for (int i=1; i < N; i++) {
		for (int lr=0; lr < 2; lr++) {
			if (!isInside(a[i], lr, i)) {
				d[lr][i] = false;
				continue;
			}
			for (auto it = success[!lr].begin();
				 it != success[!lr].end() &&
				 it->first < LR[!lr][i][0];
				 it = success[!lr].erase(it));
			for (auto it = success[!lr].upper_bound(LR[!lr][i][1]);
				 it != success[!lr].end();
				 it = success[!lr].erase(it));

			auto it = success[!lr].lower_bound(LR[!lr][i][0]);
			for(;it != success[!lr].end() && it->first <= LR[!lr][i][1]; it++) {

		//	printf("[%d, %d]", cont[!lr][it->second], it->second);
			if (it->second == -1 || cont[!lr][it->second] >= i-1) {
				sel[lr][i] = it->second;
				d[lr][i] = true;
				break;
			}}
			

		}
		if (!d[0][i]) {success[1].clear();}
		if (!d[1][i]) {success[0].clear();}
		if (d[0][i]) {success[0][a[i]] = i;}
		if (d[1][i]) {success[1][a[i]] = i;}
		
		//printf("%d - %d) %d %d\n", i, a[i], d[0][i], d[1][i]);
	}

	if (!d[0][N-1] && !d[1][N-1]) {
		puts("No");
		return 0;
	}
	puts("Yes");
	vector<int> ans;
	for (int lr=0; lr < 2; lr++) {
		if (d[lr][N-1] == false)
			continue;
		int clr = lr;
		int ci = N-1;
		ans.push_back(clr);
		while (ci > 0) {
			int ni = sel[clr][ci];
			if (ni == -2)
				return 1;
			//printf("%d)", ni);
			ci--;
			while (ci != ni) {
				ans.push_back(clr);
				ci--;
			}
			if(ni != -1) ans.push_back(!clr);
			clr = !clr;
		}
		break;
	}

	reverse(ans.begin(), ans.end());
	for (int n : ans)
		printf("%d ", n);
//	for (int i=0; i < N; i++)
//		printf("%d ", d[1][i]);
	puts("");
	return 0;
}