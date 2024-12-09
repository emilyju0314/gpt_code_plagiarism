#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;

char l[MAXN] , r[MAXN] , ans[MAXN];
int n , cnt;

int main() {
	scanf("%d" , &n);
	scanf("%s" , l + 1);
	scanf("%s" , r + 1);
	int p = 1 , one = 0;
	while(p <= n && l[p] == r[p]) one += (r[p] == '1') , p ++;
	if(p == n + 1) {
		printf("%s" , l + 1);
		return 0;
	}
	if(!one) for (int i = p; i <= n; ++i) putchar('1');
	else {
		for (int i = 1; i <= n; ++i) ans[++cnt] = r[i];
		if(r[n] == '1') printf("%s" , ans + 1);
		else if(r[n - 1] == '1') {
			if(p < n - 1) ans[cnt] = '1';
			else if(p == n - 1) ans[cnt] = (l[n] == '0') + '0';
			printf("%s" , ans + 1);
		}
		else {
			int fl = 0;
			for (int i = p + 1; i <= n; ++i) if(l[i] != '1') {
				fl = 1;
				break;
			}
			if(fl) ans[cnt] = '1';
			printf("%s" , ans + 1);
		}
	}
	return 0;
}