#include <cstdio>
#include <algorithm>

using namespace std;

#define rep1(i,x) for(int i=1;i<=(x);++i)
#define chmax(a,b) a=max(a,b)

int a[100001];
int memo[100001];
int start[100001];

int main()
{
	int n, k;
	while (scanf("%d %d", &n, &k), n || k) {
		fill_n(a, n, 0);
		fill_n(memo, n, 0);
		fill_n(start, n, 0);

		bool f = false;

		rep1(i, k) {
			int tmp; scanf("%d", &tmp);
			if (tmp == 0) f = true;
			else a[tmp] = true;
		}

		rep1(i, n) {
			if (a[i]) {
				if (a[i - 1]) {
					start[i] = start[i - 1];
					memo[start[i]]++;
				} else {
					start[i] = i;
					memo[start[i]]++;
				}
			}
		}

		int ma = 0;

		rep1(i, n) {
			if (a[i]) {
				chmax(ma, memo[start[i]]);
			} else if (f) {
				if (i + 1 <= n) {
					chmax(ma, memo[start[i - 1]] + memo[start[i + 1]] + 1);
				} else {
					chmax(ma, memo[start[i - 1]] + 1);
				}
			}
		}

		printf("%d\n", ma);
	}
}