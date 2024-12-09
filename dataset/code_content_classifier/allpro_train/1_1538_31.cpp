#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 300;

int n, l, r, ind, i, j;
char t[10], res[N], ansL;

int main() {
scanf("%d", &n);
printf("? ");
for (i=1;i<=n;i++) printf(" %d", i);
printf("\n");
fflush(stdout);
scanf("%s", t);
ansL = t[0];
l = n;
r = 2 * n;
while (l + 1 < r) {
	ind = (l + r) / 2;
	printf("? ");
	for (i=ind - n + 1;i<=ind;i++) printf(" %d", i);
	printf("\n");
	fflush(stdout);
	scanf("%s", t);
	if (t[0] == ansL) l = ind; else r = ind;
}
res[r] = (ansL == 'B') ? 'R' : 'B';
res[r - n] = ansL;
for (i=1;i<=2*n;i++) if (i != r && i != r - n) {
	printf("? %d", i);
	for (j=1;j<=2*n;j++) {
		if (i > r - n && i < r && (j < r - n || j > r)) printf(" %d", j);
		if ((i < r - n || i > r) && j > r - n && j < r) printf(" %d", j);
	}
	printf("\n");
	fflush(stdout);
	scanf("%s", t);
	res[i] = t[0];
}
printf("! ");
for (i=1;i<=2*n;i++) printf("%c", res[i]);
printf("\n");
fflush(stdout);
return 0;
}